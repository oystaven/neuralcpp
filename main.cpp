#include <iostream>
#include <fstream>
#include <nlopt.hpp>
#include "getdata.h"
#include "costfunc.h"
#include "sigmoid.h"
#include "sigmoidGradient.h"
#include "initWeights.h"
#include "backprop.h"
#include "nlminFunc.h"
#include "nn_data.h"

#if __cplusplus <= 199711L
  #error This library needs at least a C++11 compliant compiler
#endif

/* Matlab code ported to C++
single hidden layer neural network
dataset is MNIST digits*/

int main()
{
	typedef std::vector<double> stdvec;
	NN_DATA nn_data;	
	
	// //Use getdata() to import data, labels
	std::cout << "Importing data ...\n";
	std::ifstream featurefile ("data/data_X.csv");
	getdata(featurefile,nn_data.X);

	std::ifstream labelfile ("data/data_y.csv");
	getdata(labelfile,nn_data.y);
	
	// //Add bias vector of ones to data vector
	arma::vec onevec; onevec.ones(nn_data.X.n_rows);
	nn_data.X.insert_cols(0,onevec);

	//Initialize weights randomly, small values
	arma::mat init_Theta1; arma::mat init_Theta2;
	initWeights(init_Theta1, nn_data.input_layer_size, nn_data.hidden_layer_size);
	initWeights(init_Theta2, nn_data.hidden_layer_size, nn_data.num_labels);

	/* Unroll into one parameter vector for NLopt */
	arma::vec init_Theta1_vec = vectorise(init_Theta1);
	arma::vec init_Theta2_vec = vectorise(init_Theta2);
	arma::vec nn_params_arm = join_vert(init_Theta1_vec, init_Theta2_vec);
	stdvec nn_params = arma::conv_to< stdvec >::from(nn_params_arm);
	/* Initialize gradient vector for use in NLopt */
	 std::vector<double> nn_grad;
	/* Optimize with NLopt */
	std::cout << "\nFinding minimum objective ...\n";

	nlopt::opt opt(nlopt::LD_LBFGS, nn_params.size());
	opt.set_maxeval(50);
	opt.set_min_objective(nlminFunc, &nn_data);
	double min_cost;
	nlopt::result result = opt.optimize(nn_params, min_cost);
	std::cout << "Minimum cost value:" << min_cost << "\n";
	std::cout << "NLopt return code:" << result << "\n";
	return 0;
}