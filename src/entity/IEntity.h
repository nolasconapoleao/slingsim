#pragma once

#include "geometry/types.h"
#include "physics/types.h"

class IEntity {
public:
  virtual void draw() = 0;

protected:
  PointObj2d object;
};
