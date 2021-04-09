#pragma once

#include "input/mouse.h"

#include "game-settings.h"

namespace input {
/**
 * @brief Remaps the coordinates of the key event.
 *
 * @param event flipped vertically
 */
void remap(MouseEvent event);

MouseEvent captureMouseEvent(int key, int pressed, int x, int y) {
  MouseKeyCode code;
  switch (key) {
    case 0:
      code = MouseKeyCode::LEFT;
      break;
    case 1:
      code = MouseKeyCode::MIDDLE;
      break;
    case 2:
      code = MouseKeyCode::RIGHT;
      break;
    case 3:
      code = MouseKeyCode::SCROLL_UP;
      break;
    case 4:
      code = MouseKeyCode::SCROLL_DOWN;
      break;
  }

  MouseEvent event{code, pressed, x, y};
  remap(event);
  return event;
}

void remap(MouseEvent event) {
  event.x = float(cWindowWidth - event.x) / cWindowWidth;
  event.x = float(cWindowHeight - event.y) / cWindowHeight;
}

}; // namespace input
