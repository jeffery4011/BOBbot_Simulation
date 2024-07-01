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
    return 1;
  }

  // convert input to double
  // TODO 4: Replace atof(argv[1]) with std::stod(argv[1])
  const double inputValue = std::stod(argv[1]);
  // const int n = (int)inputValue;
  // if (argc <2){
  //   const double n = 10;
  // }
  // // const int n = 10;
  // double n = std::stoi(argv[1]);
  // int index_max = (int) n;
  // BOBbot * pArray = new BOBbot[index_max];
  // for (int i =0;i<index_max;i++){
  //   pArray[i].disp_pos();
  //   pArray[i].disp_direction();

  // }
  
  
  return 0;
}