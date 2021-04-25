#pragma once

#include <vector>

#include "input/events.h"

class InputDb {
public:
  static std::vector<KeyEvent> keyEvents;
  static std::vector<MouseEvent> mouseEvents;
  static Point2d drag, drop, hover;
};
