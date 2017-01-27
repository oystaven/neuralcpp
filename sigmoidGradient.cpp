#include "sigmoidGradient.h"
arma::mat sigmoidGradient(arma::mat X)
{
	arma::mat Y; Y.zeros(size(X));
	Y = sigmoid(X) % (1-sigmoid(X));
	return Y;
}