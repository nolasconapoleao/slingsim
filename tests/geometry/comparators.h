#pragma once

#include "geometry/types.h"

bool equals(const Point2d &p1, const Point2d &p2);
bool equals(const Vector2d &p1, const Vector2d &p2);

bool equals(const Cartesian2d &ca1, const Cartesian2d &ca2);
bool equals(const Circular2d &ci1, const Circular2d &ci2);
bool equals(float v1, float v2);

bool equals(const Point2d &p1, const Point2d &p2) {
  return equals(p1.x, p2.x) && equals(p1.y, p2.y);
}

bool equals(const Vector2d &v1, const Vector2d &v2) {
  return equals(v1.dx, v2.dx) && equals(v1.dy, v2.dy);
}

bool equals(const Cartesian2d &ca1, const Cartesian2d &ca2) {
  return equals(ca1.x, ca2.x) && equals(ca1.y, ca2.y);
}

bool equals(const Circular2d &ci1, const Circular2d &ci2) {
  return equals(ci1.m, ci2.m) && equals(ci1.a, ci2.a);
}

bool equals(float v1, float v2) {
  return abs(v1 - v2) < cTolerance;
}
