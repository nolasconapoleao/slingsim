#include "Scene.h"

#include "geometry/basic-math.h"
#include "random/random.h"

Scene::Scene() {
  for (auto k = 0; k < 10; k++) {
    generateBall();
    generateParticle();
    generatePlanetes();
  }
}

void Scene::generateBall() {
  balls.emplace_back(Ball(rng::position()));
}

void Scene::generateParticle() {
  particles.emplace_back(Particle(rng::position()));
}

void Scene::generatePlanetes() {
  planetes.emplace_back(Planetes(rng::position()));
}
