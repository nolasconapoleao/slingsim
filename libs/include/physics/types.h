#pragma once

#include "geometry/types.h"

/// @brief Object with point center of mass.
struct PointObj2d {
  /// @brief Position
  Point2d p;
  /// @brief Velocity
  Vector2d v;
  /// @brief Acceleration
  Vector2d a;

  /// @brief Object mass
  Mass m;
  /// @brief Object radius approximation
  float r;
};
