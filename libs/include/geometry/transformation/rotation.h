#pragma once

#include "geometry/types.h"

/**
 * @brief Rotates a point using horizontal symmetry axis.
 *
 * @param p Point to rotate
 * @param c center of rotation
 * @param angle rotation angle (in radians), positive means anti ccw rotation
 */
void rotate(Point2d p, Point2d c, float angle);
