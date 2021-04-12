#include "geometry/transformation/misc.h"

#include "geometry/basic-math.h"
#include "geometry/transformation/rotation.h"

void flipHorizontal(Point2d &p, float xAxis) {
  p.x = 2 * xAxis - p.x;
}

void flipVertical(Point2d &p, float yAxis) {
  p.y = 2 * yAxis - p.y;
}

void flipLine(Point2d &p, const Line2d &line) {
  Point2d m = mid({line[0], line[1]});
  Vector2d normal = crossProduct(line[0] - line[1]);
  float alpha = angle(p - m, normal);
  rotate(p, m, cPi - 2 * alpha);
}
