#pragma once

#include <array>
#include <vector>

#include "entity/Ball.h"
#include "entity/Particle.h"
#include "entity/Planetes.h"
#include "entity/Portal.h"
#include "entity/Seesaw.h"

class Scene {
public:
  Scene();
  void generateBall();
  void generateParticle();
  void generatePlanetes();

  std::array<Portal, 2> portals;
  std::vector<Ball> balls;
  std::vector<Particle> particles;
  std::vector<Planetes> planetes;
  std::vector<Seesaw> seesaws;
};
