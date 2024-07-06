#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include "Particle.h"
#include "v2.h"
#include "contact.h"
#include "interact_force.h"

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
    ParticleArray[i].disp_pos();
    myfile.open("position.txt", std::ios_base::app);
    myfile<<ParticleArray[i].position.x<<" "<<ParticleArray[i].position.y<<std::endl;
    myfile.close();
    // ParticleArray[i].disp_External_Force();
    ParticleArray[i].disp_External_Force();



  }

  std::cout<<"Force_Applied"<<std::endl;
  External_Force_update(ParticleArray,0.001,n);
  for (int i =0;i<n;i++){
    ParticleArray[i].disp_pos();
    myfile.open("Force.txt", std::ios_base::app);
    myfile<<ParticleArray[i].position.x<<" "<<ParticleArray[i].position.y<<"  "<<ParticleArray[i].velocity.x<<" "<<ParticleArray[i].velocity.y<<"  "<<ParticleArray[i].External_Force.x<<" "<<ParticleArray[i].External_Force.y<<std::endl;
    myfile.close();
    // ParticleArray[i].disp_External_Force();
    
    ParticleArray[i].disp_External_Force();



  }
  
  return 0;
}