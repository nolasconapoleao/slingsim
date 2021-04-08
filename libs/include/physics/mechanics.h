#pragma once

#include "types.h"

void applyForce(PointObj2d &obj, const Vector2d force);
void applyForce(PointObj2d &obj, const VectorCirc2d force);

void transferMomentum(PointObj2d &origin, const Vector2d destination, float amont);
