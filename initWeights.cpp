#include "initWeights.h"

void initWeights(arma::mat& weights)
{
unsigned rows=weights.n_rows;
unsigned columns=weights.n_cols;
std::random_device rd; 
std::mt19937 rng(rd());
std::uniform_real_distribution<double> uni(0,0.1);

for (unsigned i = 0; i < rows; i++){
    for (unsigned j = 0; j < columns; j++){
		 auto random_num = uni(rng);
        weights(i, j) = random_num;
	  }
  }
}