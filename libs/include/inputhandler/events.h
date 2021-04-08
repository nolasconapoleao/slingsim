#pragma once

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
  float x;
  float y;
  bool pressed;
};

struct MouseEvent {
  MouseKeyCode code;
  float x;
  float y;
  bool pressed;
};
