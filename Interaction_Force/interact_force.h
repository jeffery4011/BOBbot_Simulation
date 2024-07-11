
void Repulsive_Force(Particle ParticleA, Particle ParticleB,v2 distance,v2 direction,v2 collision_position,double h);
void Damping_Shear_Force(Particle& ParticleA, Particle& ParticleB,v2 collision_position);
void Reinitialize_Force(Particle *ParticleArray, const int Num_of_Particle);
void External_Force_update(Particle *ParticleArray, double h, int Num_of_Particle);