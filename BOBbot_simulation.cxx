#include <cmath>
#include <iostream>
#include <string>
#include "BOBbot.h"
#include "v2.h"

int main(int argc, char* argv[])
{
  if (argc <2){
    const int n = 10;
  }
  const int n = std::stod(argv[1]);
  BOBbot * pArray = new BOBbot[n];
  // for (int i =0;i<n;i++){
  //   pArray[i].disp_pos();
  //   pArray[i].disp_direction();

  // }
  
  
  return 0;
}