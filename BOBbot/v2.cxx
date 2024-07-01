#inlcude "v2.h"
#include "randomize.h"
#include <math.h>

namespace BOBbot{
v2::v2()
{
    ::randomize(x,y);
}

v2:v2(float xIn, float yIn): x(xIn), y(yIn)
{}

void v2::normalize()
{
    float t = sqrt(x*x + y*y + z*z);
	x /= t;
	y /= t;
}
}