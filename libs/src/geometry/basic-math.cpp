#include "geometry/basic-math.h"

#include <math.h>

Vector2d operator-(const Point2d &p1, const Point2d &p2) {
  return Vector2d{p1.x - p2.x, p1.y - p2.y};
}

Point2d operator+(const Point2d &p, const Vector2d &v) {
  return Point2d{p.x + v.dx, p.y + v.dy};
}

Vector2d operator*(const Vector2d &v, float multiplier) {
  return Vector2d{multiplier * v.dx, multiplier * v.dy};
}

Vector2d operator+(const Vector2d &v1, const Vector2d &v2) {
  return Vector2d{v1.dx + v2.dx, v1.dy + v2.dy};
}

float angle(const Vector2d &v1, const Vector2d &v2) {
  float dot = v1.dx * v2.dx + v1.dy * v2.dy;
  float det = v1.dx * v2.dy - v1.dy * v2.dx;
  return atan2(det, dot);
}

float angle(const Point2d &a, const Point2d &b, const Point2d &c) {
  return angle(a - b, c - b);
}

float distance(const Point2d &a, const Point2d &b) {
  return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

Point2d mid(const std::vector<Point2d> &vec) {
  Point2d mid;
  for (const auto &p : vec) {
    mid.x += p.x;
    mid.y += p.y;
  }
  mid.x /= vec.size();
  mid.y /= vec.size();
  return mid;
}

Vector2d crossProduct(const Vector2d &v) {
  return Vector2d{-v.dy, v.dx};
}

float dotProduct(const Vector2d &a, const Vector2d &b) {
  return a.dx * b.dy + b.dx * a.dy;
}

Circular2d toCircular(Cartesian2d &ca) {
  Circular2d ci;
  ci.m = sqrt(pow(ca.x, 2) + pow(ca.y, 2));
  ci.a = atan2(ca.y, ca.x);
  return ci;
}

Cartesian2d toCartesian(Circular2d &ci) {
  Cartesian2d ca;
  ca.x = ci.m * cos(ci.a);
  ca.y = ci.m * sin(ci.a);
  return ca;
}
