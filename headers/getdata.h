#ifndef GETDATA_H
#define GETDATA_H
 
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <boost/tokenizer.hpp>
#include <armadillo>
void getdata(std::ifstream& myfile, arma::mat& data);

#endif

