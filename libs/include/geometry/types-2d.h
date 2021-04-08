#pragma once

#include <vector>

/// @brief Two Dimensional Point.
struct Point2d {
  float x;
  float y;
};

using Triangle2d = Point2d[3];
using Line2d = Point2d[3];
using Poligon2d = std::vector<Point2d>;

struct Circle2d {
  Point2d center;
  float radius;
};

using Vector2d = Point2d;

/// Vector in circular coordinates
struct VectorCirc2d {
  float modulus;
  float theta;
};
