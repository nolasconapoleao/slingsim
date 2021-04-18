#include "Scene.h"

#include "random/random.h"

Scene::Scene() {
  for (auto k = 0; k < 10; k++) {
    generateBall();
    generateParticle();
    generatePlanetes();
  }
}

void Scene::generateBall() {
  balls.emplace(id++, Ball(rng::position()));
}

void Scene::generateParticle() {
  particles.emplace(id++, Particle(rng::position()));
}

void Scene::generatePlanetes() {
  planetes.emplace(id++, Planetes(rng::position()));
}

void Scene::run() {
  for (auto &[id, b] : balls) {
    b.move();
  }
  for (auto &[id, p] : particles) {
    p.move();
  }
  for (auto &[id, p] : planetes) {
    p.move();
  }
}

void Scene::draw() const {
  for (const auto &[id, b] : balls) {
    b.draw();
  }
  for (const auto &[id, p] : particles) {
    p.draw();
  }
  for (const auto &[id, p] : planetes) {
    p.draw();
  }
}
