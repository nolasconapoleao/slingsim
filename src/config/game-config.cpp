#include "config/game-config.h"

#include <chrono>
#include <ctime>
#include <iostream>
#include <math.h>
#include <cstdio>

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/matrix.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "engine/Shader.h"
#include "engine/Model.h"
#include "game-settings.h"
#include "geometry/basic-math.h"
#include "geometry/transformation/misc.h"
#include "geometry/transformation/rotation.h"
#include "graphics/draw.h"
#include "input/keyboard.h"
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
Shader firstProgram;
Model model;

glm::mat4 modelMatrix,viewMatrix,projMatrix;
float camX = 0.0f, camY = 0.0f, camZ = 50;

//Jumping formulas;
glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), velocity = glm::vec3(0.0f), v_0 = glm::vec3(0.0f),
          v_x = glm::vec3(0.0f);
float initJumpVelocity(0.0f), termVelocity(0.0f);
float dt = 0.0f, gravity = 0.0f;
float termTime = 0.0f, timeToApex = 0.0f;
float vel = 1.00f, h = 5.0f, x_h = 10.0f, acc = -9.807f, vel_x = 0.0f, v_init = 0.0f;
std::chrono::system_clock::time_point start, stop;
std::chrono::duration<float> elapsed;
//std::chrono::system_clock::time_point end;

int code=0;
int code2=0;

void captureKeyEvent(unsigned char key, int x, int y) {
  switch (key) {
    case 'w':
      camZ -= 0.01f;
      break;
    case 's':
      camZ += 0.01f;
      break;
    case 'a':
      camX -= 0.01f;
      break;
    case 'd':
      camX += 0.01f;
      break;
    case ' ':
      break;
    case 'z': {
    
    }
      break;
  }

  // return KeyEvent{code, Point2d{float(x), float(y)}};
}

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
  stop = start;
  start = std::chrono::system_clock::now();

  if (!trace) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
  }
  /*
  draw(Circle2d{Point2d{ball.x, ball.y}, radius}, color);
  if (mousePressed) {
    draw(Line2d{drag, hover}, colour::Red);
  }*/

  firstProgram.bind();
  viewMatrix = glm::lookAt(glm::vec3(0.0f, 0.0f, camZ), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));

  elapsed = start - stop;
  dt += elapsed.count();

  std::cout << "x: " << v_0.x << " y: " << v_0.y << "\n";
  /*
  vel += acc * dt;

  v_0 = position + glm::vec3(0, 1, 0);
  v_x = position + glm::vec3(1, 0, 0);
  */
  // position.y = (-2 * 1.22 / (2.44 * 2.44) * position.x * position.x) / 2 + position.x;

  firstProgram.sendUniform(modelMatrix, Shader::MATRICES::MODEL_MATRIX);
  firstProgram.sendUniform(viewMatrix, Shader::MATRICES::VIEW_MATRIX);
  firstProgram.sendUniform(projMatrix, Shader::MATRICES::PROJECTION_MATRIX);
  firstProgram.sendUniform(v_0, code);
  firstProgram.sendUniform(v_x, code2);

  model.render();
  firstProgram.unbind();

  vel_x = glm::sqrt(-9.807f * glm::pow(x_h,2) / (-2.0f * glm::pow(h,2)));
  v_init = 2.0f * h * vel_x / x_h;

  v_0.x = 0;//vel_x * dt;
  v_0.y = (-2.0f * h * glm::pow(vel_x, 2) / glm::pow(x_h, 2)) * dt * dt / 2 + v_init * dt;

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
  glutKeyboardFunc(captureKeyEvent);
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

  glutInitContextVersion(4, 5);
  glutInitContextProfile(GLUT_CORE_PROFILE);
  glutInit(&argc, &argv);
  glutInitDisplayMode(GLUT_SINGLE);
  glutInitWindowSize(cWindowWidth, cWindowHeight);
  glutCreateWindow("Sling");
  
  glEnable(GL_CULL_FACE);  
  glClearColor(1, 1, 1, 0);
  glClear(GL_COLOR_BUFFER_BIT);

  stop = std::chrono::system_clock::time_point::time_point();
  start = std::chrono::system_clock::now();
  loadinput();
  loadRenderer();
  loadReshaper();

  GLint GlewInitResult = glewInit();
  if (GLEW_OK != GlewInitResult) {
    exit(EXIT_FAILURE);
  }
  
  //Init Shaders
  firstProgram.init();
  firstProgram.create("./shaders/vertex.vert", Shader::SHADER_TYPE::VERTEX_SHADER);
  firstProgram.create("./shaders/frag.frag", Shader::SHADER_TYPE::FRAGMENT_SHADER);
  firstProgram.enable();

  firstProgram.uniformInit("ModelMatrix", Shader::MATRICES::MODEL_MATRIX);
  firstProgram.uniformInit("ViewMatrix", Shader::MATRICES::VIEW_MATRIX);
  firstProgram.uniformInit("ProjMatrix", Shader::MATRICES::PROJECTION_MATRIX);
  code = firstProgram.uniformInit("v_0");
  code2 = firstProgram.uniformInit("v_x");
  //Init Matrices
  modelMatrix = glm::mat4(1.0f);
  projMatrix = glm::mat4(1.0f);
  viewMatrix = glm::mat4(1.0f);
  projMatrix = glm::perspective(glm::degrees(60.0f), static_cast<float>(cWindowWidth / cWindowHeight), 0.1f, 1000.0f);

  model.load();

  looper(0);
  glutMainLoop();
}
