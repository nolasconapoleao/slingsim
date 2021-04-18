#pragma once

#include "geometry/types.h"
#include "graphics/utils.h"

// TODO: Make geometric types share interface
void render(const Point2d &point, const Colour &colour);
void render(const Triangle2d &triangle, const Colour &colour);
void render(const Line2d &line, const Colour &colour);
void render(const Poligon2d &poligon, const Colour &colour);
void render(const Circle2d &circle, const Colour &colour);
