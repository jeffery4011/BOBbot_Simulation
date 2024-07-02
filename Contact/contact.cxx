#include "BOBbot.h"
#include "v2.h"

#include <math.h>
#include <cmath>

bool contact(BOBbot b1, BOBbot b2){
    return ((b1.position.minus(b2.position)).norm()<(b1.radius+b2.radius));
}