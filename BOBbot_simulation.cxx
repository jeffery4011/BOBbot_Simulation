#include <cmath>
#include <iostream>
#include <string>
#include "BOBbot.h"
#include "v2.h"

int main(int argc, char* argv[])
{
  int n = 0;
    if (argc < 2) {
    // TODO 12: Create a print statement using Tutorial_VERSION_MAJOR
    //          and Tutorial_VERSION_MINOR
    // std::cout << argv[0] << " Version " << Tutorial_VERSION_MAJOR << "."
    //           << Tutorial_VERSION_MINOR << std::endl;
    // std::cout << "Usage: " << argv[0] << " number" << std::endl;
    n = 10;
  }
  else{
    const int inputValue = std::stoi(argv[1]);
    n = inputValue;

  }

  // convert input to double
  // TODO 4: Replace atof(argv[1]) with std::stod(argv[1])
  
  BOBbot * pArray = new BOBbot[n];
  for (int i =0;i<n;i++){
    pArray[i].disp_pos();
    pArray[i].disp_direction();

  }
  
  
  return 0;
}