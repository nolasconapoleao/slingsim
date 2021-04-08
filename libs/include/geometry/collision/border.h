#pragma once

#include "geometry/types.h"

namespace collision {

bool collides(const Point2d &point, const Triangle2d &triangle);
bool collides(const Point2d &point, const Line2d &line);
bool collides(const Point2d &point, const Poligon2d &poligon);
bool collides(const Point2d &point, const Circle2d &circle);

bool collides(const Circle2d point, Circle2d triangle);

} // namespace collision
