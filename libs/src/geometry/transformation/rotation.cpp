#include "geometry/transformation/rotation.h"

#include <math.h>

#include "geometry/basic-math.h"

void rotate(Point2d &p, const Point2d &c, float angle) {
  p.x += distance(p, c) * cos(p.a + angle);
  p.y += distance(p, c) * sin(p.a + angle);
}
