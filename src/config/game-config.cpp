#include "config/game-config.h"

#include <GL/freeglut.h>
#include <iostream>
#include <math.h>

#include "game-settings.h"
#include "graphics/draw.h"

constexpr float radius = 0.02;

float step = 0.01;
constexpr float xC = 0.5, yC = 0.5;
float vY = 0, aY = -0.005;
float vX = 0, aX = 0.0;
constexpr auto amortizationCoef = 0.8;

Colour color;
Circle2d ball{Point2d{xC, yC}, radius};

void updateColor() {
  color.r = (float)((rand() % 9)) / 8;
  color.g = (float)((rand() % 9)) / 8;
  color.b = (float)((rand() % 9)) / 8;
}

void handleKeyPress(int key, int, int) {
  std::cout << "key: " << key << "\n";
  switch (key) {
    case GLUT_KEY_UP:
      vY += step;
      break;
    case GLUT_KEY_DOWN:
      vY -= step;
      break;
    case GLUT_KEY_LEFT:
      vX -= step;
      break;
    case GLUT_KEY_RIGHT:
      vX += step;
      break;
  }
}

int xDrag, yDrag;
int xDrop, yDrop;
void handleClick(int key, int state, int x, int y) {
  std::cout << "x: " << x << " ,y: " << y << "\n";
  if (key != 0 && state == 0) {
    ball.center.x = float(x) / cWindowWidth;
    ball.center.y = float(cWindowHeight - y) / cWindowHeight;
  }

  if (key == 0) {
    if (state == 0) {
      xDrag = x;
      yDrag = y;
    } else {
      xDrop = x;
      yDrop = y;
      vX = float(xDrop - xDrag) / cWindowWidth;
      vY = float(yDrag - yDrop) / cWindowHeight;
    }
  }
}

void updatePosition() {
  if (ball.center.y < radius) {
    vY *= -amortizationCoef;
    ball.center.y = radius;
    updateColor();
  } else if (ball.center.y > 1 - radius) {
    vY *= -amortizationCoef;
    ball.center.y = 1 - radius;
    updateColor();
  }

  if (ball.center.x < radius) {
    vX *= -amortizationCoef;
    ball.center.x = radius;
    updateColor();
  } else if (ball.center.x > 1 - radius) {
    vX *= -amortizationCoef;
    ball.center.x = 1 - radius;
    updateColor();
  }

  ball.center.y += vY;
  vY += aY;
  ball.center.x += vX;
  vX += aX;
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
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();

  draw(ball, color);

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
