#pragma once

#include "constants.h"
#include "types.h"

void addForce(PointObj2d &obj, const Vector2d &force);
void addMomentum(PointObj2d &obj, const Vector2d &momentum);

void reflect(PointObj2d &obj);
void teleport(PointObj2d &obj);

void idle(PointObj2d &obj);
void randomWalk(PointObj2d &obj);
void orbit(PointObj2d &obj, Point2d center);
