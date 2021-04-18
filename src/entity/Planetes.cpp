#include "Planetes.h"

#include "geometry/basic-math.h"
#include "geometry/collision/border.h"
#include "graphics/render.h"
#include "physics/mechanics.h"

Planetes::Planetes(const Point2d &p) {
  obj = PointObj2d{p, cBasisH * cStep, cNull, 1.0, 0.005};
  color = randomColour();
}

void Planetes::draw() const {
  render(Circle2d{obj.p, obj.r}, color);
}

void Planetes::move() {
  // TODO (nn): Orbit mouse position
  orbit(obj, Point2d{0.5, 0.5});
}

void Planetes::handleBorderCollision() {
}
