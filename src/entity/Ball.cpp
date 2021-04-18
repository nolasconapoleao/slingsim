#include "Ball.h"

#include "geometry/basic-math.h"
#include "geometry/collision/border.h"
#include "graphics/render.h"
#include "physics/mechanics.h"
#include "random/random.h"

Ball::Ball(const Point2d &p) {
  obj = PointObj2d{p, cBasisH * cStep, cNull, 1.0, 0.005};
  color = rng::colour();
}

void Ball::draw() const {
  render(Circle2d{obj.p, obj.r}, color);
}

void Ball::move() {
  idle(obj);

  Circle2d circle{obj.p, obj.r};
  if (collision::outside(circle)) {
    handleBorderCollision();
  }
}

void Ball::handleBorderCollision() {
  reflect(obj);
  color = rng::colour();
}
