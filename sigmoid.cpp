#include "headers/sigmoid.h"

arma::mat sigmoid(arma::mat& X)
{
	arma::mat Y = 1/(1+exp(-X));
	return Y;
}