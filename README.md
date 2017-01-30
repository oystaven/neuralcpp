## neuralcpp
Neural networks in C++. Based on Andrew Ng's MATLAB exercise 4 in his Coursera course in machine learning.
Trains a neural network to recognize MNIST handwritten digits. Pixel vector per example is 28x28=784. Hidden layer size can be set in nn_data class header.

Boost library is used for data tokenizer:

http://www.boost.org

Armadillo linear algebra library is used for matrix operations:

Conrad Sanderson and Ryan Curtin. 
Armadillo: a template-based C++ library for linear algebra. http://arma.sourceforge.net/armadillo_joss_2016.pdf
Journal of Open Source Software, Vol. 1, pp. 26, 2016.

NLopt is used for function optimization:
Steven G. Johnson, The NLopt nonlinear-optimization package, http://ab-initio.mit.edu/nlopt

MNIST dataset can be downloaded at: http://yann.lecun.com/exdb/mnist/

CSV format files were created using MATLAB code from: http://ufldl.stanford.edu/wiki/index.php/Using_the_MNIST_Dataset

Unpack data.tar.gz to get data readily in .csv format.

Dependencies can be installed on linux via

sudo apt-get install libopenblas-dev liblapack-dev libarmadillo-dev libnlopt-dev libboost-dev

Compile with  

g++ -std=c++11 main.cpp getdata.cpp costfunc.cpp sigmoid.cpp sigmoidGradient.cpp initWeights.cpp backprop.cpp nlminFunc.cpp -o main -O2 -larmadillo -lnlopt -lm -Wall
