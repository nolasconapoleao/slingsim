#pragma once

#include "entity/IEntity.h"
#include "entity/IMovable.h"

class Particle : public IEntity, public IMovable {
public:
  Particle(const Point2d &p);
  void draw() const override;
  void move() override;
  void handleBorderCollision() override;
};
