#include "v2.h"
#include "randomize.h"
#include <math.h>
#include <iostream>
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

double v2::norm()
{
    return sqrt(x*x + y*y);
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

v2 v2::minus(v2 v){
    return v2(x-v.x,y-v.y);
}


void v2::rotation(double angle){
    // Rotation in radius
    float X = x;
    float Y = y;
    x = cos(angle)*X+sin(angle)*Y;
    y = -sin(angle)*X+cos(angle)*Y;
}

double v2::cross(v2 v){
    return x*v.y-v.x*y;
}

v2 v2::angular_velocity_rotate(double w){
    return v2(-y*w,x*w);
}