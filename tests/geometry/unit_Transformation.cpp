#define CATCH_CONFIG_MAIN
#include <catch2/single_include/catch2/catch.hpp>
#include <geometry/transformation/misc.h>
#include <geometry/transformation/rotation.h>
#include <geometry/transformation/scale.h>
#include <geometry/transformation/translation.h>

#include "comparators.h"

constexpr Point2d cPoint{0.5, 0.5};

TEST_CASE("Rotate point", "[geometry][misc][rotate]") {
  Point2d pTest = cPoint;
  rotate(pTest, Point2d{0, 0}, 0);

  Point2d pExpected = cPoint;
  REQUIRE(equals(pTest, pExpected));
}

TEST_CASE("Scale point", "[geometry][misc][scale]") {
  Point2d pTest = cPoint;
  scale(pTest, Point2d{0, 0}, 2);

  Point2d pExpected{1, 1};
  REQUIRE(equals(pTest, pExpected));
}

TEST_CASE("Translate point", "[geometry][misc][translate]") {
  Point2d pTest = cPoint;
  translate(pTest, Vector2d{0.5, 0});

  Point2d pExpected{1, 0.5};
  REQUIRE(equals(pTest, pExpected));
}

TEST_CASE("Flip point around axis", "[geometry][misc][flip]") {
  Point2d pTest = cPoint;
  flipHorizontal(pTest, 0);
  Point2d pExpected{-0.5, 0.5};
  REQUIRE(equals(pTest, pExpected));

  flipVertical(pTest, 0);
  pExpected = Point2d{-0.5, -0.5};
  REQUIRE(equals(pTest, pExpected));

  flipLine(pTest, Line2d{Point2d{-1, 1}, Point2d{1, -1}});
  pExpected = Point2d{0.5, 0.5};
  REQUIRE(equals(pTest, pExpected));
}
