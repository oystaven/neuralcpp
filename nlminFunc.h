#ifndef NLMINFUNC_H
#define NLMINFUNC_H
#include <armadillo>
#include <iostream>
#include "sigmoidGradient.h"
#include "costfunc.h"
#include "backprop.h"
#include "nn_data.h"
double nlminFunc(const std::vector<double> &nn_params, std::vector<double> &nn_grad, void* nn_specs);

#endif