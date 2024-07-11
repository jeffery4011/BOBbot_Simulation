#include "Particle.h"
#include "v2.h"

#include <math.h>
#include <cmath>
#include <memory>

bool contact(std::shared_ptr<Particle>& b1, std::shared_ptr<Particle>& b2){
    return ((b1->position.minus(b2->position)).norm()<(b1->radius+b2->radius));
}