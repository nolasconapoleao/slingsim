#include "config/game-config.h"

#include <GL/freeglut.h>
#include <iostream>
#include <math.h>

#include "game-settings.h"
#include "geometry/basic-math.h"
#include "geometry/collision/border.h"
#include "geometry/transformation/misc.h"
#include "geometry/transformation/rotation.h"
#include "graphics/render.h"
#include "input/remap-utils.h"
#include "physics/mechanics.h"
#include "scene/Scene.h"

Scene scene;

constexpr Point2d p{0.5, 0.5};
constexpr Vector2d v{0, 0};
constexpr Vector2d a{0, 0};
constexpr float mass = 1.0;
constexpr float radius = 0.02;

float amortizationCoef = 1.0;
float cWindowWidth = 1920;
float cWindowHeight = 1080;

PointObj2d ball{p, v, a, mass, radius};

bool mousePressed, traceToogle, collisionToogle;
bool gravityToogle, dampingToogle;
short moveToogle;
Point2d drag, drop, hover;

Colour color;

void handleKeyPress(int key, int, int) {
  std::cout << "key: " << key << "\n";
  switch (key) {
    case GLUT_KEY_UP:
      addForce(ball, cBasisV * cStep);
      break;
    case GLUT_KEY_DOWN:
      addForce(ball, cBasisV * -cStep);
      break;
    case GLUT_KEY_RIGHT:
      addForce(ball, cBasisH * cStep);
      break;
    case GLUT_KEY_LEFT:
      addForce(ball, cBasisH * -cStep);
      break;
    case GLUT_KEY_CTRL_L:
      gravityToogle = !gravityToogle;
      break;
    case GLUT_KEY_ALT_L:
      moveToogle++;
      moveToogle %= 3;
      break;
    case GLUT_KEY_SHIFT_L:
      dampingToogle = !dampingToogle;
      break;
    case GLUT_KEY_CTRL_R:
      traceToogle = !traceToogle;
      break;
    case GLUT_KEY_SHIFT_R:
      collisionToogle = !collisionToogle;
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
      if (modulus(drag - drop) < cStep) {
        ball.v = cNull;
      } else {
        addMomentum(ball, drop - drag);
      }
      break;
    case 1:
      ball.p = p;
      break;
    case 2:
      flipLine(ball.p, Line2d{drag, drop});
      break;
  }
}

void updatePosition() {
  scene.run();
  Circle2d circle{ball.p, ball.r};
  if (collision::outside(circle)) {
    if (collisionToogle) {
      teleport(ball);
    } else {
      color = randomColour();
      reflect(ball);
    }
  }

  if (moveToogle == 0) {
    ball.r = radius;
    idle(ball);
  } else if (moveToogle == 1) {
    ball.r = radius;
    orbit(ball, hover);
  } else {
    ball.r = 0.005;
    randomWalk(ball);
  }

  ball.a.dy = (gravityToogle ? 0 : -0.005);

  amortizationCoef = (dampingToogle ? 1.0 : 0.8);
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
  if (!traceToogle) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
  }

  scene.draw();
  render(Circle2d{ball.p, ball.r}, color);
  render(Circle2d{hover, 0.005}, colour::Green);
  if (mousePressed) {
    render(Line2d{drag, hover}, colour::Red);
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
