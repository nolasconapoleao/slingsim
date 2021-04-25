#include "Planetes.h"

#include "database/InputDb.h"
#include "geometry/basic-math.h"
#include "geometry/collision/border.h"
#include "graphics/render.h"
#include "physics/mechanics.h"
#include "random/random.h"

Planetes::Planetes(const Point2d &p) {
  obj = PointObj2d{p, cBasisH * cStep, cNull, 1.0, 0.005};
  color = rng::colour();
}

void Planetes::draw() const {
  render(Circle2d{obj.p, obj.r}, color);
}

void Planetes::move() {
  orbit(obj, InputDb::hover);
}

void Planetes::handleBorderCollision() {
}
