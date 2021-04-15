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
  float alpha = angle(p, line[0], line[1]);
  rotate(p, line[0], 2 * alpha);
}

void normalize(Point2d &point, const Point2d &orig, const Point2d &limit) {
  const float width = limit.x - orig.x;
  const float height = limit.y - orig.y;

  point.x = (point.x - orig.x) / width;
  point.y = (point.y - orig.y) / height;
}
