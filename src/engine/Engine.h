#pragma once

#include <vector>

#include "input/events.h"
#include "mouse/MouseState.h"
#include "scene/Scene.h"

class Engine {
public:
  void loadKeyInput(const KeyEvent &key);
  void loadouseInput(const MouseEvent &mouse);

  void processInputs();
  void updateEntities();
  void handleInteractions();
  void renderScene();

private:
  EntityId selectedBall;
  EntityId activeBall;

  std::vector<KeyEvent> keyEvents;
  MouseState mouseState;
};
