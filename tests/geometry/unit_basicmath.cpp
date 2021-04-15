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

TEST_CASE("Vector summation", "[geometry][Vector math]") {
  REQUIRE(equals(cV1 + cV4, cVNull));
  REQUIRE(equals(cVNull + cVNull, cVNull));
}

TEST_CASE("Vector multiplication", "[geometry][Vector math]") {
  REQUIRE(equals(cVNull * 2.0f, cVNull));
  REQUIRE(equals(cV1 * 0.0f, cVNull));
  REQUIRE(equals(cV1 * 2.0f, cV3));
}

TEST_CASE("Angle calculation", "[geometry][angle]") {
  REQUIRE(angle(cVNull, cVNull) == 0);
  REQUIRE(equals(angle(cVNull, cV1), cPi / 4.0f));

  REQUIRE(angle(cP1, cPOrig, cP1) == 0);
  REQUIRE(equals(angle(cP1, cPOrig, cP2), cPi / 4.0f));
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
  Cartesian2d ca{1, 0};
  Circular2d ci = toCircular(ca);
  REQUIRE(ci.m == 1);
  REQUIRE(equals(abs(ci.a), 0));

  Circular2d ci2{1, 0};
  Cartesian2d ca2 = toCartesian(ci2);
  REQUIRE(ca2.x == 1);
  REQUIRE(ca2.y == 0);
}
