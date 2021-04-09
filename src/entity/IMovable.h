#pragma once

#include "geometry/types.h"
#include "physics/types.h"

class IMovable {
public:
  virtual void move() = 0;

protected:
  PointObj2d object;
};
