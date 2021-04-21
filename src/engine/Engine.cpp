#include "Engine.h"

#include "database/InputDb.h"
#include "geometry/basic-math.h"
#include "input/remap-utils.h"
#include "physics/mechanics.h"
#include "random/random.h"

Engine::Engine() {
  selectedEntity = std::make_shared<Ball>(rng::position());
  selectedEntity->changeAcc(cBasisV * -0.003);
}

void Engine::processInputs() {
  for (const auto &k : InputDb::keyEvents) {
    processKeyPress(k);
  }
  InputDb::keyEvents.clear();

  for (const auto &m : InputDb::mouseEvents) {
    processMouseClick(m);
  }
  InputDb::mouseEvents.clear();
}

void Engine::updateEntities() {
  selectedEntity->move();
  for (auto &b : scene.balls) {
    b.move();
  }
  for (auto &p : scene.particles) {
    p.move();
  }
  for (auto &p : scene.planetes) {
    p.move();
  }
}

void Engine::renderScene() const {
  selectedEntity->draw();
  for (const auto b : scene.balls) {
    b.draw();
  }
  for (const auto p : scene.particles) {
    p.draw();
  }
  for (const auto p : scene.planetes) {
    p.draw();
  }
}

void Engine::processKeyPress(const KeyEvent &event) {
  switch (event.code) {
    case KeyCode::UP:
      selectedEntity->changeAcc(cBasisV * cStep);
      break;
    case KeyCode::DOWN:
      selectedEntity->changeAcc(cBasisV * -cStep);
      break;
    case KeyCode::RIGHT:
      selectedEntity->changeAcc(cBasisH * cStep);
      break;
    case KeyCode::LEFT:
      selectedEntity->changeAcc(cBasisH * -cStep);
      break;
  }
}

void Engine::processMouseClick(const MouseEvent &event) {
  if (event.pressed) {
    InputDb::drag = event.p;
    return;
  }

  InputDb::drop = event.p;
  switch (event.code) {
    case MouseKeyCode::LEFT:
      selectedEntity->changePos(InputDb::drop);
      break;
    case MouseKeyCode::MIDDLE:
      selectedEntity->changeVel(InputDb::drop - InputDb::drag);
      break;
    case MouseKeyCode::RIGHT:
      selectedEntity->mirror(Line2d{InputDb::drag, InputDb::drop});
      break;
  }
}

void Engine::handleInteractions() {
}

void Engine::destroySelected() {
  // TODO(nn): Remove after search
  // scene.balls.erase(selectedId);
}
