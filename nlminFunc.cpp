#include "nlminFunc.h"

double nlminFunc(const std::vector<double> &nn_params, std::vector<double> &nn_grad, void* nn_data)
{
	double J =0.0;
	NN_DATA *nn_dataPtr = static_cast<NN_DATA*>(nn_data);
	
	J = costfunc(nn_params, *nn_dataPtr);
	nn_grad = backprop(nn_params, *nn_dataPtr);
	std::cout << "Cost: " << J << std::endl;
	return J;
}
