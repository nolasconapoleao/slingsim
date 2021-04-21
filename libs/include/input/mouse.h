#pragma once

#include "input/events.h"

namespace input {

/**
 * @brief Captures mouse click event.
 * Example use: glutMouseFunc(captureKeyEvent);
 *
 * @param key mouse zone for click
 * @param pressed true means pressed, false means released
 * @param x mouse horizontal position during key press
 * @param y mouse vertical position during key press
 */
void captureMouseEvent(int key, int pressed, int x, int y);

/**
 * @brief Capture hover over screen event.
 *
 * @param x mouse horizontal position during hover
 * @param y mouse vertical position during hover
 */
void captureHover(int x, int y);

}; // namespace input
