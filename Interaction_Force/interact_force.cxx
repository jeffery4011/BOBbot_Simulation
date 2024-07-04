#include "BOBbot.h"
#include "v2.h"

#include <math.h>
#include <cmath>

void External_Force_update(BOBbot *BOBbotArray, double h){
    double k = 1000;
    for(int i =0;i<std::size(BOBbotArray);i++){
        for(int j =i+1;j<std::size(BOBbotArray);j++){
            v2 distance = BOBbotArray[i].position.minus(BOBbotArray[j].position);
            if (distance.norm()<(BOBbotArray[i].radius+BOBbotArray[j].radius+h)){
                double repulsive_distance = BOBbotArray[i].radius+BOBbotArray[j].radius+h-distance.norm();
                v2 direction = distance.normalize();
                v2 collision_position = direction.product(0.5*distance.norm());
                BOBbotArray[i].apply_external_force(collision_position,direction.product(-(k*repulsive_distance)));
                BOBbotArray[j].apply_external_force(collision_position,direction.product(-(k*repulsive_distance)));
                
            }
        }
    }
}