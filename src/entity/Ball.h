#pragma once

#include "entity/IEntity.h"
#include "entity/IMovable.h"

class Ball : public IEntity, public IMovable {
public:
  Ball(const Point2d &p);
  void draw() const override;
  void move() override;

  void changePos(const Point2d &p);
  void changeVel(const Vector2d &v);
  void changeAcc(const Vector2d &a);
  void mirror(const Line2d &line);

  void handleBorderCollision() override;
};
