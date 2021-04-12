#include "geometry/transformation/scale.h"

#include "geometry/basic-math.h"
#include "math.h"

void scale(Point2d &p, const Point2d &s, float factor) {
  p.x = s.x + distance(p, s) * factor * cos(angle(p - s, cBasisH));
  p.y = s.y + distance(p, s) * factor * sin(angle(p - s, cBasisH));
}
