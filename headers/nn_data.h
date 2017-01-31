#ifndef NN_DATA_H
#define NN_DATA_H
#include <armadillo>

class NN_DATA {
	public:
		int input_layer_size = 784;
		int hidden_layer_size = 28;
		int num_labels = 10;
		double lambda=0.1;
		int iterations=0;
		arma::mat X;
		arma::uvec y;
};

#endif