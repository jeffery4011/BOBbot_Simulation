#include "Particle.h"
#include "v2.h"
#include <iostream>
#include <math.h>
#include <cmath>

// Collision Model applys the discrete element method(DEM), which is a method for simulating granular material(Mishra 2003)
//https://www.sciencedirect.com/science/article/pii/S0020768310002477

void Repulsive_Force(Particle& ParticleA, Particle& ParticleB,v2 distance,v2 direction,v2 collision_position){
    double k = 1000;
    double repulsive_distance = ParticleA.radius+ParticleB.radius-distance.norm();
    
    ParticleA.apply_external_force(collision_position,direction.product((k*repulsive_distance)));
    ParticleB.apply_external_force(collision_position,direction.product(-(k*repulsive_distance)));

}

void Damping_Force(Particle& ParticleA, Particle& ParticleB,v2 collision_position){
    double eta = 0.1;
    v2 ParticleA_Velocity = ParticleA.velocity.sum(ParticleA.radius*ParticleA.angular_velocity);
    v2 ParticleB_Velocity = ParticleB.velocity.sum(ParticleB.radius*ParticleB.angular_velocity);
    v2 relative_velocity = ParticleA_Velocity.minus(ParticleB_Velocity);
    ParticleA.apply_external_force(collision_position,relative_velocity.product(-1*eta));
    ParticleB.apply_external_force(collision_position,relative_velocity.product(eta));

}

void External_Force_update(Particle *ParticleArray,const double h,const int Num_of_Particle){
    
    // int Num_of_Particle = sizeof(ParticleArray)/sizeof(ParticleArray[0]);
    // std::cout<<"NUM of Particle  "<<sizeof(ParticleArray)<<std::endl;
    for(int i =0;i<Num_of_Particle;i++){
        for(int j =i+1;j<Num_of_Particle;j++){
            v2 distance = ParticleArray[i].position.minus(ParticleArray[j].position);
            std::cout<<"Distance  "<<distance.norm()<<std::endl;
            if (distance.norm()<(ParticleArray[i].radius+ParticleArray[j].radius+h)){
                v2 direction = distance.product(1/distance.norm());
                v2 collision_position = ParticleB.position.sum(direction.product(0.5*distance.norm()));
                Repulsive_Force(ParticleArray[i],ParticleArray[j],distance,direction,collision_position);
                
                // ParticleArray[i].disp_External_Force();
                // ParticleArray[j].disp_External_Force();
            }
        }
    }
}

