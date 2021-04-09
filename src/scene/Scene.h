#pragma once

#include <array>
#include <map>

#include "entity/Ball.h"
#include "entity/Particle.h"
#include "entity/Portal.h"
#include "entity/Seesaw.h"

using EntityId = unsigned short;

class Scene {
public:
  Scene();
  void generateBall(float x, float y);
  void generateParticle(float x, float y);
  void destroyParticle(EntityId id);
  void destroyBall(EntityId id);

private:
  std::array<Portal, 2> portals;
  std::map<EntityId, Ball> balls;
  std::map<EntityId, Particle> particles;
  std::vector<Seesaw> seesaws;
};
