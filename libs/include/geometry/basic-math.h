#pragma once

#include "geometry/types.h"

float angle(const Point2d &a, const Point2d &b, const Point2d &c);
float distance(const Point2d &a, const Point2d &b);

VectorCirc2d toCartesian(const Vector2d &circular);
Vector2d toCircular(const VectorCirc2d &cartesian);
