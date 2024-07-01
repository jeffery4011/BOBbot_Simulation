#include "v2.h"
#include "randomize.h"
#include <math.h>
#include <cmath>


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

double v2::dot(v2 vector){
    double s = 0;
    s +=  x*vector.x;
    s +=  y*vector.y;
    return s;
}

v2 v2::product(double f){
    
    return v2(f*x,f*y);
}

v2 v2::sum(v2 v){
    return v2(x+v.x,y+v.y);
}

void v2::rotation(double angle){
    // Rotation in radius
    float x = v2.x;
    float y = v2.y;
    v2.x = cos(angle)*x+sin(angle)*y;
    v2.y = -sin(angle)*x+cos(angle)*y;
}