#include <gtest/gtest.h>

#include "poids/core/quantity.hpp"
#include "poids/kgms/unit.hpp"

TEST(TestQuantity, BaseConstruct) {
  double expected = 3.5;
  auto actual = poids::Quantity<double,
                                kgms::UnitType<std::ratio<1>,
                                               std::ratio<1, 2>,
                                               std::ratio<0>>>::makeFromBaseUnitValue(3.5);

  EXPECT_DOUBLE_EQ(expected, actual.base());
}

TEST(TestQuantity, DetectUnitlessQuantity) {
  using actual = poids::Quantity<double,
                                 kgms::UnitType<std::ratio<0>,
                                                std::ratio<0>,
                                                std::ratio<0>>>;
  EXPECT_TRUE(poids::IsUnitless<actual>::value);
}

TEST(TestQuantity, ImplicitFromScalarIfUnitless) {
  poids::Quantity<double,
                  kgms::UnitType<std::ratio<0>,
                                 std::ratio<0>,
                                 std::ratio<0>>>
      actual = 5.6;

  EXPECT_DOUBLE_EQ(5.6, actual.base());
}

TEST(TestQuantity, ExplicitAsConversion) {
  double expected = 5600.0;

  auto millimeters = poids::BaseQuantity<double,
                                         kgms::UnitType<std::ratio<0>,
                                                        std::ratio<1>,
                                                        std::ratio<0>>>::makeBase(0.001);

  auto value = poids::Quantity<double,
                               kgms::UnitType<std::ratio<0>,
                                              std::ratio<1>,
                                              std::ratio<0>>>::makeFromBaseUnitValue(5.6);

  auto actual = value.as(millimeters);

  EXPECT_NEAR(expected, actual, 1e-6);
}

TEST(TestQuantityComparison, Equals) {
  auto expected = poids::Quantity<double,
                                  kgms::UnitType<std::ratio<1>,
                                                 std::ratio<1, 2>,
                                                 std::ratio<0>>>::makeFromBaseUnitValue(1.0);
  auto actual = poids::Quantity<double,
                                kgms::UnitType<std::ratio<1>,
                                               std::ratio<1, 2>,
                                               std::ratio<0>>>::makeFromBaseUnitValue(1.0);

  EXPECT_EQ(expected, actual);
}

TEST(TestQuantityComparison, NotEquals) {
  auto expected = poids::Quantity<double,
                                  kgms::UnitType<std::ratio<1>,
                                                 std::ratio<1, 2>,
                                                 std::ratio<0>>>::makeFromBaseUnitValue(1.5);
  auto actual = poids::Quantity<double,
                                kgms::UnitType<std::ratio<1>,
                                               std::ratio<1, 2>,
                                               std::ratio<0>>>::makeFromBaseUnitValue(1.0);

  EXPECT_NE(expected, actual);
}

TEST(TestQuantityComparison, GreaterThan) {
  auto expected = poids::Quantity<double,
                                  kgms::UnitType<std::ratio<1>,
                                                 std::ratio<1, 2>,
                                                 std::ratio<0>>>::makeFromBaseUnitValue(1.5);
  auto actual = poids::Quantity<double,
                                kgms::UnitType<std::ratio<1>,
                                               std::ratio<1, 2>,
                                               std::ratio<0>>>::makeFromBaseUnitValue(1.0);

  EXPECT_GT(expected, actual);
}

TEST(TestQuantityComparison, LessThan) {
  auto expected = poids::Quantity<double,
                                  kgms::UnitType<std::ratio<1>,
                                                 std::ratio<1, 2>,
                                                 std::ratio<0>>>::makeFromBaseUnitValue(-100.9);
  auto actual = poids::Quantity<double,
                                kgms::UnitType<std::ratio<1>,
                                               std::ratio<1, 2>,
                                               std::ratio<0>>>::makeFromBaseUnitValue(10.0);

  EXPECT_LT(expected, actual);
}

TEST(TestQuantityComparison, GreaterThanOrEqual) {
  auto expected = poids::Quantity<double,
                                  kgms::UnitType<std::ratio<1>,
                                                 std::ratio<1, 2>,
                                                 std::ratio<0>>>::makeFromBaseUnitValue(195.5);
  auto actual = poids::Quantity<double,
                                kgms::UnitType<std::ratio<1>,
                                               std::ratio<1, 2>,
                                               std::ratio<0>>>::makeFromBaseUnitValue(153.0);

  EXPECT_GE(expected, actual);
}

TEST(TestQuantityComparison, LessThanOrEqual) {
  auto expected = poids::Quantity<double,
                                  kgms::UnitType<std::ratio<1>,
                                                 std::ratio<1, 2>,
                                                 std::ratio<0>>>::makeFromBaseUnitValue(1.5);
  auto actual = poids::Quantity<double,
                                kgms::UnitType<std::ratio<1>,
                                               std::ratio<1, 2>,
                                               std::ratio<0>>>::makeFromBaseUnitValue(2.0);

  EXPECT_LE(expected, actual);
}
