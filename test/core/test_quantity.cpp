#include <gtest/gtest.h>

#include "poids/core/quantity.hpp"
#include "poids/kgms/unit.hpp"

TEST(TestQuantity, BaseConstruct) {
  double expected = 3.5;
  auto actual = poids::Quantity<double,
                                kgms::UnitType<std::ratio<1>,
                                               std::ratio<1, 2>,
                                               std::ratio<0>>>::makeBase(3.5);

  EXPECT_DOUBLE_EQ(expected, actual.base());
}

TEST(TestQuantityComparison, Equals) {
  auto expected = poids::Quantity<double,
                                  kgms::UnitType<std::ratio<1>,
                                                 std::ratio<1, 2>,
                                                 std::ratio<0>>>::makeBase(1.0);
  auto actual = poids::Quantity<double,
                                kgms::UnitType<std::ratio<1>,
                                               std::ratio<1, 2>,
                                               std::ratio<0>>>::makeBase(1.0);

  EXPECT_EQ(expected, actual);
}

TEST(TestQuantityComparison, NotEquals) {
  auto expected = poids::Quantity<double,
                                  kgms::UnitType<std::ratio<1>,
                                                 std::ratio<1, 2>,
                                                 std::ratio<0>>>::makeBase(1.5);
  auto actual = poids::Quantity<double,
                                kgms::UnitType<std::ratio<1>,
                                               std::ratio<1, 2>,
                                               std::ratio<0>>>::makeBase(1.0);

  EXPECT_NE(expected, actual);
}

TEST(TestQuantityComparison, GreaterThan) {
  auto expected = poids::Quantity<double,
                                  kgms::UnitType<std::ratio<1>,
                                                 std::ratio<1, 2>,
                                                 std::ratio<0>>>::makeBase(1.5);
  auto actual = poids::Quantity<double,
                                kgms::UnitType<std::ratio<1>,
                                               std::ratio<1, 2>,
                                               std::ratio<0>>>::makeBase(1.0);

  EXPECT_GT(expected, actual);
}

TEST(TestQuantityComparison, LessThan) {
  auto expected = poids::Quantity<double,
                                  kgms::UnitType<std::ratio<1>,
                                                 std::ratio<1, 2>,
                                                 std::ratio<0>>>::makeBase(-100.9);
  auto actual = poids::Quantity<double,
                                kgms::UnitType<std::ratio<1>,
                                               std::ratio<1, 2>,
                                               std::ratio<0>>>::makeBase(10.0);

  EXPECT_LT(expected, actual);
}

TEST(TestQuantityComparison, GreaterThanOrEqual) {
  auto expected = poids::Quantity<double,
                                  kgms::UnitType<std::ratio<1>,
                                                 std::ratio<1, 2>,
                                                 std::ratio<0>>>::makeBase(195.5);
  auto actual = poids::Quantity<double,
                                kgms::UnitType<std::ratio<1>,
                                               std::ratio<1, 2>,
                                               std::ratio<0>>>::makeBase(153.0);

  EXPECT_GE(expected, actual);
}

TEST(TestQuantityComparison, LessThanOrEqual) {
  auto expected = poids::Quantity<double,
                                  kgms::UnitType<std::ratio<1>,
                                                 std::ratio<1, 2>,
                                                 std::ratio<0>>>::makeBase(1.5);
  auto actual = poids::Quantity<double,
                                kgms::UnitType<std::ratio<1>,
                                               std::ratio<1, 2>,
                                               std::ratio<0>>>::makeBase(2.0);

  EXPECT_LE(expected, actual);
}


