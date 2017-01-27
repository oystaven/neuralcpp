#include <iostream>
#include <fstream>
#include <nlopt.h>
#include "getdata.h"
#include "costfunc.h"

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
	
	
	return 0;
}