#pragma once

#include "inputhandler/keyboard.h"

#include <GL/glut.h>

namespace inputhandler {

KeyEvent captureArrowEvent(int key, int x, int y) {
  KeyCode code;
  switch (key) {
    case GLUT_KEY_UP:
      code = KeyCode::UP;
      break;
    case GLUT_KEY_DOWN:
      code = KeyCode::DOWN;
      break;
    case GLUT_KEY_LEFT:
      code = KeyCode::LEFT;
      break;
    case GLUT_KEY_RIGHT:
      code = KeyCode::RIGHT;
      break;
    case GLUT_KEY_INSERT:
      code = KeyCode::SHOOT;
      break;
  }

  return KeyEvent{code, x, y};
}

KeyEvent captureKeyEvent(unsigned char key, int x, int y) {
  KeyCode code;
  switch (key) {
    case 'w':
      code = KeyCode::UP;
      break;
    case 's':
      code = KeyCode::DOWN;
      break;
    case 'a':
      code = KeyCode::LEFT;
      break;
    case 'd':
      code = KeyCode::RIGHT;
      break;
    case ' ':
      code = KeyCode::JUMP;
      break;
    case 'z':
      code = KeyCode::DASH;
      break;
  }

  return KeyEvent{code, x, y};
}

}; // namespace inputhandler
