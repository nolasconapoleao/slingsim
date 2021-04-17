#include "geometry/transformation/rotation.h"

#include <math.h>

#include "geometry/basic-math.h"

void rotate(Point2d &p, const Point2d &c, float a) {
  float dist = distance(p, c);
  float newAngle = angle(cBasisH, p - c) + a;
  p.x = c.x + dist * cos(newAngle);
  p.y = c.y + dist * sin(newAngle);
}
