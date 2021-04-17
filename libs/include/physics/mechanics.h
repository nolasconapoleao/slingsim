#pragma once

#include "types.h"

void operator+(PointObj2d &obj, const Vector2d &force) {

  void transferMomentum(PointObj2d & obj, float momentum);

  void teleport(PointObj2d & obj, float momentum);

  void move(PointObj2d & obj);
