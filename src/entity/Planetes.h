#include "entity/IEntity.h"
#include "entity/IMovable.h"

class Planetes : public IEntity, public IMovable {
public:
  Planetes(const Point2d &p);
  void draw() const override;
  void move() override;
  void handleBorderCollision() override;
};
