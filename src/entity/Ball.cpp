#include "Ball.h"

#include "geometry/basic-math.h"
#include "geometry/collision/border.h"
#include "geometry/transformation/misc.h"
#include "graphics/render.h"
#include "physics/mechanics.h"
#include "random/random.h"

Ball::Ball(const Point2d &p) {
  obj = PointObj2d{p, cBasisH * rng::decimal() * cStep + cBasisV * rng::decimal() * cStep, cNull, 1.0, 0.01};
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

void Ball::changePos(const Point2d &p) {
  obj.p = p;
}

void Ball::changeVel(const Vector2d &v) {
  obj.v = v;
}

void Ball::changeAcc(const Vector2d &a) {
  obj.a = a;
}

void Ball::mirror(const Line2d &line) {
  flipLine(obj.p, line);
}

void Ball::handleBorderCollision() {
  reflect(obj);
  color = rng::colour();
}
