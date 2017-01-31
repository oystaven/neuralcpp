#include "headers/findErrors.h"

void findErrors(NN_ERRORS nn_errors, const arma::uvec predictions, const arma::uvec groundtruth, const unsigned num_labels)
{
	for(unsigned i=0; i<predictions.n_rows; i++){
		if(predictions(i)==groundtruth(i) && predictions(i)==1){
			nn_errors.TPincr();
		}
		else if(predictions(i)==groundtruth(i) && predictions(i)==0){
			nn_errors.TNincr();
		}
		else if(predictions(i)!=groundtruth(i) && predictions(i)==1){
			nn_errors.FPincr();
		}
		else if(predictions(i)!=groundtruth(i) && predictions(i)==0){
			nn_errors.FNincr();
		}
	}
}