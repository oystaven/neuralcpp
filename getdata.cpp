#include "getdata.h"

void getdata(std::ifstream& myfile, arma::mat& data)
{
	//get data and read into flat string vector 
	std::vector<std::string> vec;
	std::string line;
	size_t columns=0;
	size_t rows=0;
		
	if (myfile.is_open())
	{
		while( getline (myfile,line))
		{
			using namespace boost;
		   tokenizer<escaped_list_separator<char> > tok(line, escaped_list_separator<char>('\n', ',', '\"'));
			columns = std::distance(tok.begin(), tok.end());
		   for(tokenizer<escaped_list_separator<char> >::iterator beg=tok.begin(); beg!=tok.end();++beg)
			{
		       vec.push_back(*beg);
		   }
			rows++;
		}
		myfile.close();
	}
	else std::cout << "Unable to open file\n";	
	
	/* Move float data from string vector to the armadillo matrix */
	data.set_size(rows,columns);

	   for (unsigned i = 0; i < rows; i++){
	       for (unsigned j = 0; j < columns; j++){
	           data(i, j) = std::stof(vec[i*columns+j]);
			  }
		  }
}