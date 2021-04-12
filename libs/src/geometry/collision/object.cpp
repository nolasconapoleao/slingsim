#include "geometry/collision/object.h"

#include "geometry/basic-math.h"

namespace collision {

bool collides(const Point2d &point, const Triangle2d &triangle) {
  // TODO Improve approximation for collsion
  const auto m = mid({triangle[0], triangle[1], triangle[1]});
  Circle2d circle{m, distance(triangle[0], m)};
  return collides(point, circle);
}

bool collides(const Point2d &point, const Line2d &line) {
  return angle(line[0], point, line[1]) == cPi || angle(line[0], point, line[1]) == 0;
}

bool collides(const Point2d &point, const Poligon2d &poligon) {
  // TODO Improve approximation for collsion
  const auto m = mid(poligon);
  Circle2d circle{m, distance(poligon[0], m)};
  return collides(point, circle);
}

bool collides(const Point2d &point, const Circle2d &circle) {
  return distance(circle.c, point) < (circle.r);
  ;
}

bool collides(const Circle2d circle1, Circle2d circle2) {
  return distance(circle1.c, circle2.c) < (circle1.r + circle2.r);
}

} // namespace collision
