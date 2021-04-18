#pragma once

#include <array>
#include <map>

#include "entity/Ball.h"
#include "entity/Particle.h"
#include "entity/Planetes.h"
#include "entity/Portal.h"
#include "entity/Seesaw.h"

using EntityId = unsigned short;

class Scene {
public:
  Scene();
  void generateBall();
  void generateParticle();
  void generatePlanetes();

  void destroyBall(EntityId id);
  void destroyParticle(EntityId id);
  void destroyPlanetes(EntityId id);

  void run();
  void draw() const;

private:
  EntityId id = 0;
  std::array<Portal, 2> portals;
  std::map<EntityId, Ball> balls;
  std::map<EntityId, Particle> particles;
  std::map<EntityId, Planetes> planetes;
  std::vector<Seesaw> seesaws;
};
