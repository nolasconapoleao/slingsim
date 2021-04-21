#pragma once

#include <memory>
#include <vector>

#include "database/Scene.h"
#include "entity/Ball.h"
#include "geometry/types.h"
#include "input/events.h"

class Engine {
public:
  Engine();
  void processInputs();
  void updateEntities();
  void handleInteractions();
  void renderScene() const;

private:
  void processKeyPress(const KeyEvent &event);
  void processMouseClick(const MouseEvent &event);

  void destroySelected();

  std::shared_ptr<Ball> selectedEntity;
  Scene scene;
};
