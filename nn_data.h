#ifndef NN_DATA_H
#define NN_DATA_H
#include <armadillo>

class NN_DATA {
	public:
		int input_layer_size = 400;
		int hidden_layer_size = 25;
		int num_labels = 10;
		double lambda=0.1;
		arma::mat X;
		arma::mat y;
};

#endif