#include "BOBbot.h"
#include "v2.h"
#include "randomize.h"
// TODO 11: include cmath
#include <cmath>
#include <iostream>

BOBbot::BOBbot():position(),direction()
{
  position.denominate(50);
  direction.normalize();
}


void BOBbot::disp_pos(){
  std::cout<<"Position_ x = " << position.x<<"  y="<<position.y<<std::endl;

}

void BOBbot::disp_direction(){
  std::cout<<"Direction_ x = " << direction.x<<"  y="<<direction.y<<std::endl;

}