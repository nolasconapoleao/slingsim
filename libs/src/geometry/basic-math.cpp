#include "geometry/basic-math.h"

#include <math.h>

Vector2d operator-(const Point2d &p1, const Point2d &p2) {
  return Vector2d{p1.x - p2.x, p1.y - p2.y};
}

Point2d operator+(const Point2d &p, const Vector2d &v) {
  return Point2d{p.x + v.dx, p.y + v.dy};
}

Vector2d operator*(const float multiplier, const Vector2d &v) {
  return Vector2d{multiplier * v.dx, multiplier * v.dy};
}

float angle(const Vector2d &v1, const Vector2d &v2) {
  return atan2(v1.dx - v2.dx, v1.dy - v2.dy);
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

void udpateCircular(Vector2d &v) {
  v.m = sqrt(pow(v.dx, 2) + pow(v.dy, 2));
  v.a = atan2(v.dx, v.dy);
}

void udpateCartesian(Vector2d &v) {
  v.dx = v.m * cos(v.a);
  v.dy = v.m * sin(v.a);
}
