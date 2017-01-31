#include "headers/initWeights.h"

void initWeights(arma::mat& weights, const int L_in, const int L_out)
{
weights.zeros(L_out, 1+L_in);
unsigned rows=weights.n_rows;
unsigned columns=weights.n_cols;
double e_init = sqrt(6) / sqrt(L_out+L_in); 
std::random_device rd; 
std::mt19937 rng(rd());
std::uniform_real_distribution<double> uni(0,1);

for (unsigned i = 0; i < rows; i++){
    for (unsigned j = 0; j < columns; j++){
		 auto random_num = uni(rng) * 2 * e_init - e_init;
        weights(i, j) = random_num;
	  }
  }
}
