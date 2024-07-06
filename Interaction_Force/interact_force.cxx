#include "Particle.h"
#include "v2.h"
#include <iostream>
#include <math.h>
#include <cmath>

void Repel_Force(Particle& ParticleA, Particle& ParticleB,v2 distance,const double h){
    double k = 1000;
    double repulsive_distance = ParticleA.radius+ParticleB.radius+h-distance.norm();
    v2 direction = distance.product(1/distance.norm());
    v2 collision_position = ParticleB.position.sum(direction.product(0.5*distance.norm()));
    ParticleA.apply_external_force(collision_position,direction.product((k*repulsive_distance)));
    ParticleB.apply_external_force(collision_position,direction.product(-(k*repulsive_distance)));

}

void External_Force_update(Particle *ParticleArray,const double h,const int Num_of_Particle){
    
    // int Num_of_Particle = sizeof(ParticleArray)/sizeof(ParticleArray[0]);
    // std::cout<<"NUM of Particle  "<<sizeof(ParticleArray)<<std::endl;
    for(int i =0;i<Num_of_Particle;i++){
        for(int j =i+1;j<Num_of_Particle;j++){
            v2 distance = ParticleArray[i].position.minus(ParticleArray[j].position);
            std::cout<<"Distance  "<<distance.norm()<<std::endl;
            if (distance.norm()<(ParticleArray[i].radius+ParticleArray[j].radius+h)){
                Repel_Force(ParticleArray[i],ParticleArray[j],distance,h);
                
                // ParticleArray[i].disp_External_Force();
                // ParticleArray[j].disp_External_Force();
            }
        }
    }
}

