#include <gtest/gtest.h>

#include "poids/core/quantity.hpp"
#include "poids/si/unit.hpp"

TEST(TestBaseQuantity, BaseConstruct) {
  double expected = 3.5;
  auto actual = poids::makeBase<double,
                                si::combine_units_t<si::MassUnit<1>,
                                                    si::LengthUnit<1, 2>>>(3.5);

  EXPECT_DOUBLE_EQ(expected, actual.base());
}

TEST(TestBaseQuantity, DetectUnitlessBaseQuantity) {
  using Unitless = poids::BaseQuantity<double,
                                       si::combine_units_t<si::LengthUnit<0>, si::CurrentUnit<0>>>;
  EXPECT_TRUE(poids::IsUnitless<Unitless>::value);

  using NotUnitless = poids::BaseQuantity<double,
                                          si::combine_units_t<si::LengthUnit<1>, si::TimeUnit<-1>>>;
  EXPECT_FALSE(poids::IsUnitless<NotUnitless>::value);
}

TEST(TestBaseQuantity, ExplicitValueConversion) {
  double expected = 5600.0;

  auto value = poids::makeBase<double,
                               si::combine_units_t<si::LengthUnit<1>>>(5600.0);

  auto actual = value.value();

  EXPECT_NEAR(expected, actual, 1e-6);
}

TEST(TestBaseQuantityComparison, Equals) {
  auto expected = poids::makeBase<double,
                                  si::combine_units_t<si::MassUnit<1>, si::LengthUnit<1, 2>>>(1.0);
  auto actual = poids::makeBase<double,
                                si::combine_units_t<si::MassUnit<1>, si::LengthUnit<1, 2>>>(1.0);

  EXPECT_EQ(expected, actual);
}

TEST(TestBaseQuantityComparison, NotEquals) {
  auto expected = poids::makeBase<double,
                                  si::combine_units_t<si::MassUnit<1>, si::LengthUnit<1, 2>>>(1.5);
  auto actual = poids::makeBase<double,
                                si::combine_units_t<si::MassUnit<1>, si::LengthUnit<1, 2>>>(1.0);

  EXPECT_NE(expected, actual);
}

TEST(TestBaseQuantityComparison, GreaterThan) {
  auto expected = poids::makeBase<double,
                                  si::combine_units_t<si::MassUnit<1>, si::LengthUnit<1, 2>>>(1.5);
  auto actual = poids::makeBase<double,
                                si::combine_units_t<si::MassUnit<1>, si::LengthUnit<1, 2>>>(1.0);

  EXPECT_GT(expected, actual);
}

TEST(TestBaseQuantityComparison, LessThan) {
  auto expected = poids::makeBase<double,
                                  si::combine_units_t<si::MassUnit<1>, si::LengthUnit<1, 2>>>(-100.9);
  auto actual = poids::makeBase<double,
                                si::combine_units_t<si::MassUnit<1>, si::LengthUnit<1, 2>>>(10.0);

  EXPECT_LT(expected, actual);
}

TEST(TestBaseQuantityComparison, GreaterThanOrEqual) {
  auto expected = poids::makeBase<double,
                                  si::combine_units_t<si::MassUnit<1>, si::LengthUnit<1, 2>>>(195.5);
  auto actual = poids::makeBase<double,
                                si::combine_units_t<si::MassUnit<1>, si::LengthUnit<1, 2>>>(153.0);

  EXPECT_GE(expected, actual);
}

TEST(TestBaseQuantityComparison, LessThanOrEqual) {
  auto expected = poids::makeBase<double,
                                  si::combine_units_t<si::MassUnit<1>, si::LengthUnit<1, 2>>>(1.5);
  auto actual = poids::makeBase<double,
                                si::combine_units_t<si::MassUnit<1>, si::LengthUnit<1, 2>>>(2.0);

  EXPECT_LE(expected, actual);
}