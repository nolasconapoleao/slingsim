#pragma once

#include "geometry/types.h"
#include "graphics/utils.h"

// TODO: Make geometric types share interface
void draw(const Point2d &point, const Colour &colour);
void draw(const Triangle2d &point, const Colour &colour);
void draw(const Line2d &point, const Colour &colour);
void draw(const Poligon2d &point, const Colour &colour);
void draw(const Circle2d &point, const Colour &colour);
