#include "headers/backprop.h"
std::vector<double> backprop(std::vector<double> nn_params, NN_DATA nn_data)
{
	typedef std::vector<double> stdvec;	
	int m=nn_data.X.n_rows;
	int K=nn_data.num_labels;
	int lambda=nn_data.lambda;
	int hidden_layer_size=nn_data.hidden_layer_size;
	int input_layer_size=nn_data.input_layer_size;
	
	/* Reshape parameters into matrices */
	arma::vec nn_params_arm = arma::conv_to< arma::vec >::from(nn_params);
	arma::mat Theta1 = arma::reshape(nn_params_arm.rows(0,hidden_layer_size*(input_layer_size+1)-1), hidden_layer_size, input_layer_size+1);
	arma::mat Theta2 = arma::reshape(nn_params_arm.rows(hidden_layer_size*(input_layer_size+1),nn_params_arm.n_rows-1), K, hidden_layer_size+1);
	
	arma::mat deltacum1; deltacum1.zeros(size(Theta1));
	arma::mat deltacum2; deltacum2.zeros(size(Theta2));
	
	for(int i=0; i<m; i++)
	{
		arma::rowvec x = nn_data.X.row(i);
		arma::rowvec a1 = x;
		arma::rowvec z2 = a1*trans(Theta1);
		arma::vec one; one.ones(1);
		arma::rowvec a2 = join_rows(one,sigmoid(z2));
		arma::rowvec z3 = a2*trans(Theta2);
		arma::rowvec a3 = sigmoid(z3);
		arma::rowvec h = a3;
		arma::rowvec Y; Y.zeros(1,K);
		int ind = arma::as_scalar(nn_data.y(i,0));
		Y(0,ind) = 1;
		arma::rowvec delta3 = a3-Y;
		arma::rowvec delta2 = delta3*Theta2%sigmoidGradient(join_rows(one,z2));
		deltacum1 = deltacum1 + trans(delta2.cols(1,delta2.n_cols-1))*a1;
		deltacum2 = deltacum2 + trans(delta3)*a2;
	}
	arma::mat Theta1_grad = deltacum1/m;
	arma::mat Theta2_grad = deltacum2/m;
	//Regularization
	Theta1_grad.cols(1,Theta1_grad.n_cols-1) = Theta1_grad.cols(1,Theta1_grad.n_cols-1) + (lambda / m) * Theta1.cols(1,Theta1.n_cols-1);
	Theta2_grad.cols(1,Theta2_grad.n_cols-1) = Theta2_grad.cols(1,Theta2_grad.n_cols-1) + (lambda / m) * Theta2.cols(1,Theta2.n_cols-1);
	
	//Unroll data into one vector for NLopt
	arma::vec Theta1_grad_vec = vectorise(Theta1_grad);
	arma::vec Theta2_grad_vec = vectorise(Theta2_grad);
	arma::vec nn_grad_arm = join_vert(Theta1_grad_vec, Theta2_grad_vec);
	stdvec nn_grad = arma::conv_to< stdvec >::from(nn_grad_arm); 
	
	return nn_grad;
}