#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include "BOBbot.h"
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
  BOBbot * BOBbotArray = new BOBbot[n];
  
  
  
  //Check Overlapping
  int max_num_of_try = 10000;
  int place_index = 1;
  int num_of_try = 0;
  while (place_index <n){
    std::cout<<"Placing "<<place_index<<"th BOBbot"<<std::endl;
    num_of_try = 0;
    bool place_success = 0;
    while (! place_success){
      std::cout<<"Try "<<num_of_try<<"th time"<<std::endl;
      int contact_index = 0;
        while (contact_index<place_index){
        
          if (contact(BOBbotArray[contact_index],BOBbotArray[place_index])){
            num_of_try++;
            BOBbotArray[place_index] = BOBbot();
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
  
  // savedata(BOBbotArray);
  
  for (int i =0;i<n;i++){
    BOBbotArray[i].disp_pos();
    myfile.open("position.txt", std::ios_base::app);
    myfile<<BOBbotArray[i].position.x<<" "<<BOBbotArray[i].position.y<<std::endl;
    myfile.close();
    // BOBbotArray[i].disp_External_Force();
    BOBbotArray[i].disp_External_Force();



  }

  std::cout<<"Force_Applied"<<std::endl;
  External_Force_update(BOBbotArray,20,n);
  for (int i =0;i<n;i++){
    BOBbotArray[i].disp_pos();
    myfile.open("Force.txt", std::ios_base::app);
    myfile<<BOBbotArray[i].position.x<<" "<<BOBbotArray[i].position.y<<std::endl;
    myfile.close();
    // BOBbotArray[i].disp_External_Force();
    
    BOBbotArray[i].disp_External_Force();



  }
  
  return 0;
}