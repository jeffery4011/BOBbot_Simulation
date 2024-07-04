#include "BOBbot.h"
#include "v2.h"
#include <iostream>
#include <math.h>
#include <cmath>

void Repel_Force(BOBbot* BOBbotA, BOBbot* BOBbotB,v2 distance, double h){
    double k = 1000;
    double repulsive_distance = BOBbotA.radius+BOBbotB.radius+h-distance.norm();
    v2 direction = distance.product(1/distance.norm());
    v2 collision_position = BOBbotB.position.sum(direction.product(0.5*distance.norm()));
    BOBbotA.apply_external_force(collision_position,direction.product((k*repulsive_distance)));
    BOBbotB.apply_external_force(collision_position,direction.product(-(k*repulsive_distance)));

}

void External_Force_update(BOBbot *BOBbotArray, double h, int Num_of_BOBbot){
    
    // int Num_of_BOBbot = sizeof(BOBbotArray)/sizeof(BOBbotArray[0]);
    // std::cout<<"NUM of BOBbot  "<<sizeof(BOBbotArray)<<std::endl;
    for(int i =0;i<Num_of_BOBbot;i++){
        for(int j =i+1;j<Num_of_BOBbot;j++){
            v2 distance = BOBbotArray[i].position.minus(BOBbotArray[j].position);
            std::cout<<"Distance  "<<distance.norm()<<std::endl;
            if (distance.norm()<(BOBbotArray[i].radius+BOBbotArray[j].radius+h)){
                Repel_Force(&BOBbotArray[i],&BOBbotArray[j],distance,h);
                
                // BOBbotArray[i].disp_External_Force();
                // BOBbotArray[j].disp_External_Force();
            }
        }
    }
}

