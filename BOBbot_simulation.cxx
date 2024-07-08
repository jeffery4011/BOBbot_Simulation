#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include "Particle.h"
#include "v2.h"
#include "contact.h"
#include "interact_force.h"
#include "solver.h"
#include <iomanip>
#include <GLFW/glfw3.h>

int main(int argc, char* argv[])
{


  GLFWwindow* window;
  if (!glfwInit()){
    return -1;
  }
  window = glfwCreateWindow(640,480,"Window!",NULL,NULL);
  glfwMakeContextCurrent(window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
    std::cout<<"Couldn't load opengl"<<std::endl;
    glfwTerminate();
    return -1;
  }
  glClearColor(0.25f,0.5f,0.75f,1.0f);
  while(!GLFWwindowShouldClose(window)){
    glfwPollEvents();
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
  }
  glfwTerminate();
  return 0;


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
      ParticleArray[i].position.x=-0.2;
      ParticleArray[i].position.y=0;
      ParticleArray[i].velocity.x=0.1;
      ParticleArray[i].velocity.y=0;
      ParticleArray[i].direction.x=1;
      ParticleArray[i].direction.y=0;
      ParticleArray[i].angular_velocity=10;
    }
    else{
      ParticleArray[i].position.x=0.2;
      ParticleArray[i].position.y=0;
      ParticleArray[i].velocity.x=-0.1;
      ParticleArray[i].velocity.y=0;
      ParticleArray[i].direction.x=1;
      ParticleArray[i].direction.y=0;
      ParticleArray[i].angular_velocity=10;
    }
  }

  std::cout<<"Force_Applied"<<std::endl;
  for(int t=0;t<7500;t++){
    
    for (int i =0;i<n;i++){
    myfile.open("X.txt", std::ios_base::app);
    myfile<<std::setprecision(4)<<std::fixed;
    myfile<<ParticleArray[i].position.x<<std::endl;
    myfile.close();
    }
      for (int i =0;i<n;i++){
    myfile.open("Y.txt", std::ios_base::app);
    myfile<<std::setprecision(4)<<std::fixed;
    myfile<<ParticleArray[i].position.y<<std::endl;
    myfile.close();
    }
      for (int i =0;i<n;i++){
    myfile.open("Dx.txt", std::ios_base::app);
    myfile<<std::setprecision(4)<<std::fixed;
    myfile<<ParticleArray[i].direction.x<<std::endl;
    myfile.close();
    }
      for (int i =0;i<n;i++){
    myfile.open("Dy.txt", std::ios_base::app);
    myfile<<std::setprecision(4)<<std::fixed;
    myfile<<ParticleArray[i].direction.y<<std::endl;
    myfile.close();
    }

  brute_particle_update_solver(ParticleArray,0.001,0.002,n);
  }
  
  
  
  return 0;
}