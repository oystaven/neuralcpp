#ifndef GETLABELS_H
#define GETLABELS_H
 
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <boost/tokenizer.hpp>
#include <armadillo>
void getlabels(std::ifstream& myfile, arma::uvec& labels);

#endif

