#pragma once

#include "geometry/types.h"

/**
 * @brief Converts coordinates to scene.
 *
 * @param screenCoordinates
 * @return Point2d scene coordinates
 */
Point2d toScene(const Point2d &screenCoordinates);

/**
 * @brief Converts coordinates to normalized screen coordinates.
 *
 * @return x scene coordinate
 * @return y scene coordinate
 * @param Point2d screen Coordinates
 */
Point2d toPixel(int x, int y);
