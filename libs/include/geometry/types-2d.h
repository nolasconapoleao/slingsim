#pragma once

#include <vector>

#include "constants.h"

/// @brief Cartesian coordinates.
struct Cartesian2d {
  /// @brief Coordinate in x axis.
  float x = 0;
  /// @brief Coordinate in y axis.
  float y = 0;
};

/// @brief Circular coordinates.
struct Circular2d {
  /// @brief Distance of point to origin.
  float m = 0;
  /// @brief Angle between x axis and line segment to origin.
  float a = 0;
};

/// @brief Two Dimensional Point.
struct Point2d {
  /// @brief Coordinate in x axis.
  float x = 0;
  /// @brief Coordinate in y axis.
  float y = 0;
};

/// @brief Two Dimensional Vector.
struct Vector2d {
  /// @brief Coordinate in x axis.
  float dx = 0;
  /// @brief Coordinate in y axis.
  float dy = 0;
};

/// @brief Two Dimensional Triangle.
using Triangle2d = Point2d[3];

/// @brief Two Dimensional Line.
using Line2d = Point2d[2];

/// @brief Two Dimensional Poligon.
using Poligon2d = std::vector<Point2d>;

/// @brief Circle in two dimensions.
struct Circle2d {
  Point2d c;
  float r;
};

/// @brief Horizontal basis.
constexpr Vector2d cBasisH{1, 0};
/// @brief Vertical basis.
constexpr Vector2d cBasisV{0, 1};

constexpr Vector2d cNull{0, 0};

constexpr Point2d cOrig{0, 0};
