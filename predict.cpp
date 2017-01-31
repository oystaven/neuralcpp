#include "headers/predict.h"

arma::uvec predict(std::vector<double> nn_params, NN_DATA nn_data)
{
	
	int m=nn_data.X.n_rows;
	int K=nn_data.num_labels;
	int hidden_layer_size=nn_data.hidden_layer_size;
	int input_layer_size=nn_data.input_layer_size;
	
	/* Reshape parameters into matrices */
	arma::vec nn_params_arm = arma::conv_to< arma::vec >::from(nn_params);
	arma::mat Theta1 = arma::reshape(nn_params_arm.rows(0,hidden_layer_size*(input_layer_size+1)-1), hidden_layer_size, input_layer_size+1);
	arma::mat Theta2 = arma::reshape(nn_params_arm.rows(hidden_layer_size*(input_layer_size+1),nn_params_arm.n_rows-1), K, hidden_layer_size+1);

	/* Feedforward */
	arma::mat temp = nn_data.X * trans(Theta1);
	arma::mat h1 = sigmoid(temp);
	arma::vec onevec; onevec.ones(h1.n_rows);
	h1.insert_cols(0,onevec);
	temp = h1 * trans(Theta2);
	arma::mat h2 = sigmoid(temp);
	arma::uvec predictions = index_max(h2,1);
	return predictions;
}