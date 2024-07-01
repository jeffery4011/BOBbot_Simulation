#include "BOBbot.h"
#include "v2.h"
#include "randomize.h"
// TODO 11: include cmath
#include <cmath>
#include <iostream>


void BOBbot::Initialize(){
 v2 *pos;
 pos::randomize();
 float x = pos.x;
 float y = pos.y;
 std::cout << "BOBbot Position x: " << x << " y:" << y << std::endl;

}