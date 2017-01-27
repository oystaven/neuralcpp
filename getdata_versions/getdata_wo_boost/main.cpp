#include <iostream>
#include <fstream>
#include "getdata.h"
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

#if __cplusplus <= 199711L
  #error This library needs at least a C++11 compliant compiler
#endif

int main()
{
	//Declare struct with data info

	struct info features;
	
	std::ifstream myfile ("data/X_train.txt");
	std::vector<float> array = getdata(myfile, features);
//debugging below, remove
		for(int i=0;i<=features.rows*features.columns-1;i++)
		{
			std::cout << array[i] << "\n";
		}
		std::cout << features.rows << "\n";
		std::cout << features.columns << "\n";
//until here

	return 0;
}