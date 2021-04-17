#pragma once

#include "constants.h"
#include "geometry/types.h"

Vector2d operator-(const Point2d &p1, const Point2d &p2);
Point2d operator+(const Point2d &p, const Vector2d &v);
Vector2d operator*(const Vector2d &v, float multiplier);
Vector2d operator+(const Vector2d &v1, const Vector2d &v2);

float angle(const Vector2d &v1, const Vector2d &v2);
float angle(const Point2d &a, const Point2d &b, const Point2d &c);
float distance(const Point2d &a, const Point2d &b);

Point2d mid(const std::vector<Point2d> &vec);

Vector2d crossProduct(const Vector2d &v);
float dotProduct(const Vector2d &a, const Vector2d &b);

// TODO (nn): Should be called after point or vector operations
Circular2d toCircular(Cartesian2d &ca);
Cartesian2d toCartesian(Circular2d &ci);
