#include <iostream>
#include <fstream>
#include <nlopt.hpp>
#include "headers/getdata.h"
#include "headers/getlabels.h"
#include "headers/costfunc.h"
#include "headers/sigmoid.h"
#include "headers/sigmoidGradient.h"
#include "headers/initWeights.h"
#include "headers/backprop.h"
#include "headers/nlminFunc.h"
#include "headers/nn_data.h"
#include "headers/definitions.h"
#include "headers/predict.h"
#if __cplusplus <= 199711L
  #error This library needs at least a C++11 compliant compiler
#endif

/* Matlab code ported to C++
based on Andrew Ng's Coursera exercise
single hidden layer neural network
dataset is MNIST digits 
--Øystein Staven--2017-- */

int main()
{
	NN_DATA nn_traindata;	
	
	/* Use getdata() to import train data, train labels */
	std::cout << "Importing train data ...\n";
	std::ifstream trFeaturefile ("data/trainData.csv");
	getdata(trFeaturefile, nn_traindata.X);
	std::ifstream trLabelfile ("data/trainLabels.csv");
	getlabels(trLabelfile, nn_traindata.y);
	
	/* Add bias vector of ones to data vector */
	arma::vec onevec; onevec.ones(nn_traindata.X.n_rows);
	nn_traindata.X.insert_cols(0,onevec);
	
	/* Initialize weights semi-randomly, small values */
	arma::mat init_Theta1; arma::mat init_Theta2;
	initWeights(init_Theta1, nn_traindata.input_layer_size, nn_traindata.hidden_layer_size);
	initWeights(init_Theta2, nn_traindata.hidden_layer_size, nn_traindata.num_labels);

	/* Unroll into one parameter vector for NLopt */
	arma::vec init_Theta1_vec = vectorise(init_Theta1);
	arma::vec init_Theta2_vec = vectorise(init_Theta2);
	arma::vec nn_params_arm = join_vert(init_Theta1_vec, init_Theta2_vec);
	stdvec nn_params = arma::conv_to< stdvec >::from(nn_params_arm);
	
	/* Initialize gradient vector for use in NLopt */
	std::vector<double> nn_grad;
	nn_grad.reserve(nn_params.size());
	
	/* Optimize with NLopt */
	std::cout << "\nFinding minimum objective ...\n";
	nlopt::opt opt(nlopt::LD_LBFGS, nn_params.size());
	opt.set_maxeval(50);
	opt.set_min_objective(nlminFunc, &nn_traindata);
	double min_cost=0.0;
	nlopt::result result = opt.optimize(nn_params, min_cost);
	std::cout << "Minimum cost value:" << min_cost << "\n";
	std::cout << "NLopt return code:" << result << "\n";
	
	/* First use getdata() to import test data, test labels */
	NN_DATA nn_testdata;
	std::cout << "Importing test data ...\n";
	std::ifstream teFeaturefile ("data/testData.csv");
	getdata(teFeaturefile, nn_testdata.X);
	std::ifstream teLabelfile ("data/testLabels.csv");
	getlabels(teLabelfile, nn_testdata.y);
	
	/* Add bias vector of ones to data vector */
	onevec.ones(nn_testdata.X.n_rows);
	nn_testdata.X.insert_cols(0,onevec);
	std::cout << "\nPredicting labels ...\n";
	arma::uvec predictions = predict(nn_params, nn_testdata);
	
	/* Find accuracy */
	arma::umat zz = (predictions==nn_testdata.y);
	double accusum = arma::accu(zz);
	double accuracy = accusum/nn_testdata.y.n_rows * 100;
	std::cout << "Accuracy: " << accuracy << " %" << std::endl;
	return 0;
}