#include "geometry/collision/border.h"

namespace collision {

bool collides(const Point2d point) {
  return point.x < 0 || point.y < 0 || point.x > 1 || point.y > 1;
}

bool collides(const Circle2d circle) {
  return circle.c.x < circle.r || circle.c.y < circle.r || circle.c.x > (1 - circle.r) || circle.c.y > (1 - circle.r);
}

} // namespace collision
