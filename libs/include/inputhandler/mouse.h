#pragma once

#include "inputhandler/events.h"

namespace inputhandler {

/**
 * @brief Captures mouse click event.
 * Example use: glutMouseFunc(captureKeyEvent);
 *
 * @param key mouse zone for click
 * @param pressed true means pressed, false means released
 * @param x mouse horizontal position during key press
 * @param y mouse vertical position during key press
 * @return MouseEvent captured
 */
MouseEvent captureMouseEvent(int key, int pressed, int x, int y);

}; // namespace inputhandler
