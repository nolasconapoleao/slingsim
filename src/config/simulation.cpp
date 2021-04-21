#include "config/simulation.h"

#include <GL/freeglut.h>

#include "engine/Engine.h"
#include "game-settings.h"
#include "input/keyboard.h"
#include "input/mouse.h"

float cWindowWidth = 1920;
float cWindowHeight = 1080;

Engine engine;

void handleKeyPress(int k, int x, int y) {
  input::captureKeyEvent(k, x, y);
  input::captureArrowEvent(k, x, y);
}

void handleClick(int k, int pressed, int x, int y) {
  input::captureMouseEvent(k, pressed, x, y);
}

void handleHover(int x, int y) {
  input::captureHover(x, y);
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

  engine.renderScene();

  glFlush();
  glutSwapBuffers();
}

void looper(int) {
  engine.updateEntities();
  engine.processInputs();

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

void initSimulation() {
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
