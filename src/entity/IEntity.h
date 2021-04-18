#pragma once

#include "geometry/types.h"
#include "graphics/utils.h"
#include "physics/types.h"

class IEntity {
public:
  virtual void draw() const = 0;

protected:
  PointObj2d obj;
  Colour color;
};
