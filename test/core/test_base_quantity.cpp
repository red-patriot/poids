#include <gtest/gtest.h>

#include "poids/core/base_quantity.hpp"
#include "poids/kgms/unit.hpp"

TEST(TestBaseQuantity, BaseConstruct) {
  double expected = 3.5;
  auto actual = poids::makeBase<double,
                                kgms::UnitType<std::ratio<1>,
                                               std::ratio<1, 2>,
                                               std::ratio<0>>>(3.5);

  EXPECT_DOUBLE_EQ(expected, actual.base());
}

TEST(TestBaseQuantity, DetectUnitlessBaseQuantity) {
  using Unitless = poids::BaseQuantity<double,
                                       kgms::UnitType<std::ratio<0>,
                                                      std::ratio<0>,
                                                      std::ratio<0>>>;
  EXPECT_TRUE(poids::IsUnitless<Unitless>::value);

  using NotUnitless = poids::BaseQuantity<double,
                                          kgms::UnitType<std::ratio<0>,
                                                         std::ratio<1>,
                                                         std::ratio<-1>>>;
  EXPECT_FALSE(poids::IsUnitless<NotUnitless>::value);
}

TEST(TestBaseQuantity, ExplicitAsConversion) {
  double expected = 5600.0;

  auto value = poids::makeBase<double,
                               kgms::UnitType<std::ratio<0>,
                                              std::ratio<1>,
                                              std::ratio<0>>>(5600.0);

  auto actual = value.value();

  EXPECT_NEAR(expected, actual, 1e-6);
}

TEST(TestBaseQuantityComparison, Equals) {
  auto expected = poids::makeBase<double,
                                  kgms::UnitType<std::ratio<1>,
                                                 std::ratio<1, 2>,
                                                 std::ratio<0>>>(1.0);
  auto actual = poids::makeBase<double,
                                kgms::UnitType<std::ratio<1>,
                                               std::ratio<1, 2>,
                                               std::ratio<0>>>(1.0);

  EXPECT_EQ(expected, actual);
}

TEST(TestBaseQuantityComparison, NotEquals) {
  auto expected = poids::makeBase<double,
                                  kgms::UnitType<std::ratio<1>,
                                                 std::ratio<1, 2>,
                                                 std::ratio<0>>>(1.5);
  auto actual = poids::makeBase<double,
                                kgms::UnitType<std::ratio<1>,
                                               std::ratio<1, 2>,
                                               std::ratio<0>>>(1.0);

  EXPECT_NE(expected, actual);
}

TEST(TestBaseQuantityComparison, GreaterThan) {
  auto expected = poids::makeBase<double,
                                  kgms::UnitType<std::ratio<1>,
                                                 std::ratio<1, 2>,
                                                 std::ratio<0>>>(1.5);
  auto actual = poids::makeBase<double,
                                kgms::UnitType<std::ratio<1>,
                                               std::ratio<1, 2>,
                                               std::ratio<0>>>(1.0);

  EXPECT_GT(expected, actual);
}

TEST(TestBaseQuantityComparison, LessThan) {
  auto expected = poids::makeBase<double,
                                  kgms::UnitType<std::ratio<1>,
                                                 std::ratio<1, 2>,
                                                 std::ratio<0>>>(-100.9);
  auto actual = poids::makeBase<double,
                                kgms::UnitType<std::ratio<1>,
                                               std::ratio<1, 2>,
                                               std::ratio<0>>>(10.0);

  EXPECT_LT(expected, actual);
}

TEST(TestBaseQuantityComparison, GreaterThanOrEqual) {
  auto expected = poids::makeBase<double,
                                  kgms::UnitType<std::ratio<1>,
                                                 std::ratio<1, 2>,
                                                 std::ratio<0>>>(195.5);
  auto actual = poids::makeBase<double,
                                kgms::UnitType<std::ratio<1>,
                                               std::ratio<1, 2>,
                                               std::ratio<0>>>(153.0);

  EXPECT_GE(expected, actual);
}

TEST(TestBaseQuantityComparison, LessThanOrEqual) {
  auto expected = poids::makeBase<double,
                                  kgms::UnitType<std::ratio<1>,
                                                 std::ratio<1, 2>,
                                                 std::ratio<0>>>(1.5);
  auto actual = poids::makeBase<double,
                                kgms::UnitType<std::ratio<1>,
                                               std::ratio<1, 2>,
                                               std::ratio<0>>>(2.0);

  EXPECT_LE(expected, actual);
}