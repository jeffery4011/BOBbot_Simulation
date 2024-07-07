
void Repulsive_Force(Particle ParticleA, Particle ParticleB,v2 distance,v2 direction,v2 collision_position);
void Damping_Shear_Force(Particle& ParticleA, Particle& ParticleB,v2 collision_position);
void External_Force_update(Particle *ParticleArray, double h, int Num_of_Particle);