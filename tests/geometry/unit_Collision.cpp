//
// Created by nolasco on 13/04/21.
//

#define CATCH_CONFIG_MAIN
#include <catch2/single_include/catch2/catch.hpp>
#include <geometry/collision/border.h>
#include <geometry/collision/object.h>

TEST_CASE("Point border collision", "[geometry][collision][border]") {
  auto onBorder = GENERATE(Point2d{0, 0}, Point2d{1, 0}, Point2d{0, 1}, Point2d{1, 1});
  REQUIRE_FALSE(collision::outside(onBorder));

  auto outside = GENERATE(Point2d{-0.1, 0}, Point2d{1.1, 0}, Point2d{0, 1.1}, Point2d{1.1, 1.1}, Point2d{0.1, -0.1});
  REQUIRE(collision::outside(outside));

  auto inside = GENERATE(Point2d{0.1, 0}, Point2d{0.8, 0}, Point2d{0.3, 1}, Point2d{0.2, 0.9});
  REQUIRE_FALSE(collision::outside(inside));
}

constexpr auto cRadius = 0.1;
TEST_CASE("Circle border collision", "[geometry][collision][border]") {
  auto outside = GENERATE(Circle2d{Point2d{0, 0}, cRadius}, Circle2d{Point2d{1, 0}, cRadius},
                          Circle2d{Point2d{0.05, 0}, cRadius});
  REQUIRE(collision::outside(outside));

  auto inside = GENERATE(Circle2d{Point2d{0.15, 0.5}, cRadius}, Circle2d{Point2d{0.8, 0.4}, cRadius},
                         Circle2d{Point2d{0.1, 0.3}, cRadius}, Circle2d{Point2d{0.2, 0.9}, cRadius});
  REQUIRE_FALSE(collision::outside(inside));
}

const Line2d cLine{Point2d{0.2, 0.2}, Point2d{0.4, 0.4}};
TEST_CASE("Line collision", "[geometry][collision][object]") {
  auto outside = GENERATE(Point2d{0.2, 0.1}, Point2d{1.1, 0}, Point2d{0.8, 0.1});
  REQUIRE_FALSE(collision::collides(outside, cLine));

  auto inside = GENERATE(Point2d{0.3, 0.3}, Point2d{0.1, 0.1}, Point2d{0.5, 0.5});
  REQUIRE(collision::collides(inside, cLine));
}

// TODO(nn): Optimization of triangle collision causes failed tests
// const Triangle2d cTriangle {Point2d{0.2, 0.2}, Point2d{0.4, 0.2}, Point2d{0.4, 0.4}};
// TEST_CASE("Triangle collision", "[geometry][collision][object]") {
//   auto outside = GENERATE(Point2d{-0.1, 0}, Point2d{0.3, 0.5}, Point2d{0, 1.1});
//   REQUIRE_FALSE(collision::collides(outside, cTriangle));

//   auto inside = GENERATE(Point2d{0.3, 0.3}, Point2d{0.25, 0.35});
//   REQUIRE(collision::collides(inside, cTriangle));
// }

// const Triangle2d cTriangle2 {Point2d{0.2, 0.2}, Point2d{0.2, 0.4}, Point2d{0.4, 0.4}};
// const Poligon2d cPoligon {cTriangle, cTriangle2};
// TEST_CASE("Poligon collision", "[geometry][collision][object]") {
//   auto outside = GENERATE(Point2d{-0.1, 0}, Point2d{0.3, 0.5}, Point2d{0, 1.1});
//   REQUIRE_FALSE(collision::collides(outside, cTriangle));

//   auto inside = GENERATE(Point2d{0.3, 0.3}, Point2d{0.25, 0.35});
//   REQUIRE(collision::collides(inside, cTriangle));
// }

const Circle2d cCircle{Point2d{0.2, 0.2}, 0.1};
TEST_CASE("Circle-point collision", "[geometry][collision][object]") {
  auto outside = GENERATE(Point2d{0.2, 0}, Point2d{1.1, 0});
  REQUIRE_FALSE(collision::collides(outside, cCircle));

  auto inside = GENERATE(Point2d{0.2, 0.2}, Point2d{0.2, 0.25});
  REQUIRE(collision::collides(inside, cCircle));
}

TEST_CASE("Circle-circle collision", "[geometry][collision][object]") {
  auto outside = GENERATE(Circle2d{Point2d{0.1, 0}, 0.1});
  REQUIRE_FALSE(collision::collides(outside, cCircle));

  auto inside = GENERATE(Circle2d{Point2d{0.2, 0.2}, 0.1}, Circle2d{Point2d{0.2, 0.3}, 0.15});
  REQUIRE(collision::collides(inside, cCircle));
}
