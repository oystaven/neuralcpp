#include "getdata.h"

void  getdata(std::ifstream& myfile, boost::numeric::ublas::matrix<float>& m)
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
			//columns = std::count(line.begin(), line.end(), ' ');
			
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
	//move numbers to the boost matrix
   m.resize(rows,columns);
   for (unsigned i = 0; i < m.size1 (); ++ i)
       for (unsigned j = 0; j < m.size2 (); ++ j)
           m (i, j) = array[i*columns+j];
   
	//TODO remove below
	//std::cout << m << std::endl;

	
	//return array; 
}