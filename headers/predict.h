#ifndef PREDICT_H
#define PREDICT_H
#include <armadillo>
#include <iostream>
#include "sigmoid.h"
#include "nn_data.h"
#include "definitions.h"

arma::uvec predict(std::vector<double> nn_params, NN_DATA nn_data);
#endif