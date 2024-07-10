#pragma once
#include "v2.h"
#include "Particle.h"

class Ring_particle: public Particle{
    public:
    // v2 head;
    // v2 tail;
    Ring_particle();
    void update_head();
};

class Ring {
    public:
    int n = 1000;
    Ring_particle * RingParticleArray = new Ring_particle[n];

    void initialize(double ring_radius);
    void disp_particle();
    void update_internal_force();

};