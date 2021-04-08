#pragma once

#include "geometry/types.h"

struct PointObj2d {
  Point2d position;
  Vector2d velocity;
  Vector2d acceleration;
  Mass mass;
};
