#include "BOBbot.h"
#include "v2.h"
#include "randomize.h"
// TODO 11: include cmath
#include <cmath>


void BOBbot::Initialize(){
 v2 pos;
 pos= v2.randomize();
 x = pos[0];
 y = pos[1];
 std::cout << "BOBbot Position x: " << x << " y:" << y << std::endl;

}