#ifndef __v2_h__
#define __v2_h__


class v2
{
public:
	float x;
	float y;
	
	v2();
	v2(float xIn, float yIn);
	void randomize();
	void normalize();
	v2 denominate(float d);
	double dot(v2 vector);
	v2 product(double f);
	v2 sum(v2 v);
	void rotation(double angle);

};

#endif