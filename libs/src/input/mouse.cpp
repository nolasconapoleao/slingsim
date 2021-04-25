#include "input/mouse.h"

#include "database/InputDb.h"
#include "input/remap-utils.h"

namespace input {

void captureMouseEvent(int key, int pressed, int x, int y) {
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
  InputDb::mouseEvents.emplace_back(MouseEvent{code, pressed == 0, p});
}

void captureHover(int x, int y) {
  InputDb::hover = toPixel(x, y);
}

}; // namespace input
