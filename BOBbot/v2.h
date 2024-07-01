#ifndef __v2_h__
#define __v2_h__


class v2
{
public:
	float x;
	float y;
	
	v2();
	v2(float xIn, float yIn, float zIn);
	void randomize();
	void normalize();

};

#endif