#include "Particle.h"
#include "v2.h"
#include <iostream>
#include <math.h>
#include <cmath>

// Collision Model applys the discrete element method(DEM), which is a method for simulating granular material(Mishra 2003)
//https://www.sciencedirect.com/science/article/pii/S0020768310002477

void Repulsive_Force(Particle& ParticleA, Particle& ParticleB,v2 distance,v2 direction,v2 collision_position,double h){
    // double k = 0.001;
    double k = 0.5;
    double repulsive_distance = ParticleA.radius+ParticleB.radius-distance.norm()+h;
    ParticleA.apply_external_force(collision_position,direction.product((k*repulsive_distance)));
    std::cout<<"PA Repulsive Distance: " << repulsive_distance<<std::endl;
    std::cout<<"PA Repulsive acceleration: "<< direction.product((k*repulsive_distance/ParticleA.mass)).x<<"  "<<direction.product((k*repulsive_distance/ParticleA.mass)).y<<std::endl;
    ParticleB.apply_external_force(collision_position,direction.product(-(k*repulsive_distance)));
    // ParticleA.disp_External_Force();
    // ParticleB.disp_External_Force();

}

void Damping_Shear_Force(Particle& ParticleA, Particle& ParticleB,v2 collision_position){
    v2 rad_A = collision_position.minus(ParticleA.position);
    v2 rad_B = collision_position.minus(ParticleB.position);
    v2 particleA_tang_velocity = v2(-1*ParticleA.angular_velocity*rad_A.y,ParticleA.angular_velocity*rad_A.x);
    v2 particleB_tang_velocity = v2(-1*ParticleB.angular_velocity*rad_B.y,ParticleB.angular_velocity*rad_B.x);

   
    // ParticleA.disp_External_Torque();
    // ParticleB.disp_External_Torque();
    
    
    // double eta = 0.7; //work for BOBBOt
    double eta = 0.0000003;


    v2 ParticleA_point_Velocity = ParticleA.velocity.sum(particleA_tang_velocity);
    v2 ParticleB_point_Velocity = ParticleB.velocity.sum(particleB_tang_velocity);
    v2 relative_velocity = ParticleA_point_Velocity.minus(ParticleB_point_Velocity);
    std::cout<<"PA relative velocity "<< relative_velocity.x<<"  "<<relative_velocity.y<<std::endl;
    ParticleA.apply_external_force(collision_position,relative_velocity.product(-1*eta));
    ParticleB.apply_external_force(collision_position,relative_velocity.product(1*eta));
    std::cout<<"PA relative velocity Force acceleration: "<< relative_velocity.product(-1*eta).x/ParticleA.mass<<"  "<<relative_velocity.product(-1*eta).y/ParticleA.mass<<std::endl;
    // ParticleA.disp_External_Force();
    // ParticleB.disp_External_Force();
    
     double kt = 0.2;
    v2 relative_tang_velocity = particleA_tang_velocity.minus(particleB_tang_velocity);
    //std::cout<<"Relative_tanget_velocity: "<< relative_tang_velocity.x<<"   "<<relative_tang_velocity.y<<std::endl;
    ParticleA.apply_external_force(collision_position,relative_tang_velocity.product(1*kt));
    ParticleB.apply_external_force(collision_position,relative_tang_velocity.product(-1*kt));

    //Friction
    relative_tang_velocity.normalize();
    v2 relative_velocity_radius = relative_velocity.minus(relative_tang_velocity);
    relative_velocity_radius.normalize();
    // std::cout<<"Relative_tanget_velocity: "<< ParticleA.External_Force.x<<"   "<<ParticleA.Exteranl_Force.y<<std::endl;
    
    double Force_norm = abs(relative_velocity_radius.dot(ParticleA.External_Force.sum(ParticleA.Internal_Force)));
    // std::cout<<"Dammping Force_norm:  "<<Force_norm<<std::endl;
    ParticleA.apply_external_force(collision_position,relative_tang_velocity.product(ParticleA.friction_coefficient*Force_norm));
    ParticleA.apply_external_force(collision_position,relative_tang_velocity.product(-1*ParticleA.friction_coefficient*Force_norm));
    
    

}
void Reinitialize_Force(Particle *ParticleArray, const int Num_of_Particle){
    for(int i =0;i<Num_of_Particle;i++){
        ParticleArray[i].External_Force.x=0;
        ParticleArray[i].External_Force.y=0;
        ParticleArray[i].Internal_Force.x=0;
        ParticleArray[i].Internal_Force.y=0;
        ParticleArray[i].External_Torque = 0;
        ParticleArray[i].Internal_Torque = 0;
    }
}

void External_Force_update(Particle *ParticleArray,const double h,const int Num_of_Particle){
    
    // int Num_of_Particle = sizeof(ParticleArray)/sizeof(ParticleArray[0]);
    // std::cout<<"NUM of Particle  "<<sizeof(ParticleArray)<<std::endl;
    // for(int i =0;i<Num_of_Particle;i++){
    //     ParticleArray[i].External_Force.x=0;
    //     ParticleArray[i].External_Force.y=0;
    //     ParticleArray[i].Internal_Force.x=0;
    //     ParticleArray[i].Internal_Force.y=0;
    //     ParticleArray[i].External_Torque = 0;
    //     ParticleArray[i].Internal_Torque = 0;
    // }


    for(int i =0;i<Num_of_Particle;i++){
        for(int j =i+1;j<Num_of_Particle;j++){
            v2 distance = ParticleArray[i].position.minus(ParticleArray[j].position);
            // std::cout<<"Distance  "<<distance.norm()<<std::endl;
            if (distance.norm()<(ParticleArray[i].radius+ParticleArray[j].radius+h)){
                std::cout<<"Collide between: "<<i<<"  "<<j<<std::endl;
                v2 direction = distance.product(1/distance.norm());
                v2 collision_position = ParticleArray[j].position.sum(direction.product(0.5*distance.norm()));
                Damping_Shear_Force(ParticleArray[i],ParticleArray[j],collision_position);
                Repulsive_Force(ParticleArray[i],ParticleArray[j],distance,direction,collision_position,h);
                // ParticleArray[i].disp_External_Torque();
                // ParticleArray[i].disp_vel();
                // ParticleArray[i].disp_angular_vel();

                
                // ParticleArray[i].disp_External_Force();
                // ParticleArray[j].disp_External_Force();
            }
        }
    }
}

