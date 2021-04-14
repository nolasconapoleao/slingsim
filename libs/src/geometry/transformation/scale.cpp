#include "geometry/transformation/scale.h"

#include "geometry/basic-math.h"
#include "math.h"

void scale(Point2d &p, const Point2d &s, float factor) {
  float dist = distance(p, s) * factor;
  float newAngle = angle(cBasisH, p - s);
  p.x = s.x + dist * factor * cos(newAngle);
  p.y = s.y + dist * factor * sin(newAngle);
}
