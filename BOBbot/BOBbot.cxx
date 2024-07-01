#include "BOBbot.h"
#include "v2.h"
#include "randomize.h"
// TODO 11: include cmath
#include <cmath>
#include <iostream>

BOBbot::BOBbot(): position(),direction()
{
  // position();
  // angle=0;
}


void BOBbot::disp_pos(){
  std::cout<<"Position_ x = " << position.x<<"  y="<<position.y<<std::endl;

}