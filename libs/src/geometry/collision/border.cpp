#include "geometry/collision/border.h"

namespace collision {

bool outside(const Point2d point) {
  return outsideV(point) || outsideH(point);
}

bool outsideV(const Point2d point) {
  return point.y < 0 || point.y > 1;
}

bool outsideH(const Point2d point) {
  return point.x < 0 || point.x > 1;
}

bool outside(const Circle2d circle) {
  return outsideV(circle) || outsideH(circle);
}

bool outsideV(const Circle2d circle) {
  return circle.c.y < circle.r || circle.c.y > (1 - circle.r);
}

bool outsideH(const Circle2d circle) {
  return circle.c.x < circle.r || circle.c.x > (1 - circle.r);
}

} // namespace collision
