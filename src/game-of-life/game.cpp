#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>

#include "GameOfLife.h"

constexpr GLfloat cWhite[3]{1.0, 1.0, 1.0};
constexpr GLfloat cBlack[3]{0.0, 0.0, 0.0};

constexpr GLint FPS = 1;
constexpr GLint cWindow_width = 600;
constexpr GLint cWindow_height = 600;
constexpr GLfloat xSize = 1.0 / cWidth_game;
constexpr GLfloat ySize = 1.0 / cHeight_game;

GameOfLife game;

void drawRectangle(int x, int y) {
  glVertex2f(x * xSize, y * ySize);
  glVertex2f((x + 1) * xSize, y * ySize);
  glVertex2f((x + 1) * xSize, (y + 1) * ySize);
  glVertex2f(x * xSize, (y + 1) * ySize);
}

void render() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();

  glBegin(GL_QUADS);
  for (GLint x = 0; x < cWidth_game; ++x) {
    for (GLint y = 0; y < cHeight_game; ++y) {
      game.at(x, y) ? glColor3fv(cWhite) : glColor3fv(cBlack);
      drawRectangle(x, y);
    }
  }
  glEnd();

  glFlush();
  glutSwapBuffers();
}

void reshape(int width, int height) {
  glViewport(0, 0, width, height);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, 1.0, 0.0, 1.0);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glutPostRedisplay();
}

void update(int) {
  game.update();

  glutPostRedisplay();
  glutTimerFunc(1000 / FPS, update, 0);
}

void initOpenGl() {
  int argc = 0;
  char **argv;
  glutInit(&argc, argv);

  glutInitWindowSize(cWindow_width, cWindow_height);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("Game of Life");
  glClearColor(1, 1, 1, 1);

  glutReshapeFunc(reshape);
  glutDisplayFunc(render);

  update(0);
  glutMainLoop();
}

int main() {
  initOpenGl();

  // Console render
  // while(true) {
  //     game.loop();
  // }

  return 0;
}
