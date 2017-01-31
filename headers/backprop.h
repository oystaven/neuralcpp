#ifndef BACKPROP_H
#define BACKPROP_H
#include <armadillo>
#include <iostream>
#include "sigmoidGradient.h"
#include "nn_data.h"
std::vector<double> backprop(std::vector<double> nn_params, NN_DATA nn_data);
#endif