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
    {mass = 0.000005;connect=0.0001; radius = 0.1*connect;inertia = 50000;} //NO ROTATION//0.5*mass*radius*radius;}
}
void Ring_particle::update_head(){
    direction = tail.minus(position);
    head = position.sum(direction);
    direction.normalize();
}

void Ring_particle::apply_internal_force(v2 Force){
    Internal_Force = Internal_Force.sum(Force);

}


void Ring::initialize(double ring_radius){
    // std::cout<<"Ring_particle_radius: "<<RingParticleArray[0].radius<<std::endl;
    n = 3.1415926*ring_radius/RingParticleArray[0].connect;
    RingParticleArray = new Ring_particle[n];
    // std::cout<<"Number of particles "<<n<<std::endl;
    
    RingParticleArray[0].position.y =ring_radius;
    RingParticleArray[0].position.x =0;
    RingParticleArray[0].head.x = RingParticleArray[0].connect;
    RingParticleArray[0].head.y = ring_radius;
    RingParticleArray[0].tail.x = -1*RingParticleArray[0].connect;
    RingParticleArray[0].tail.y = ring_radius;
    RingParticleArray[0].External_Force.x=0;
    RingParticleArray[0].External_Force.y=0;
    for (int i =1;i<n;i++){
        // std::cout<<"Setting up "<<i<<" particle"<<std::endl;
        RingParticleArray[i].position.y = ring_radius*cos(2*3.14159265*i/n);
        RingParticleArray[i].position.x = ring_radius*sin(2*3.14159265*i/n);
        // std::cout<<RingParticleArray[i].position.y<<"  "<<RingParticleArray[i].position.x<<std::endl;
        RingParticleArray[i].tail.x = RingParticleArray[i-1].head.x; 
        RingParticleArray[i].tail.y = RingParticleArray[i-1].head.y;
        RingParticleArray[i].External_Force.x=0;
        RingParticleArray[i].External_Force.y=0;
        RingParticleArray[i].update_head(); 
        // RingParticleArray[i].disp_External_Force();

    }
    // RingParticleArray[n-1].tail.x 
    std::cout<<"Finish Initialization"<<std::endl;
}

void Ring::disp_particle(){
    for (int i =0;i<n;i++){
        RingParticleArray[i].disp_pos();
        RingParticleArray[i].disp_External_Force();
    }
}



void Ring::update_internal_force(){
    double kr = 2;//0.2;//0.05 too loose//0.1 too loose for active

    
    for (int i=1;i<n;i++){
        v2 dis=RingParticleArray[i].position.minus(RingParticleArray[i-1].position);
        double distance=dis.norm();
        dis.normalize();
        // if (distance > 2*RingParticleArray[i].connect){
            v2 F = dis.product(kr*(-2*RingParticleArray[i].connect + distance));
            // if (i==1){
            //     std::cout<<"Acceleration: "<<F.norm()/RingParticleArray[i].mass<<std::endl;
            // }
            
            // if (i==1){
            //     dis = RingParticleArray[i].position.minus(RingParticleArray[i-1].position);
            //     std::cout<<"Distance: "<<dis.x<<" "<<dis.y<<std::endl;
            //     std::cout<<"Force: "<<F.x<<" "<<F.y<<std::endl;
            // }
            // RingParticleArray[i-1].disp_External_Force();
            // std::cout<<distance<<std::endl;
            // RingParticleArray[i-1].apply_external_force(RingParticleArray[i-1].position,F);
            RingParticleArray[i-1].External_Force = RingParticleArray[i-1].External_Force.sum(F);
            // RingParticleArray[i-1].disp_External_Force();
            RingParticleArray[i].External_Force = RingParticleArray[i].External_Force.sum(F.product(-1));
            // RingParticleArray[i].apply_external_force(RingParticleArray[i].position,F.product(-1));
        // }

    }
    v2 dis=RingParticleArray[0].position.minus(RingParticleArray[n-1].position);
    double distance=dis.norm();
    dis.normalize();
    // if (distance > 2*RingParticleArray[0].connect){
        v2 F = dis.product(kr*(-2*RingParticleArray[0].connect + distance));
        // RingParticleArray[n-1].apply_external_force(RingParticleArray[n-1].position,F);
        // RingParticleArray[0].apply_external_force(RingParticleArray[n-1].position,F.product(-1));
        RingParticleArray[n-1].External_Force = RingParticleArray[n-1].External_Force.sum(F);
        RingParticleArray[0].External_Force = RingParticleArray[0].External_Force.sum(F.product(-1));
    // }
    // std::cout<<"Spring_Force"<<std::endl;
    // std::cout<<"Particle0:"<<std::endl;
    // RingParticleArray[0].disp_pos();
    // RingParticleArray[0].disp_External_Force();
    // std::cout<<"Particle1:"<<std::endl;
    // RingParticleArray[1].disp_pos();
    // // RingParticleArray[1].disp_External_Force();
    // std::cout<<"Particle_end:"<<std::endl;
    // RingParticleArray[n-1].disp_pos();
    //RingParticleArray[ring.n-1].disp_External_Force();
}