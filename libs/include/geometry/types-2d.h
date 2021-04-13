#pragma once

#include <vector>

/// @brief Two Dimensional Point.
struct Point2d {
  /// @brief Coordinate in x axis.
  float x = 0;
  /// @brief Coordinate in y axis.
  float y = 0;

  /// @brief Distance of point to origin.
  float m = 0;
  /// @brief Angle between x axis and line segment to origin.
  float a = 0;
};

using Triangle2d = Point2d[3];
using Line2d = Point2d[2];
using Poligon2d = std::vector<Point2d>;

struct Circle2d {
  Point2d c;
  float r;
};

struct Vector2d {
  float dx = 0;
  float dy = 0;

  float m = 0;
  float a = 0;
};

constexpr Vector2d cBasisH{1, 0};
constexpr Vector2d cBasisV{0, 1};
