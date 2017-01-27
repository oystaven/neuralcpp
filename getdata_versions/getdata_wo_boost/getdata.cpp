#include "getdata.h"

std::vector<float>  getdata(std::ifstream& myfile, struct info& features)
{
	std::vector<float> array;
	int rows=0;
	int columns=0;
	std::string line;

	if (myfile.is_open())
	{
		while( getline (myfile,line))
		{
			//count columns/features
			columns = std::count(line.begin(), line.end(), ' ');
			//store features, separate by delimiter
	      std::istringstream buf(line);
	      std::istream_iterator<float> beg(buf), end;
	      std::vector<float> tokens(beg, end);
			//move tokens to array
	      for(auto& s: tokens)
				array.push_back(s);
			rows++;
		}
		
		myfile.close();
	}
	else std::cout << "Unable to open file\n";
	
	columns=columns+1;
	
	features.rows=rows;
	features.columns=columns;
			return array; 
}