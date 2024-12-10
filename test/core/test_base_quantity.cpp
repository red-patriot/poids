#include <gtest/gtest.h>

#include "poids/core/base_quantity.hpp"
#include "poids/kgms/unit.hpp"

TEST(TestBaseQuantity, BaseConstruct) {
  double expected = 3.5;
  auto actual = poids::BaseQuantity<double,
                                    kgms::UnitType<std::ratio<1>,
                                                   std::ratio<1, 2>,
                                                   std::ratio<0>>>::makeBase(3.5);

  EXPECT_DOUBLE_EQ(expected, actual.base());
}

TEST(TestBaseQuantity, DetectUnitlessBaseQuantity) {
  using actual = poids::BaseQuantity<double,
                                     kgms::UnitType<std::ratio<0>,
                                                    std::ratio<0>,
                                                    std::ratio<0>>>;
  EXPECT_TRUE(poids::IsUnitless<actual>::value);
}

TEST(TestBaseQuantity, ExplicitAsConversion) {
  double expected = 5600.0;

  auto value = poids::BaseQuantity<double,
                                   kgms::UnitType<std::ratio<0>,
                                                  std::ratio<1>,
                                                  std::ratio<0>>>::makeBase(5600.0);

  auto actual = value.value();

  EXPECT_NEAR(expected, actual, 1e-6);
}

TEST(TestBaseQuantityComparison, Equals) {
  auto expected = poids::BaseQuantity<double,
                                      kgms::UnitType<std::ratio<1>,
                                                     std::ratio<1, 2>,
                                                     std::ratio<0>>>::makeBase(1.0);
  auto actual = poids::BaseQuantity<double,
                                    kgms::UnitType<std::ratio<1>,
                                                   std::ratio<1, 2>,
                                                   std::ratio<0>>>::makeBase(1.0);

  EXPECT_EQ(expected, actual);
}

TEST(TestBaseQuantityComparison, NotEquals) {
  auto expected = poids::BaseQuantity<double,
                                      kgms::UnitType<std::ratio<1>,
                                                     std::ratio<1, 2>,
                                                     std::ratio<0>>>::makeBase(1.5);
  auto actual = poids::BaseQuantity<double,
                                    kgms::UnitType<std::ratio<1>,
                                                   std::ratio<1, 2>,
                                                   std::ratio<0>>>::makeBase(1.0);

  EXPECT_NE(expected, actual);
}

TEST(TestBaseQuantityComparison, GreaterThan) {
  auto expected = poids::BaseQuantity<double,
                                      kgms::UnitType<std::ratio<1>,
                                                     std::ratio<1, 2>,
                                                     std::ratio<0>>>::makeBase(1.5);
  auto actual = poids::BaseQuantity<double,
                                    kgms::UnitType<std::ratio<1>,
                                                   std::ratio<1, 2>,
                                                   std::ratio<0>>>::makeBase(1.0);

  EXPECT_GT(expected, actual);
}

TEST(TestBaseQuantityComparison, LessThan) {
  auto expected = poids::BaseQuantity<double,
                                      kgms::UnitType<std::ratio<1>,
                                                     std::ratio<1, 2>,
                                                     std::ratio<0>>>::makeBase(-100.9);
  auto actual = poids::BaseQuantity<double,
                                    kgms::UnitType<std::ratio<1>,
                                                   std::ratio<1, 2>,
                                                   std::ratio<0>>>::makeBase(10.0);

  EXPECT_LT(expected, actual);
}

TEST(TestBaseQuantityComparison, GreaterThanOrEqual) {
  auto expected = poids::BaseQuantity<double,
                                      kgms::UnitType<std::ratio<1>,
                                                     std::ratio<1, 2>,
                                                     std::ratio<0>>>::makeBase(195.5);
  auto actual = poids::BaseQuantity<double,
                                    kgms::UnitType<std::ratio<1>,
                                                   std::ratio<1, 2>,
                                                   std::ratio<0>>>::makeBase(153.0);

  EXPECT_GE(expected, actual);
}

TEST(TestBaseQuantityComparison, LessThanOrEqual) {
  auto expected = poids::BaseQuantity<double,
                                      kgms::UnitType<std::ratio<1>,
                                                     std::ratio<1, 2>,
                                                     std::ratio<0>>>::makeBase(1.5);
  auto actual = poids::BaseQuantity<double,
                                    kgms::UnitType<std::ratio<1>,
                                                   std::ratio<1, 2>,
                                                   std::ratio<0>>>::makeBase(2.0);

  EXPECT_LE(expected, actual);
}