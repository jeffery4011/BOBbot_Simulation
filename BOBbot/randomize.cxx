#include <random>

namespace {
  std::random_device randDevice;
  std::minstd_rand engine(randDevice());
  std::uniform_real_distribution<float> normalDist(-0.8, 0.8);
}

void randomize(float& x, float& y)
{
  x = normalDist(engine);
  y = normalDist(engine);
}