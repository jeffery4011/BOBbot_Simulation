#pragma once
#include "v2.h"
#include "Particle.h"

class Ring :{
    public:
    int n = 1000;
    Particle * RingParticleArray = Particle[n];

    void Disp_particle_pos();
}