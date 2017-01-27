#ifndef GETDATA_H
#define GETDATA_H


#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

void getdata(std::ifstream& myfile, boost::numeric::ublas::matrix<float>& m);

#endif

