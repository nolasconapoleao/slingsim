#pragma once

#include "geometry/types.h"

enum class KeyCode {
  // Move event
  UP,
  DOWN,
  LEFT,
  RIGHT,

  // Action event
  SHOOT,
  JUMP,
  DASH
};

enum class MouseKeyCode { LEFT, MIDDLE, RIGHT, SCROLL_UP, SCROLL_DOWN };

struct KeyEvent {
  KeyCode code;
  Point2d p;
};

struct MouseEvent {
  MouseKeyCode code;
  bool pressed;
  Point2d p;
};
