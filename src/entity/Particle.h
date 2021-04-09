#pragma once

#include "entity/IEntity.h"
#include "entity/IMovable.h"

class Particle : public IEntity, public IMovable {
public:
  void draw() override;
  void move() override;

private:
  Circle2d particle;
};
