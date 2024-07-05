#pragma once
#include "v2.h"

class Particle
{

private:
    double mass = 0.151; //kg
    
    double inertia = 0.5*mass*radius*radius;
public:
    Particle();
	v2 position;
    v2 direction;
    v2 External_Force;
    v2 Internal_Force;
    double Internal_Torque = 0;
    double sum_External_Force =0;
    double External_Torque = 0;
    // float angle;
    double radius = 0.04; // m
	void disp_pos();
    void disp_direction();
    void disp_External_Force();
    void disp_External_Torque();
    void disp_sum_External_Force();
    void apply_external_force(v2 pos,v2 Force);
	// void Initialize();

};