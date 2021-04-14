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
