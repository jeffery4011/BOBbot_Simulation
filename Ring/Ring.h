#pragma once
#include "v2.h"
#include "Particle.h"

class Ring_particle: public Particle{
    public:
    Ring_particle(){mass = 0.0000001;radius = 0.0001;intertia = 0.5*mass*radius*radius;}
};

class Ring {
    public:
    int n = 1000;
    Particle * RingParticleArray = new Ring_particle[n];

    void initialize(double ring_radius);
    void disp_particle();

};