#ifndef COSTFUNC_H
#define COSTFUNC_H
#include <armadillo>
#include <iostream>
double costfunc(arma::mat& Theta1,
arma::mat& Theta2, 
int& input_layer_size,  
int& hidden_layer_size, 
int& num_labels, 
arma::mat& X, 
arma::mat& y, 
double& lambda);
#endif