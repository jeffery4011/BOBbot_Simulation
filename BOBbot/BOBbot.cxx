#include "BOBbot.h"
#include "v2.h"
#include "randomize.h"
// TODO 11: include cmath
#include <cmath>
#include <iostream>

BOBbot::BOBbot():position(),direction(),External_Force(0,0)
{

  direction.normalize();
}


void BOBbot::disp_pos(){
  std::cout<<"Position_ x = " << position.x<<"  y="<<position.y<<std::endl;
  // float p=0.2;
  // double p = 3.1415926;
  // std::cout<<"Product: "<<position.sum(p).x<<"  "<<position.sum(p).y <<std::endl;

}

void BOBbot::disp_direction(){
  std::cout<<"Direction_ x = " << direction.x<<"  y="<<direction.y<<std::endl;
  double p = 3.1415926/2;
  direction.rotation(p);
  std::cout<<"New Direction_ x = " << direction.x<<"  y="<<direction.y<<std::endl;

}

void BOBbot::disp_External_Force(){
  std::cout<<"External_Force_ x = " << External_Force.x<<"  y="<<External_Force.y<<std::endl;
  // float p=0.2;
  // double p = 3.1415926;
  // std::cout<<"Product: "<<position.sum(p).x<<"  "<<position.sum(p).y <<std::endl;

}