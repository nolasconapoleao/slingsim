#pragma once

#include "geometry/types.h"

bool equals(const Point2d &p1, const Point2d &p2);
bool equals(const Vector2d &p1, const Vector2d &p2);

bool equals(const Point2d &p1, const Point2d &p2) {
  return p1.x == p2.x && p1.y == p2.y;
}

bool equals(const Vector2d &p1, const Vector2d &p2) {
  return p1.dx == p2.dx && p1.dy == p2.dy;
}
