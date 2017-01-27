#ifndef GETDATA_H
#define GETDATA_H


#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cstdlib>

std::vector<float> getdata(std::ifstream& myfile, struct info& features);
struct info{
	size_t rows;
	size_t columns;
	info()
	{
		rows=0;
		columns=0;
	}
};
#endif

