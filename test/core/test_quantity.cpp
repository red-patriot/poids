#include <gtest/gtest.h>

#include "poids/core/quantity.hpp"
#include "poids/si/unit.hpp"

TEST(TestQuantity, BaseConstruct) {
  double expected = 3.5;
  auto actual = poids::Quantity<double,
                                si::combine_units_t<si::MassUnit<1>, si::LengthUnit<1, 2>>>::makeFromBaseUnitValue(3.5);

  EXPECT_DOUBLE_EQ(expected, actual.base());
}

TEST(TestQuantity, DetectUnitlessQuantity) {
  using Unitless = poids::Quantity<double,
                                   si::UnitlessUnit>;
  EXPECT_TRUE(poids::IsUnitless_v<Unitless>);

  using NotUnitless = poids::Quantity<double,
                                      si::combine_units_t<si::MassUnit<1>, si::LengthUnit<1>, si::TimeUnit<-2>>>;
  EXPECT_FALSE(poids::IsUnitless_v<NotUnitless>);
}

TEST(TestQuantity, DetectBaseQuantity) {
  using NotBase = poids::Quantity<long double,
                                  si::combine_units_t<si::LengthUnit<2, 3>, si::TimeUnit<4>>>;

  EXPECT_FALSE(poids::IsBaseUnit_v<NotBase>);

  using Base = poids::Quantity<long double,
                               si::combine_units_t<si::MassUnit<1>, si::LengthUnit<-5>, si::TimeUnit<4>>,
                               true>;

  EXPECT_TRUE(poids::IsBaseUnit_v<Base>);
}

TEST(TestQuantity, ConstructFromScalarIfUnitless) {
  poids::Quantity<double,
                  si::UnitlessUnit>
      actual{5.6};

  EXPECT_DOUBLE_EQ(5.6, actual.base());
}

TEST(TestQuantity, ExplicitAsConversion) {
  double expected = 5600.0;

  auto millimeters = poids::makeBase<double,
                                     si::LengthUnit<1>>(0.001);

  auto value = poids::Quantity<double,
                               si::LengthUnit<1>>::makeFromBaseUnitValue(5.6);

  auto actual = value.as(millimeters);

  EXPECT_NEAR(expected, actual, 1e-6);
}

TEST(TestQuantity, ImplicitlyConstructibleFromBaseQuantity) {
  auto meters = poids::makeBase<double,
                                si::combine_units_t<si::MassUnit<0>, si::LengthUnit<1>, si::TimeUnit<0>>>(1.0);

  poids::Quantity actual{meters};

  EXPECT_NEAR(1.0, actual.as(meters), 1e-6);
}

TEST(TestQuantityComparison, Equals) {
  auto expected = poids::Quantity<double,
                                  si::combine_units_t<si::MassUnit<1>, si::LengthUnit<1, 2>>>::makeFromBaseUnitValue(1.0);
  auto actual = poids::Quantity<double,
                                si::combine_units_t<si::MassUnit<1>, si::LengthUnit<1, 2>>>::makeFromBaseUnitValue(1.0);

  EXPECT_EQ(expected, actual);
}

TEST(TestQuantityComparison, NotEquals) {
  auto expected = poids::Quantity<double,
                                  si::combine_units_t<si::MassUnit<1>, si::LengthUnit<1, 2>>>::makeFromBaseUnitValue(1.5);
  auto actual = poids::Quantity<double,
                                si::combine_units_t<si::MassUnit<1>, si::LengthUnit<1, 2>>>::makeFromBaseUnitValue(1.0);

  EXPECT_NE(expected, actual);
}

TEST(TestQuantityComparison, GreaterThan) {
  auto expected = poids::Quantity<double,
                                  si::combine_units_t<si::MassUnit<1>, si::LengthUnit<1, 2>>>::makeFromBaseUnitValue(1.5);
  auto actual = poids::Quantity<double,
                                si::combine_units_t<si::MassUnit<1>, si::LengthUnit<1, 2>>>::makeFromBaseUnitValue(1.0);

  EXPECT_GT(expected, actual);
}

TEST(TestQuantityComparison, LessThan) {
  auto expected = poids::Quantity<double,
                                  si::combine_units_t<si::MassUnit<1>, si::LengthUnit<1, 2>>>::makeFromBaseUnitValue(-100.9);
  auto actual = poids::Quantity<double,
                                si::combine_units_t<si::MassUnit<1>, si::LengthUnit<1, 2>>>::makeFromBaseUnitValue(10.0);

  EXPECT_LT(expected, actual);
}

TEST(TestQuantityComparison, GreaterThanOrEqual) {
  auto expected = poids::Quantity<double,
                                  si::combine_units_t<si::MassUnit<1>, si::LengthUnit<1, 2>>>::makeFromBaseUnitValue(195.5);
  auto actual = poids::Quantity<double,
                                si::combine_units_t<si::MassUnit<1>, si::LengthUnit<1, 2>>>::makeFromBaseUnitValue(153.0);

  EXPECT_GE(expected, actual);
}

TEST(TestQuantityComparison, LessThanOrEqual) {
  auto expected = poids::Quantity<double,
                                  si::combine_units_t<si::MassUnit<1>, si::LengthUnit<1, 2>>>::makeFromBaseUnitValue(1.5);
  auto actual = poids::Quantity<double,
                                si::combine_units_t<si::MassUnit<1>, si::LengthUnit<1, 2>>>::makeFromBaseUnitValue(2.0);

  EXPECT_LE(expected, actual);
}
