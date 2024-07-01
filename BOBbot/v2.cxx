#include "v2.h"
#include "randomize.h"
#include <math.h>


v2::v2()
{
    ::randomize(x,y);
}

v2::v2(float xIn, float yIn): x(xIn), y(yIn)
{}

void v2::normalize()
{
    float t = sqrt(x*x + y*y);
	x /= t;
	y /= t;
}
v2 v2::denominate(float d){
    return v2(x/d,y/d);
}