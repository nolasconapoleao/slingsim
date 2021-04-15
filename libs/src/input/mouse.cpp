#include "input/mouse.h"

#include "input/remap-utils.h"

namespace input {

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

  Point2d p = toPixel(x, y);
  return MouseEvent{code, pressed == 1, p};
}

}; // namespace input
