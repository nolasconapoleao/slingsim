#include "geometry/transformation/translation.h"

#include "geometry/basic-math.h"

void translate(Point2d &p, const Vector2d &direction) {
  p = p + direction;
}
