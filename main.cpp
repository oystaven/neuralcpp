#include <iostream>
#include <fstream>
#include <nlopt.h>
#include "getdata.h"

#if __cplusplus <= 199711L
  #error This library needs at least a C++11 compliant compiler
#endif

int main()
{
	std::ifstream myfile ("data/X_train.txt");
   arma::mat data;
	getdata(myfile,data);
	data.print();
	return 0;
}