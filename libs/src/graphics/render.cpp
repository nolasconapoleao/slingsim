#include "graphics/render.h"

#ifdef _WIN64
#include "Windows.h"
#endif

#include <GL/gl.h>
#include <math.h>

void render(const Point2d &point, const Colour &colour) {
  glColor3f(colour.r, colour.g, colour.b);
  glBegin(GL_POINTS);
  glVertex2f(point.x, point.y);
  glEnd();
}

void render(const Triangle2d &triangle, const Colour &colour) {
  glColor3f(colour.r, colour.g, colour.b);
  glBegin(GL_TRIANGLES);
  glVertex2f(triangle[0].x, triangle[0].y);
  glVertex2f(triangle[1].x, triangle[1].y);
  glVertex2f(triangle[2].x, triangle[2].y);
  glEnd();
}

void render(const Line2d &line, const Colour &colour) {
  glColor3f(colour.r, colour.g, colour.b);
  glBegin(GL_LINES);
  glVertex2f(line[0].x, line[0].y);
  glVertex2f(line[1].x, line[1].y);
  glEnd();
}

void render(const Poligon2d &poligon, const Colour &colour) {
  glColor3f(colour.r, colour.g, colour.b);
  for (const auto &triangle : poligon) {
    render(triangle, colour);
  }
}

void render(const Circle2d &circle, const Colour &colour) {
  glColor3f(colour.r, colour.g, colour.b);
  glBegin(GL_TRIANGLES);
  float x = circle.r, y = 0;
  for (double i = 0; i <= 360;) {
    glVertex2f(x + circle.c.x, y + circle.c.y);
    i = i + .5;
    x = circle.r * cos(i);
    y = circle.r * sin(i);
    glVertex2f(x + circle.c.x, y + circle.c.y);
    glVertex2f(circle.c.x, circle.c.y);
  }
  glEnd();
}
