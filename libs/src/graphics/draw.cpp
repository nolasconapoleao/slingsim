#pragma once

#include "graphics/draw.h"

#ifdef _WIN64
    #include "Windows.h"
#endif

#include <GL/gl.h>
#include <math.h>

void draw(const Point2d &point, const Colour &colour) {
  glColor3f(colour.r, colour.g, colour.b);
  glBegin(GL_POINTS);
  glVertex2f(point.x, point.y);
  glEnd();
}

void draw(const Triangle2d &triangle, const Colour &colour) {
  glColor3f(colour.r, colour.g, colour.b);
  glBegin(GL_TRIANGLES);
  glVertex2f(triangle[0].x, triangle[0].y);
  glVertex2f(triangle[1].x, triangle[1].y);
  glVertex2f(triangle[2].x, triangle[2].y);
  glEnd();
}

void draw(const Line2d &line, const Colour &colour) {
  glColor3f(colour.r, colour.g, colour.b);
  glBegin(GL_LINES);
  glVertex2f(line[0].x, line[0].y);
  glVertex2f(line[1].x, line[1].y);
  glEnd();
}

void draw(const Poligon2d &poligon, const Colour &colour) {
  glColor3f(colour.r, colour.g, colour.b);
  for (const auto &triangle : poligon) {
    draw(triangle, colour);
  }
}

void draw(const Circle2d &circle, const Colour &colour) {
  glColor3f(colour.r, colour.g, colour.b);
  glBegin(GL_TRIANGLES);
  float x = circle.radius, y = 0;
  for (double i = 0; i <= 360;) {
    glVertex2f(x + circle.center.x, y + circle.center.y);
    i = i + .5;
    x = circle.radius * cos(i);
    y = circle.radius * sin(i);
    glVertex2f(x + circle.center.x, y + circle.center.y);
    glVertex2f(circle.center.x, circle.center.y);
  }
  glEnd();
}
