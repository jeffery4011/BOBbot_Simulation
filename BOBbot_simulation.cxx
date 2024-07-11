#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include "Particle.h"
#include "v2.h"
#include "contact.h"
#include "interact_force.h"
#include "solver.h"
#include "Ring.h"
#include <algorithm>
#include <list>
#include <memory>
#include <vector>

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
  std::vector<std::shared_ptr<Particle>> vector_particle_array; 
  
  
  
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


  // vector_particle_array.push_back(std::make_shared<Particle>());
  // while (place_index <n){
  //   std::cout<<"Placing "<<place_index<<"th Particle"<<std::endl;
  //   vector_particle_array.push_back(std::make_shared<Particle>());
  //   num_of_try = 0;
  //   bool place_success = 0;
  //   while (! place_success){
  //     std::cout<<"Try "<<num_of_try<<"th time"<<std::endl;
  //     int contact_index = 0;
  //       while (contact_index<place_index){
        
  //         if (contact(*(vector_particle_array[contact_index]),*(vector_particle_array[place_index]))){
  //           num_of_try++;
  //           vector_particle_array[0] = std::make_shared<Particle>();
  //           break;
  //         }
  //         contact_index++;
  //       }
        
  //       if (contact_index == place_index){
  //         place_success =1;
  //       }
  //       if (num_of_try == max_num_of_try){
  //         std::cout<<"Over Crowded! Decrease the number of robot or vary the distribution parameter!"<<std::endl;
  //         return 0;
  //       }
  //   }
  // }
  // for(int i=0;i<n;i++){
  //   vector_particle_array.push_back(std::make_shared<Particle>());
  //   std::cout<<vector_particle_array[i]->position.x<<std::endl;
  // }
  // vector_particle_array[0] = std::make_shared<Particle>();
  // std::cout<<vector_particle_array[0]->position.x<<std::endl;

  //End of Check Overlapping

  std::ofstream myfile;
  Ring ring;
  ring.initialize(0.2);
  
  
  
  // std::cout<<"Robot_radius: "<<ParticleArray[0].radius<<std::endl;
  // std::cout<<"Ring_particle_num:_"<<ring.n<<std::endl;
  // myfile.open("Ring_num.txt", std::ios_base::app);
  //   // myfile<<std::setprecision(4)<<std::fixed;
  // myfile<<ring.n<<std::endl;
  // myfile.close();
  

  // Particle * TotalParticleArray = new Particle[n+ring.n];
  // std::vector<std::shared_ptr<Particle>> SumParticleArray;
  // std::copy(ParticleArray,ParticleArray+n,TotalParticleArray);
  // std::copy(ring.RingParticleArray,ring.RingParticleArray+ring.n,TotalParticleArray+n);
  // for (int i =0;i<ring.n;i++){
  //   ring.RingParticleArray[i].position.x = ring.RingParticleArray[i].position.x +1;
  // }

  // for (int i =0;i<n+ring.n;i++){
  //   myfile.open("Ring.txt", std::ios_base::app);
  //   // myfile<<std::setprecision(4)<<std::fixed;
  //   myfile<<TotalParticleArray[i].position.x<<" "<<TotalParticleArray[i].position.y<<std::endl;
  //   myfile.close();
  // }


  // savedata(ParticleArray);

  // for(int i =1;i<n+ring.n;i=i+300){
  //   std::cout<<"Particle_mass: "<<TotalParticleArray[i].mass<<std::endl;
  // }
  
  // for (int i =0;i<n;i++){
    
    
  //   if (i%2==0){
  //     // ParticleArray[i].position.x=-0.2;
  //     // ParticleArray[i].position.y=0;
  //     // ParticleArray[i].velocity.x=0.1;
  //     // ParticleArray[i].velocity.y=0;
  //     // ParticleArray[i].direction.x=1;
  //     // ParticleArray[i].direction.y=0;
  //     ParticleArray[i].angular_velocity=10;
  //   }
  //   else{
  //     // ParticleArray[i].position.x=0.2;
  //     // ParticleArray[i].position.y=0;
  //     // ParticleArray[i].velocity.x=-0.1;
  //     // ParticleArray[i].velocity.y=0;
  //     // ParticleArray[i].direction.x=1;
  //     // ParticleArray[i].direction.y=0;
  //     ParticleArray[i].angular_velocity=10;
  //   }
  // }

  // std::cout<<"Force_Applied"<<std::endl;
  // for(int t=0;t<7500;t++){
    // for (int i =0;i<ring.n;i++){
    // myfile.open("Ring.txt", std::ios_base::app);
    // // myfile<<std::setprecision(4)<<std::fixed;
    // myfile<<ring.RingParticleArray[i].position.x<<" "<<ring.RingParticleArray[i].position.y<<std::endl;
    // myfile.close();
    // }
    
    // for (int i =0;i<n;i++){
    // myfile.open("BOBbot_"+std::to_string(i)+".txt", std::ios_base::app);
    // // myfile<<std::setprecision(4)<<std::fixed;
    // myfile<<ParticleArray[i].position.x<<" "<<ParticleArray[i].position.y<<" "<<ParticleArray[i].direction.x<<" "<<ParticleArray[i].direction.y<<std::endl;
    // myfile.close();
    // }
    //   for (int i =0;i<n;i++){
    // myfile.open("Y.txt", std::ios_base::app);
    // myfile<<std::setprecision(4)<<std::fixed;
    // myfile<<ParticleArray[i].position.y<<std::endl;
    // myfile.close();
    // }
    //   for (int i =0;i<n;i++){
    // myfile.open("Dx.txt", std::ios_base::app);
    // myfile<<std::setprecision(4)<<std::fixed;
    // myfile<<ParticleArray[i].direction.x<<std::endl;
    // myfile.close();
    // }
    //   for (int i =0;i<n;i++){
    // myfile.open("Dy.txt", std::ios_base::app);
    // myfile<<std::setprecision(4)<<std::fixed;
    // myfile<<ParticleArray[i].direction.y<<std::endl;
    // myfile.close();
  // ring.RingParticleArray[0]  
  for (int t=0;t<7500;t++){
    Reinitialize_Force(ring.RingParticleArray,ring.n);
    ring.update_internal_force();
    brute_particle_update_solver(ring.RingParticleArray,0.001,0,ring.n);
    std::cout<<ring.RingParticleArray[0].x<<" "<<ring.RingParticleArray[0].y<<std::endl;
  }
  // brute_particle_update_solver(ring.RingParticleArray,0.001,0,ring.n);
  // ring.disp_particle();
  // }
  
  
  
  return 0;
}