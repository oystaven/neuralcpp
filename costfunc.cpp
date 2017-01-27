#include "costfunc.h"
#include "sigmoid.h"

double costfunc(arma::mat& Theta1,
arma::mat& Theta2,
int& input_layer_size,  
int& hidden_layer_size, 
int& num_labels, 
arma::mat& X, 
arma::mat& y, 
double& lambda)
{
	double J=0;
	arma::mat J_cost; J_cost.set_size(1,1);
	int m=X.n_rows;
	int K=num_labels;
	
	arma::mat Theta1_grad; Theta1_grad.zeros(size(Theta1));
	arma::mat Theta2_grad; Theta2_grad.zeros(size(Theta2));

	arma::vec onevec; onevec.ones(m);
	X.insert_cols(0,onevec);
	for(int i=0; i<m; i++)
	{
		arma::rowvec x = X.row(i);
		arma::rowvec a1 = x;
		arma::rowvec z2 = a1*trans(Theta1);
		arma::rowvec a2 = sigmoid(z2);
		arma::vec one; one.ones(1);
		arma::rowvec z3 = join_rows(one,a2)*trans(Theta2);
		arma::rowvec a3 = sigmoid(z3);
		arma::rowvec h = a3;
		arma::rowvec Y; Y.zeros(1,K);
		int ind = arma::as_scalar(y(i,0));
		Y(0,ind-1) = 1;
		J_cost = J_cost - Y*trans(log(h))-(1-Y)*trans(log(1-h));
		//J_cost = J_cost - arma::sum(Y*trans(log(h))-(1-Y)*trans(log(1-h)));
	}
	J_cost=J_cost/m;
	J_cost = J_cost + (lambda / (2*m) * (arma::sum(arma::sum(arma::pow(Theta1,2)),1) + arma::sum(arma::sum(arma::pow(Theta2,2)),1)));

	J=arma::as_scalar(J_cost);
	return J;
}