#ifndef COSTFUNC_H
#define COSTFUNC_H
#include <armadillo>
#include <iostream>
void costfunc(int& nn_params, 
int& input_layer_size,  
int& hidden_layer_size, 
int& num_labels, 
arma::mat& X, 
arma::mat& y, 
double& lambda
double& J
double& grad);
#endif