#include "input/remap-utils.h"

#include "game-settings.h"
#include "geometry/transformation/misc.h"

Point2d toScene(const Point2d &screenCoordinates) {
  Point2d p = screenCoordinates;
  flipVertical(p, 0.5);
  // TODO (nn): Make this a generic method
  p.x *= cWindowWidth;
  p.y *= cWindowHeight;
  return p;
}

Point2d toPixel(int x, int y) {
  Point2d p{float(x), float(y)};
  normalize(p, cOrig, Point2d{float(cWindowWidth), float(cWindowHeight)});
  flipVertical(p, 0.5);
  return p;
}
