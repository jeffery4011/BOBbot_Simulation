#pragma once
#include "v2.h"

class BOBbot
{
public:
    BOBbot();
	v2 position;
    v2 direction;
    v2 External_Force;
    float External_Torque = 0;
    // float angle;

	void disp_pos();
    void disp_direction();
    void disp_External_Force();
	// void Initialize();

};