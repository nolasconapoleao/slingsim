#pragma once

#include "geometry/types.h"
#include "graphics/utils.h"

// TODO: Make geometric types share interface
void draw(const Point2d &point, const Colour &colour);
void draw(const Triangle2d &triangle, const Colour &colour);
void draw(const Line2d &line, const Colour &colour);
void draw(const Poligon2d &poligon, const Colour &colour);
void draw(const Circle2d &circle, const Colour &colour);
