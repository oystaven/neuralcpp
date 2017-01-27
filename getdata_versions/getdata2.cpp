#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <cerrno>

int main()
{
  std::string str("data/X_train.txt");
  const char* filename= str.c_str();
  
  std::ifstream in(filename, std::ios::in);// | std::ios::binary);
  if (in)
  {
    std::ostringstream contents;
    contents << in.rdbuf();
    in.close();
    std::cout << contents.str();
  }
  //throw(errno);
  //return 0;
}