#pragma once
#include "v2.h"
#include "Particle.h"

class Ring_particle: public Particle{
    public:
    // v2 head;
    // v2 tail;
    // double string_radius = 0.1;
    
    Ring_particle();
    void update_head();
    void apply_internal_force(v2 Force);
};

class Ring {
    public:
    int n = 1000;
    double damping_coefficient = 0.1;
    Ring_particle * RingParticleArray = new Ring_particle[n];

    void initialize(double ring_radius);
    void disp_particle();
    // void apply_internal_force(v2 Force);
    void update_internal_force();

};