#ifndef COSTFUNC_H
#define COSTFUNC_H
#include <armadillo>
#include <iostream>
#include "sigmoid.h"
#include "nn_data.h"
double costfunc(std::vector<double> nn_params, NN_DATA nn_data);
#endif