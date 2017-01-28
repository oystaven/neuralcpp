#include <iostream>
#include <fstream>
#include <nlopt.h>
#include "getdata.h"
#include "costfunc.h"
#include "sigmoid.h"
#include "sigmoidGradient.h"
#include "initWeights.h"
#if __cplusplus <= 199711L
  #error This library needs at least a C++11 compliant compiler
#endif
/* Attempt to port MATLAB exercise to C++
dataset is MNIST digits*/

int main()
{

	int input_layer_size = 400;
	int hidden_layer_size = 25;
	int num_labels = 10;
	
	//Use getdata() to import data, labels, and pre-trained weights
	std::cout << "Importing data ...\n";
	std::ifstream featurefile ("data/data_X.csv");
   arma::mat X;
	getdata(featurefile,X); 
	
	std::ifstream labelfile ("data/data_y.csv");
	arma::mat y;
	getdata(labelfile,y); 
	
	std::ifstream Theta1file ("data/Theta1.csv");
	arma::mat Theta1;
	getdata(Theta1file,Theta1); 
	
	std::ifstream Theta2file ("data/Theta2.csv");
	arma::mat Theta2;
	getdata(Theta2file,Theta2); 
	
	//Compute cost
	std::cout << "\nFeedforward Using Neural Network ...\n";
	double lambda=0;
	double J=0;
	// arma::vec Theta1_vec = vectorise(Theta1);
	// arma::vec Theta2_vec = vectorise(Theta2);
	// arma::vec nn_params = join_vert(Theta1_vec,Theta2_vec);
	// nn_params.print();
	J=costfunc(Theta1, Theta2, input_layer_size, hidden_layer_size, num_labels, X, y, lambda);
	std::cout << J << "\n";
	
	//Initialize weights randomly between 0 and 0.1
	arma::mat init_Theta1; init_Theta1.zeros(input_layer_size,hidden_layer_size);
	arma::mat init_Theta2; init_Theta2.zeros(hidden_layer_size,num_labels);
	initWeights(init_Theta1);
	initWeights(init_Theta2);
	
	
	return 0;
}