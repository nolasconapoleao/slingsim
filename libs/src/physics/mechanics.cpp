#include "physics/mechanics.h"

#include "geometry/basic-math.h"
#include "geometry/collision/border.h"
#include "geometry/transformation/misc.h"
#include "geometry/transformation/rotation.h"

using namespace collision;

void addForce(PointObj2d &obj, const Vector2d &force) {
  obj.a = obj.a + force / obj.m;
}

void addMomentum(PointObj2d &obj, const Vector2d &momentum) {
  obj.v = obj.v + (momentum / obj.m);
}

void reflect(PointObj2d &obj) {
  Circle2d circle{obj.p, obj.r};
  if (outsideV(circle)) {
    obj.v.dy *= -amortizationCoef;
  }

  if (outsideH(circle)) {
    obj.v.dx *= -amortizationCoef;
  }
}

void teleport(PointObj2d &obj) {
  Circle2d circle{obj.p, obj.r};
  if (outsideH(circle)) {
    flipHorizontal(obj.p, 0.5);
  }

  if (outsideV(circle)) {
    flipVertical(obj.p, 0.5);
  }
}

void idle(PointObj2d &obj) {
  obj.p = obj.p + obj.v;
  obj.v = obj.v + obj.a;
}

void randomWalk(PointObj2d &obj) {
  const auto rng = rand() % 25;
  if (rng == 0) {
    const auto randAngle = (rand() % 360);
    // TODO(nn): Make this a function
    const auto radian = (randAngle - 180) / 180.0f * cPi;
    const Circular2d circular{modulus(obj.v), randAngle};
    const auto newVel = toCartesian(circular);
    obj.v = Vector2d{newVel.x, newVel.y};
  }
  idle(obj);
}

void orbit(PointObj2d &obj, Point2d center) {
  auto signal = angle(obj.v, cBasisH);
  auto vel = signal > 0 ? modulus(obj.v) : -modulus(obj.v);
  rotate(obj.p, center, vel);
}
