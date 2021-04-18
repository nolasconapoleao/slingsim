#pragma once

#include "geometry/types.h"

namespace collision {

bool outside(const Point2d point);
bool outsideV(const Point2d point);
bool outsideH(const Point2d point);
bool outside(const Circle2d circle);
bool outsideV(const Circle2d circle);
bool outsideH(const Circle2d circle);

} // namespace collision
