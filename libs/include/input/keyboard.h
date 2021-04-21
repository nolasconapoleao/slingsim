#pragma once

#include "input/events.h"

namespace input {

/**
 * @brief Captures arrow in keyboard event.
 * Example use: glutSpecialFunc(captureKeyEvent);
 *
 * @param key code for pressed key
 * @param x mouse horizontal position during key press
 * @param y mouse vertical position during key press
 */
void captureArrowEvent(int key, int x, int y);

/**
 * @brief Captures keyboard press event.
 * Example use: glutKeyboardFunc(captureKeyEvent);
 *
 * @param key code for pressed key
 * @param x mouse horizontal position during key press
 * @param y mouse vertical position during key press
 */
void captureKeyEvent(unsigned char key, int x, int y);

}; // namespace input
