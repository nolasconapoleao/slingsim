#include "config/game-config.h"

#include <GL/freeglut.h>
#include <iostream>
#include <math.h>

#include "game-settings.h"

GLfloat colour[3]{0.0, 1.0, 0.0};
const float radius = 0.02;

float step = 0.01;
float xC = 0.5, yC = 0.5;
float vY = 0, aY = -.005;
float vX = 0, aX = 0.0;

void updateColor() {
  colour[0] = (float)((rand() % 9)) / 8;
  colour[1] = (float)((rand() % 9)) / 8;
  colour[2] = (float)((rand() % 9)) / 8;
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

bool stopped = false;
void handleClick(int, int state, int x, int y) {
  std::cout << "x: " << x << " ,y: " << y << "\n";
  if (state == 0) {
    stopped = false;
    xC = float(x) / cWindowWidth;
    yC = float(cWindowHeight - y) / cWindowHeight;
    vY = 0;
    aY = -.005;
  }
}

void updatePosition() {
  if (!stopped) {
    yC += vY;
    vY += aY;
    xC += vX;
    vX += aX;
  }

  if (yC < radius) {
    yC *= -1;
    vY *= -0.8;
    if (vY < 0.0001) {
      vY = 0.0;
      yC = radius;
      stopped = true;
    } else {
      updateColor();
    }
  }
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

void drawCircle(float xCenter, float yCenter) {
  glBegin(GL_TRIANGLES);
  float x = radius, y = 0;
  for (double i = 0; i <= 360;) {
    glVertex2f(x + xCenter, y + yCenter);
    i = i + .5;
    x = radius * cos(i);
    y = radius * sin(i);
    glVertex2f(x + xCenter, y + yCenter);
    glVertex2f(xCenter, yCenter);
  }
  glEnd();
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();

  glColor3fv(colour);
  drawCircle(xC, yC);

  glFlush();
  glutSwapBuffers();
}

// TODO: Code above should be replaced by library calls

void looper(int) {
  updatePosition();

  glutPostRedisplay();
  glutTimerFunc(1000 / FPS, looper, 0);
}

void loadInputHandler() {
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
  int argc = 1;
  char *argv;

  glutInit(&argc, &argv);
  glutInitDisplayMode(GLUT_SINGLE);
  glutInitWindowSize(cWindowWidth, cWindowHeight);
  glutCreateWindow("Sling");
  glClearColor(0, 0, 0, 0);
  glClear(GL_COLOR_BUFFER_BIT);

  loadInputHandler();
  loadRenderer();
  loadReshaper();

  looper(0);
  glutMainLoop();
}
