#pragma once

#include "geometry/types.h"
#include "input/events.h"

class MouseState {
public:
  void pressEvent(MouseEvent &event);
  Vector2d releaseEvent(MouseEvent &event);

private:
  MouseEvent right;
  MouseEvent center;
  MouseEvent left;
};
