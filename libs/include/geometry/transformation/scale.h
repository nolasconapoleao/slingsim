#pragma once

#include "geometry/types.h"

/**
 * @brief Scales a point using scaling factor.
 *
 * @param p Point to scale
 * @param s scaling point reference
 * @param factor scaling factor
 */
void scale(Point2d &p, const Point2d &s, float factor);
