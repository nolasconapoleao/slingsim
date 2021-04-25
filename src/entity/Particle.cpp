#include "Particle.h"

#include "geometry/basic-math.h"
#include "geometry/collision/border.h"
#include "graphics/render.h"
#include "physics/mechanics.h"
#include "random/random.h"

Particle::Particle(const Point2d &p) {
  obj = PointObj2d{p, cBasisH * cStep, cNull, 1.0, 0.005};
  color = rng::colour();
}

void Particle::draw() const {
  render(Circle2d{obj.p, obj.r}, color);
}

void Particle::move() {
  randomWalk(obj);

  Circle2d circle{obj.p, obj.r};
  if (collision::outside(circle)) {
    handleBorderCollision();
  }
}

void Particle::handleBorderCollision() {
  teleport(obj);
}
