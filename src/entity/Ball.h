#pragma once

#include "entity/IEntity.h"
#include "entity/IMovable.h"

class Ball : public IEntity, public IMovable {
public:
  Ball(const Point2d &p);
  void draw() const override;
  void move() override;
  void handleBorderCollision() override;
};
