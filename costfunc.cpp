#include "costfunc.h"


double costfunc(std::vector<double> nn_params, NN_DATA nn_data)
{
	double J=0;
	arma::mat J_cost; J_cost.set_size(1,1);
	int m=nn_data.X.n_rows;
	int K=nn_data.num_labels;
	int lambda=nn_data.lambda;
	int hidden_layer_size=nn_data.hidden_layer_size;
	int input_layer_size=nn_data.input_layer_size;
	
	/* Reshape parameters into matrices */
	arma::vec nn_params_arm = arma::conv_to< arma::vec >::from(nn_params);
	arma::mat Theta1 = arma::reshape(nn_params_arm.rows(0,hidden_layer_size*(input_layer_size+1)-1), hidden_layer_size, input_layer_size+1);
	arma::mat Theta2 = arma::reshape(nn_params_arm.rows(hidden_layer_size*(input_layer_size+1),nn_params_arm.n_rows-1), K, hidden_layer_size+1);

	//Feedforward cost
	for(int i=0; i<m; i++)
	{
		arma::rowvec x = nn_data.X.row(i);
		arma::rowvec a1 = x;
		arma::rowvec z2 = a1*trans(Theta1);
		arma::rowvec a2 = sigmoid(z2);
		arma::vec one; one.ones(1);
		arma::rowvec z3 = join_rows(one,a2)*trans(Theta2);
		arma::rowvec a3 = sigmoid(z3);
		arma::rowvec h = a3;
		arma::rowvec Y; Y.zeros(1,K);
		int ind = arma::as_scalar(nn_data.y(i,0));
	   Y(0,ind) = 1;
		J_cost = J_cost - Y*trans(log(h))-(1-Y)*trans(log(1-h));
	}
	J_cost=J_cost/m;
	J_cost = J_cost + (lambda / (2*m) * (arma::sum(arma::sum(arma::pow(Theta1,2)),1) + arma::sum(arma::sum(arma::pow(Theta2,2)),1)));
	J=arma::as_scalar(J_cost);

	return J;
}