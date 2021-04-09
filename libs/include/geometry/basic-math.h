#pragma once

#include "geometry/types.h"

float angle(const Point2d &a, const Point2d &b, const Point2d &c);
float distance(const Point2d &a, const Point2d &b);

VectorCirc2d toCartesian(const Vector2d &circular);
Vector2d toCircular(const VectorCirc2d &cartesian);

Vector2d crossProduct(const Vector2d &a, const Vector2d &b);
float dotProduct(const VectorCirc2d &a, const VectorCirc2d &b);
