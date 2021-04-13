#define CATCH_CONFIG_MAIN
#include <catch2/single_include/catch2/catch.hpp>
#include <geometry/basic-math.h>

#include "comparators.h"

constexpr Point2d cPOrig{0, 0};
constexpr Point2d cP1{0.5, 0};
constexpr Point2d cP2{0, 0.5};
constexpr Point2d cP3{0.3, 0.4};
constexpr Point2d cP4{1, 0};

constexpr Vector2d cVNull{0, 0};
constexpr Vector2d cV1{0.5, 0};
constexpr Vector2d cV2{0, 0.5};
constexpr Vector2d cV3{1, 0};
constexpr Vector2d cV4{-0.5, 0};

TEST_CASE("Point subtraction", "[geometry][Point math]") {
  REQUIRE(equals(cP1 - cP1, cVNull));
  REQUIRE(equals(cP1 - cPOrig, cV1));
}

TEST_CASE("Point summation", "[geometry][Point-Vector math]") {
  REQUIRE(equals(cPOrig + cV1, cP1));
  REQUIRE(equals(cP1 + cVNull, cP1));
}

TEST_CASE("Vector multiplication", "[geometry][Vector math]") {
  REQUIRE(equals(cVNull * 2.0f, cVNull));
  REQUIRE(equals(cV1 * 0.0f, cVNull));
  REQUIRE(equals(cV1 * 2.0f, cV3));
}

TEST_CASE("Angle calculation", "[geometry][angle]") {
  REQUIRE(angle(cVNull, cVNull) == 0);
  REQUIRE(abs(angle(cVNull, cV1) - cPi / 4.0f) < cTolerance);

  REQUIRE(angle(cP1, cPOrig, cP1) == 0);
  REQUIRE(abs(angle(cP1, cPOrig, cP2) - cPi / 4.0f) < cTolerance);
}

TEST_CASE("Distance calculation", "[geometry][distance]") {
  REQUIRE(distance(cPOrig, cP1) == 0.5);
  REQUIRE(distance(cPOrig, cP3) == 0.5);
}

TEST_CASE("Mid point calculation", "[geometry][Midpoint]") {
  REQUIRE(equals(mid({cP4, cPOrig}), cP1));
  REQUIRE(equals(mid({cPOrig, cP4}), cP1));
}

TEST_CASE("Cross product", "[geometry][Cross product]") {
  REQUIRE(equals(cV4, crossProduct(cV2)));
}

TEST_CASE("Dot product", "[geometry][Dot product]") {
  REQUIRE(dotProduct(cV1, cV2) == 0.25);
}

TEST_CASE("Coordinate conversion", "[geometry][conversion]") {
  Vector2d cartesian{1, 0};
  udpateCircular(cartesian);
  REQUIRE(cartesian.m == 1);
  REQUIRE(abs(cartesian.a - cPi / 2.0f) < cTolerance);

  Vector2d circular{0, 0, 1, 0};
  udpateCartesian(circular);
  REQUIRE(circular.dx == 1);
  REQUIRE(circular.dy == 0);
}
