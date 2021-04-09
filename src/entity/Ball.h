#pragma once

#include "entity/IEntity.h"
#include "entity/IMovable.h"

class Ball : public IEntity, public IMovable {
public:
  void draw() override;
  void move() override;

private:
  Circle2d ball;
};
