#include "Particle.h"
#include "v2.h"
#include <iostream>
#include <math.h>
#include <cmath>
#include "interact_force.h"
#include "Ring.h"

// void Ring::Disp_particle_pos(){
//     for(int i=0;i<n;i++){
//         RingParticleArray[i].disp_pos();
//     }
// }
void Ring::initialize(double ring_radius){
    n = 2*3.1415926*ring_radius/2/RingParticleArray[0].radius;
    RingParticleArray = new Ring_particle[n];
}

void Ring::disp_particle(){
    for (int i =0;i<n;i++){
        RingParticleArray[i].disp_pos();
    }
}