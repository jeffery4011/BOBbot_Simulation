#include "Particle.h"
#include "v2.h"
#include "randomize.h"
// TODO 11: include cmath
#include <cmath>
#include <iostream>

Particle::Particle():position(),velocity(),direction(),External_Force(0,0),Internal_Force(0,0)
{

  direction.normalize();
}


void Particle::disp_pos(){
  std::cout<<"Position_ x = " << position.x<<"  y="<<position.y<<std::endl;
  // float p=0.2;
  // double p = 3.1415926;
  // std::cout<<"Product: "<<position.sum(p).x<<"  "<<position.sum(p).y <<std::endl;

}

void Particle::disp_vel(){
  std::cout<<"Velocity_ x = " << velocity.x<<"  y="<<velocity.y<<std::endl;
}

void Particle::disp_angular_vel(){
  std::cout<<"Angular_velocity= "<<angular_velocity<<std::endl;
}

void Particle::disp_direction(){
  std::cout<<"Direction_ x = " << direction.x<<"  y="<<direction.y<<std::endl;
  // double p = 3.1415926/2;
  // direction.rotation(p);
  // std::cout<<"New Direction_ x = " << direction.x<<"  y="<<direction.y<<std::endl;

}

void Particle::disp_External_Force(){
  std::cout<<"External_Force_ x = " << External_Force.x<<"  y="<<External_Force.y<<std::endl;

}

void Particle::disp_External_Torque(){
  std::cout<<"External_Torque = " << External_Torque<<std::endl;

}

void Particle::disp_sum_External_Force(){
  std::cout<<"SUM_External_Force = " << sum_External_Force<<std::endl;

}

void Particle::apply_external_force(v2 pos,v2 Force){
  v2 radius = position.minus(pos);
  v2 distance = pos.minus(position);
  distance.normalize();
  sum_External_Force += Force.norm();
  External_Force = External_Force.sum(distance.product(Force.dot(distance)));
  External_Torque += radius.cross(Force);

}