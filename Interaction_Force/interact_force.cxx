#include "BOBbot.h"
#include "v2.h"
#include <iostream>
#include <math.h>
#include <cmath>

void External_Force_update(BOBbot *BOBbotArray, double h, int Num_of_BOBbot){
    double k = 1000;
    // int Num_of_BOBbot = sizeof(BOBbotArray)/sizeof(BOBbotArray[0]);
    // std::cout<<"NUM of BOBbot  "<<sizeof(BOBbotArray)<<std::endl;
    for(int i =0;i<Num_of_BOBbot;i++){
        for(int j =i+1;j<Num_of_BOBbot;j++){
            v2 distance = BOBbotArray[i].position.minus(BOBbotArray[j].position);
            std::cout<<"Distance  "<<distance.norm()<<std::endl;
            if (distance.norm()<(BOBbotArray[i].radius+BOBbotArray[j].radius+h)){
                double repulsive_distance = BOBbotArray[i].radius+BOBbotArray[j].radius+h-distance.norm();
                v2 direction = distance.product(1/distance.norm());
                v2 collision_position = direction.product(0.5*distance.norm());
                BOBbotArray[i].apply_external_force(collision_position,direction.product(-(k*repulsive_distance)));
                BOBbotArray[j].apply_external_force(collision_position,direction.product(-(k*repulsive_distance)));
                BOBbotArray[i].disp_External_Force();
                BOBbotArray[j].disp_External_Force();
            }
        }
    }
}