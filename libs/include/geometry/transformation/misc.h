#pragma once

#include "geometry/types.h"

/**
 * @brief Flips a point using horizontal symmetry axis.
 *
 * @param p Point to flip
 * @param xAxis position of symmetry axis
 */
void flipHorizontal(Point2d &p, float xAxis);

/**
 * @brief Flips a point using vertical symmetry axis.
 *
 * @param p Point to flip
 * @param xAxis position of symmetry axis
 */
void flipVertical(Point2d &p, float yAxis);

/**
 * @brief Flip point with line reference.
 *
 * @param p point to flip
 * @param line reference for flip
 */
void flipLine(Point2d &p, const Line2d &line);
