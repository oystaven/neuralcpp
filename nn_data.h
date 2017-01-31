#ifndef NN_DATA_H
#define NN_DATA_H
#include <armadillo>
#include "definitions.h"
class NN_DATA {
	public:
		int input_layer_size = 784;
		int hidden_layer_size = 28;
		int num_labels = 10;
		double lambda=0.1;
		arma::mat X=arma::zeros<arma::mat>(1,1);
		arma::mat y=arma::zeros<arma::mat>(1,1);
};

#endif