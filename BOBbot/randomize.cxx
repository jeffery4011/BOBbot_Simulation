#include <random>

namespace {
  std::random_device randDevice;
  std::minstd_rand engine(randDevice());
  std::normal_distribution<float> normalDist(0, RAND_MAX);
}

void randomize(float& x, float& y)
{
  x = normalDist(engine);
  y = normalDist(engine);
}