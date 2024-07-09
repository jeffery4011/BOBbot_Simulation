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
Ring_particle::Ring_particle(){
    {mass = 0.0000001;radius = 0.0001;inertia = 0.5*mass*radius*radius;}
}
void Ring_particle::update_head(){
    direction = tail.minus(position);
    head = position.sum(direction);
    direction.normalize();
}


void Ring::initialize(double ring_radius){
    std::cout<<"Ring_particle_radius: "<<RingParticleArray[0].radius<<std::endl;
    n = 3.1415926*ring_radius/RingParticleArray[0].radius;
    RingParticleArray = new Ring_particle[n];
    std::cout<<"Number of particles "<<n<<std::endl;
    
    RingParticleArray[0].position.y =0;
    RingParticleArray[0].position.x =ring_radius;
    RingParticleArray[0].head.y = RingParticleArray[0].radius;
    RingParticleArray[0].head.x = ring_radius;
    RingParticleArray[0].tail.y = -1*RingParticleArray[0].radius;
    RingParticleArray[0].tail.x = ring_radius;
    for (int i =1;i++;i<n){
        std::cout<<"Setting up "<<i<<" particle"<<std::endl;
        RingParticleArray[i].position.y = cos(2*3.14159265*i/n);
        RingParticleArray[i].position.x = sin(2*3.14159265*i/n);
        std::cout<<RingParticleArray[i].position.y<<"  "<<RingParticleArray[i].position.x<<std::endl;
        RingParticleArray[i].tail.x = RingParticleArray[i-1].head.x; 
        RingParticleArray[i].tail.y = RingParticleArray[i-1].head.y;
        // RingParticleArray[i].update_head(); 

    }
    std::cout<<"Finish Initialization"<<std::endl;
}

void Ring::disp_particle(){
    for (int i =0;i<n;i++){
        RingParticleArray[i].disp_pos();
    }
}