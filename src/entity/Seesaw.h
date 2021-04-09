#pragma once

#include "entity/IEntity.h"
#include "entity/IMovable.h"

class Seesaw : public IEntity {
public:
  void draw() override;

private:
  Line2d seesaw;
};
