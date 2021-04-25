#include "random/random.h"

namespace rng {

float angle() {
  const auto randAngle = (rand() % 360);
  return (randAngle - 180) / 180.0f * cPi;
}

float decimal() {
  return (float)((rand() % 201)) / 200;
}

Point2d position() {
  return Point2d{(float)((rand() % 50)) / 50, (float)((rand() % 50)) / 50};
}

Colour colour() {
  return Colour{decimal(), decimal(), decimal()};
}

} // namespace rng
