#include "headers/getlabels.h"

void getlabels(std::ifstream& myfile, arma::uvec& labels)
{
	//get data and read into flat string vector 
	std::vector<std::string> vec;
	std::string line;
	unsigned columns=0;
	unsigned rows=0;
		
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
	
	/* Move integer data from string vector to the armadillo vector */
	labels.set_size(rows);

	   for (unsigned i = 0; i < rows; i++){
  	           labels(i) = std::stoi(vec[i]);
  			  }
}