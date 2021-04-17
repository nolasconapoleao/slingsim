#include "config/game-config.h"

#include <GL/freeglut.h>
#include <iostream>
#include <math.h>

#include "game-settings.h"
#include "geometry/basic-math.h"
#include "geometry/transformation/misc.h"
#include "geometry/transformation/rotation.h"
#include "graphics/draw.h"
#include "input/remap-utils.h"

Point2d ball{0.5, 0.5};
Vector2d v{0, 0};
Vector2d a{0, 0};

constexpr float radius = 0.02;

bool mousePressed = false, trace = false;
bool ctrlToogled = false, altToogled = false, shiftToogled = false;
Point2d drag, drop, hover;

float step = 0.01;
auto amortizationCoef = 1.0;

Colour color;

void updateColor() {
  color.r = (float)((rand() % 9)) / 8;
  color.g = (float)((rand() % 9)) / 8;
  color.b = (float)((rand() % 9)) / 8;
}

void handleKeyPress(int key, int, int) {
  std::cout << "key: " << key << "\n";
  switch (key) {
    case GLUT_KEY_UP:
      v.dy += step;
      break;
    case GLUT_KEY_DOWN:
      v.dy -= step;
      break;
    case GLUT_KEY_LEFT:
      v.dx -= step;
      break;
    case GLUT_KEY_RIGHT:
      v.dx += step;
      break;
    case GLUT_KEY_CTRL_L:
      ctrlToogled = !ctrlToogled;
      break;
    case GLUT_KEY_ALT_L:
      altToogled = !altToogled;
      break;
    case GLUT_KEY_SHIFT_L:
      shiftToogled = !shiftToogled;
      break;
    case GLUT_KEY_CTRL_R:
      trace = !trace;
      break;
  }
}

void handleHover(int x, int y) {
  hover = toPixel(x, y);
}

void handleClick(int key, int released, int x, int y) {
  std::cout << "key: " << key << "x: " << x << " ,y: " << y << "\n";
  Point2d p = toPixel(x, y);

  mousePressed = (released == 0);
  if (released == 0) {
    drag = p;
    return;
  }

  drop = p;
  switch (key) {
    case 0:
      v = drop - drag;
      break;
    case 1:
      ball = p;
      break;
    case 2:
      flipLine(ball, Line2d{drag, drop});
      break;
  }
}

void updatePosition() {
  if (ball.y < radius) {
    v.dy *= -amortizationCoef;
    ball.y = radius;
    updateColor();
  } else if (ball.y > 1 - radius) {
    v.dy *= -amortizationCoef;
    ball.y = 1 - radius;
    updateColor();
  }

  if (ball.x < radius) {
    v.dx *= -amortizationCoef;
    ball.x = radius;
    updateColor();
  } else if (ball.x > 1 - radius) {
    v.dx *= -amortizationCoef;
    ball.x = 1 - radius;
    updateColor();
  }

  if (altToogled) {
    rotate(ball, hover, 0.1);
  }

  a.dy = (ctrlToogled ? 0 : -0.005);

  amortizationCoef = (shiftToogled ? 1.0 : 0.8);

  ball = ball + v;
  v = v + a;
}

void reshape(int width, int height) {
  cWindowWidth = width;
  cWindowHeight = height;
  glViewport(0, 0, width, height);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, 1.0, 0.0, 1.0);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glutPostRedisplay();
}

void display() {
  if (!trace) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
  }

  draw(Circle2d{Point2d{ball.x, ball.y}, radius}, color);
  if (mousePressed) {
    draw(Line2d{drag, hover}, colour::Red);
  }

  glFlush();
  glutSwapBuffers();
}

// TODO: Code above should be replaced by library calls
void looper(int) {
  updatePosition();

  glutPostRedisplay();
  glutTimerFunc(1000 / FPS, looper, 0);
}

void loadinput() {
  glutMotionFunc(handleHover);
  glutPassiveMotionFunc(handleHover);
  glutMouseFunc(handleClick);
  glutSpecialFunc(handleKeyPress);
}

void loadRenderer() {
  glutDisplayFunc(display);
}

void loadReshaper() {
  glutReshapeFunc(reshape);
}

void initGame() {
  int argc = 0;
  char *argv;

  glutInit(&argc, &argv);
  glutInitDisplayMode(GLUT_SINGLE);
  glutInitWindowSize(cWindowWidth, cWindowHeight);
  glutCreateWindow("Sling");
  glClearColor(0, 0, 0, 0);
  glClear(GL_COLOR_BUFFER_BIT);

  loadinput();
  loadRenderer();
  loadReshaper();

  looper(0);
  glutMainLoop();
}
