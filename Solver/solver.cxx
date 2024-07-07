#include "Particle.h"
#include "v2.h"
#include <iostream>
#include <math.h>
#include <cmath>
#include "interact_force.h"

void brute_particle_update_solver(Particle *ParticleArray,const double dt,const double h,const int Num_of_Particle){
    External_Force_update(ParticleArray,h,Num_of_Particle);
    for(int Particle_index=0;Particle_index<Num_of_Particle;Particle_index++){
        ParticleArray[Particle_index].position= ParticleArray[Particle_index].position.sum((ParticleArray[Particle_index].velocity.product(dt)).sum(ParticleArray[Particle_index].External_Force.product(0.5*dt*dt/ParticleArray[Particle_index].mass)));
        ParticleArray[Particle_index].angular_velocity=ParticleArray[Particle_index].angular_velocity+ParticleArray[Particle_index].External_Torque*dt/ParticleArray[Particle_index].inertia;
        std::cout<<"Inertia: "<< ParticleArray[Particle_index].inertia<<std::endl;
        ParticleArray[Particle_index].direction = ParticleArray[Particle_index].direction.sum(ParticleArray[Particle_index].direction.angular_velocity_rotate(dt*ParticleArray[Particle_index].angular_velocity));
        // ParticleArray[Particle_index].disp_direction();
        ParticleArray[Particle_index].direction.normalize();
        ParticleArray[Particle_index].velocity = ParticleArray[Particle_index].velocity.sum(ParticleArray[Particle_index].External_Force.product( dt/ParticleArray[Particle_index].mass));
    }
}