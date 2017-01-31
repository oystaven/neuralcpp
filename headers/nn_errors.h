#ifndef NN_ERRORS_H
#define NN_ERRORS_H

class NN_ERRORS {
	public:
		int TP=0;
		int FP=0;
		int TN=0;
		int FN=0;
		
		void TPincr(){ TP++; }
		void FPincr(){ FP++; }
		void TNincr(){ TN++; }
		void FNincr(){ FN++; }
};

#endif