#include "Particle.h"
#include "v2.h"
#include <iostream>
#include <math.h>
#include <cmath>

// Collision Model applys the discrete element method(DEM), which is a method for simulating granular material(Mishra 2003)
//https://www.sciencedirect.com/science/article/pii/S0020768310002477

void Repulsive_Force(Particle& ParticleA, Particle& ParticleB,v2 distance,v2 direction,v2 collision_position){
    double k = 5000;
    double repulsive_distance = ParticleA.radius+ParticleB.radius-distance.norm();
    ParticleA.apply_external_force(collision_position,direction.product((k*repulsive_distance)));
    ParticleB.apply_external_force(collision_position,direction.product(-(k*repulsive_distance)));

}

void Damping_Shear_Force(Particle& ParticleA, Particle& ParticleB,v2 collision_position){
    double eta = 0.1;
    v2 rad_A = collision_position.minus(ParticleA.position);
    v2 rad_B = collision_position.minus(ParticleB.position);
    v2 particleA_tang_velocity = v2(-1*ParticleA.angular_velocity*rad_A.y,ParticleA.angular_velocity*rad_A.x);
    v2 particleB_tang_velocity = v2(-1*ParticleB.angular_velocity*rad_B.y,ParticleB.angular_velocity*rad_B.x);
    v2 ParticleA_point_Velocity = ParticleA.velocity.sum(particleA_tang_velocity);
    v2 ParticleB_point_Velocity = ParticleB.velocity.sum(particleB_tang_velocity);
    v2 relative_velocity = ParticleA_point_Velocity.minus(ParticleB_point_Velocity);
    ParticleA.apply_external_force(collision_position,relative_velocity.product(-1*eta));
    ParticleB.apply_external_force(collision_position,relative_velocity.product(eta));


    double kt = 0.2;
    v2 relative_tang_velocity = particleA_tang_velocity.minus(particleB_tang_velocity);
    // std::cout<<"Relative_tanget_velocity: "<< relative_tang_velocity.x<<"   "<<relative_tang_velocity.y<<std::endl;
    ParticleA.apply_external_force(collision_position,relative_tang_velocity.product(1*kt));
    ParticleB.apply_external_force(collision_position,relative_tang_velocity.product(-1*kt));
    ParticleA.disp_External_Torque();
    ParticleB.disp_External_Torque();

}

void External_Force_update(Particle *ParticleArray,const double h,const int Num_of_Particle){
    
    // int Num_of_Particle = sizeof(ParticleArray)/sizeof(ParticleArray[0]);
    // std::cout<<"NUM of Particle  "<<sizeof(ParticleArray)<<std::endl;
    for(int i =0;i<Num_of_Particle;i++){
        ParticleArray[i].External_Force.x=0;
        ParticleArray[i].External_Force.y=0;
        ParticleArray[i].Internal_Force.x=0;
        ParticleArray[i].Internal_Force.y=0;
        ParticleArray[i].External_Torque = 0;
        ParticleArray[i].Internal_Torque = 0;
    }


    for(int i =0;i<Num_of_Particle;i++){
        for(int j =i+1;j<Num_of_Particle;j++){
            v2 distance = ParticleArray[i].position.minus(ParticleArray[j].position);
            // std::cout<<"Distance  "<<distance.norm()<<std::endl;
            if (distance.norm()<(ParticleArray[i].radius+ParticleArray[j].radius+h)){
                v2 direction = distance.product(1/distance.norm());
                v2 collision_position = ParticleArray[j].position.sum(direction.product(0.5*distance.norm()));
                Repulsive_Force(ParticleArray[i],ParticleArray[j],distance,direction,collision_position);
                Damping_Shear_Force(ParticleArray[i],ParticleArray[j],collision_position);
                
                // ParticleArray[i].disp_External_Force();
                // ParticleArray[j].disp_External_Force();
            }
        }
    }
}

