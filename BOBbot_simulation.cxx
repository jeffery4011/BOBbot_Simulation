#include <cmath>
#include <iostream>
#include <string>
#include "BOBbot.h"
#include "v2.h"
#include "contact.h"

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
  int max_num_of_try = 1000;
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
  }std::cout<<"All Robots have been placed!"<<std::endl;

  //End of Check Overlapping

  
  
  
  
  for (int i =0;i<n;i++){
    BOBbotArray[i].disp_pos();
    // BOBbotArray[i].disp_External_Force();
    v2 Force;
    Force.normalize();
    std::cout<<"Applied Force: "<<Force.x<<" , "<<Force.y<<std::endl;
    v2 Force_position;
    Force_position.normalize();
    Force_position= Force_position.product(BOBbotArray[i].radius);
    Force_position= Force_position.sum(BOBbotArray[i].position);
    BOBbotArray[i].apply_external_force(Force_position,Force);



  }
  std::cout<< contact(BOBbotArray[0],BOBbotArray[1])<<std::endl;
  
  return 0;
}