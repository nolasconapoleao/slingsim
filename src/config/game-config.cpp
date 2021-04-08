#include "config/game-config.h"

#include <GL/freeglut.h>

#include "game-settings.h"

int x, y;
float r, g, b;

void loadInputHandler() {
}

void loadRenderer() {
  const auto magicDots = []() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, cWindowWidth, 0.0, cWindowHeight);

    glColor3f(r, g, b);

    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();

    glFlush();
  };

  glutDisplayFunc(magicDots);
}

void loadUpdater() {
  const auto idle = []() {
    x = rand() % cWindowWidth;
    y = rand() % cWindowHeight;

    r = (float)((rand() % 9)) / 8;
    g = (float)((rand() % 9)) / 8;
    b = (float)((rand() % 9)) / 8;

    glutPostRedisplay();
  };

  glutIdleFunc(idle);
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
  loadUpdater();

  glutMainLoop();
}
