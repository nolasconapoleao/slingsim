#pragma once

#include "inputhandler/events.h"

namespace inputhandler {

/**
 * @brief Captures arrow in keyboard event.
 * Example use: glutSpecialFunc(captureKeyEvent);
 *
 * @param key code for pressed key
 * @param x mouse horizontal position during key press
 * @param y mouse vertical position during key press
 * @return KeyEvent captured
 */
KeyEvent captureArrowEvent(int key, int x, int y);

/**
 * @brief Captures keyboard press event.
 * Example use: glutKeyboardFunc(captureKeyEvent);
 *
 * @param key code for pressed key
 * @param x mouse horizontal position during key press
 * @param y mouse vertical position during key press
 * @return KeyEvent captured
 */
KeyEvent captureKeyEvent(unsigned char key, int x, int y);

}; // namespace inputhandler
