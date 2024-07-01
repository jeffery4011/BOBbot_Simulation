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


BOBbot::disp_pos(){
  cout<<"Position_ x = " << v2.x<<"  y="<<v2.y<<endl;
  
}