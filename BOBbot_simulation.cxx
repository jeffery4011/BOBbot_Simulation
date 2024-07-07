#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include "Particle.h"
#include "v2.h"
#include "contact.h"
#include "interact_force.h"
#include "solver.h"

int main(int argc, char* argv[])
{
  int n = 0;
    if (argc < 2) {
    n = 10;
  }
  else{
    const int inputValue = std::stoi(argv[1]);
    n = inputValue;
  }
  Particle * ParticleArray = new Particle[n];
  
  
  
  //Check Overlapping
  int max_num_of_try = 10000;
  int place_index = 1;
  int num_of_try = 0;
  while (place_index <n){
    std::cout<<"Placing "<<place_index<<"th Particle"<<std::endl;
    num_of_try = 0;
    bool place_success = 0;
    while (! place_success){
      std::cout<<"Try "<<num_of_try<<"th time"<<std::endl;
      int contact_index = 0;
        while (contact_index<place_index){
        
          if (contact(ParticleArray[contact_index],ParticleArray[place_index])){
            num_of_try++;
            ParticleArray[place_index] = Particle();
            break;
          }
          contact_index++;
        }
        
        if (contact_index == place_index){
          place_success =1;
        }
        if (num_of_try == max_num_of_try){
          std::cout<<"Over Crowded! Decrease the number of robot or vary the distribution parameter!"<<std::endl;
          return 0;
        }
    }
    place_index++;
  }std::cout<<"All Robots have been placed!"<<std::endl;

  //End of Check Overlapping

  std::ofstream myfile;
  
  // savedata(ParticleArray);
  
  for (int i =0;i<n;i++){
    
    
    if (i%2==0){
      ParticleArray[i].position.x=-0.4;
      ParticleArray[i].position.y=0;
      ParticleArray[i].velocity.x=0.03;
      ParticleArray[i].velocity.y=0;
      ParticleArray[i].direction.x=1;
      ParticleArray[i].direction.y=0;
      ParticleArray[i].angular_velocity=0.04;
    }
    else{
      ParticleArray[i].position.x=0.4;
      ParticleArray[i].position.y=0;
      ParticleArray[i].velocity.x=-0.03;
      ParticleArray[i].velocity.y=0;
      ParticleArray[i].direction.x=1;
      ParticleArray[i].direction.y=0;
      ParticleArray[i].angular_velocity=0.04;
    }
    // ParticleArray[i].disp_direction();
  //   ParticleArray[i].disp_pos();
  //   myfile.open("position.txt", std::ios_base::app);
  //   myfile<<ParticleArray[i].position.x<<" "<<ParticleArray[i].position.y<<std::endl;
  //   myfile.close();
  //   // ParticleArray[i].disp_External_Force();
  //   ParticleArray[i].disp_External_Force();



  }

  std::cout<<"Force_Applied"<<std::endl;
  for(int t=0;t<10000;t++){
    
    for (int i =0;i<n;i++){
    // ParticleArray[i].disp_pos();
    myfile.open("Force.txt", std::ios_base::app);
    myfile<<ParticleArray[i].position.x<<" "<<ParticleArray[i].position.y<<"  "<<ParticleArray[i].direction.x<<" "<<ParticleArray[i].direction.y<<std::endl;
    myfile.close();
    // 
    // ParticleArray[i].disp_External_Force();
    
    // ParticleArray[i].disp_External_Force();



  }
  brute_particle_update_solver(ParticleArray,0.001,0.001,n);
  }
  
  
  
  return 0;
}