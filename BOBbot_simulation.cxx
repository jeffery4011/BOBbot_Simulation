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
  
  BOBbot * BOBbotArray = new BOBbot[n];
  for (int i =0;i<n;i++){
    BOBbotArray[i].disp_pos();
    BOBbotArray[i].disp_External_Force();
    v2 Force;
    // Force();
    Force.normalize();
    v2 Force_position;
    // Force_position();
    Force_position.normalize();
    Force_position.product(BOBbotArray[i].radius);
    Force_position.sum(BOBbotArray[i].position);
    BOBbotArray[i].apply_external_force(Force_position,Force_position);
    BOBbotArray[i].disp_External_Force();
    BOBbotArray[i].disp_sum_External_Force();
    BOBbotArray[i].disp_External_Torque();

  }
  
  
  return 0;
}