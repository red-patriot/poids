#include <gtest/gtest.h>

#include "poids/core/quantity.hpp"
#include "poids/core/reference.hpp"
#include "poids/kgms.hpp"

using namespace kgms::base;

TEST(TestQuantityReference, ImplicitlyConstructFromQuantity) {
  double expected = 4.5;
  kgms::Mass quantity = kgms::Mass::makeFromBaseUnitValue(4.5);

  poids::ReferenceQuantity<double, kgms::units::MassUnit> actual = quantity;

  EXPECT_DOUBLE_EQ(expected, actual.base());
}

TEST(TestQuantityReference, ReferencesOriginalQuantity) {
  double expected = 10.0;
  kgms::Mass actual = kgms::Mass::makeFromBaseUnitValue(4.5);

  poids::ReferenceQuantity<double, kgms::units::MassUnit> reference = actual;

  reference = expected * kilogram;

  EXPECT_DOUBLE_EQ(expected, actual.as(kilogram));
}

TEST(TestQuantityReference, ConstructFromScalar) {
  double expected = 3.0;
  double actual = 10.0;

  auto reference = poids::ReferenceQuantity<double, kgms::units::LengthUnit>::makeReference(actual);

  reference = 3 * meter;

  EXPECT_DOUBLE_EQ(expected, actual);
}

TEST(TestQuantityReference, Copyable) {
  auto quantity = kgms::Velocity::makeFromBaseUnitValue(1.5);
  poids::ReferenceQuantity<double, kgms::units::VelocityUnit> ref1 = quantity;

  auto ref2 = ref1;

  EXPECT_DOUBLE_EQ(ref1.base(), ref2.base());
}

TEST(TestQuantityReference, ExplicitlyConvertibleToQuantity) {
  double expected = 9.7;
  auto reference = poids::ReferenceQuantity<double, kgms::units::AreaUnit>::makeReference(expected);

  kgms::Area actual{reference};

  EXPECT_DOUBLE_EQ(expected, actual.as(meter * meter));
}

TEST(TestQuantityReference, AsConversion) {
  double expected = 9'700;
  double value = 9.7;
  auto actual = poids::ReferenceQuantity<double, kgms::units::LengthUnit>::makeReference(value);

  EXPECT_DOUBLE_EQ(expected, actual.as(milli(meter)));
  EXPECT_DOUBLE_EQ(9.7, value);
}

TEST(TestQuantityReferenceComparison, EqualRefRef) {
  kgms::Force quantity1 = 5.0 * kilogram * meter / (second * second);
  kgms::Force quantity2 = 5.0 * kilogram * meter / (second * second);
  poids::ReferenceQuantity ref1 = quantity1;
  poids::ReferenceQuantity ref2 = quantity2;

  EXPECT_EQ(ref1, ref2);
}

TEST(TestQuantityReferenceComparison, NotEqualRefRef) {
  kgms::Force quantity1 = 5.0 * kilogram * meter / (second * second);
  kgms::Force quantity2 = 6.0 * kilogram * meter / (second * second);
  poids::ReferenceQuantity ref1 = quantity1;
  poids::ReferenceQuantity ref2 = quantity2;

  EXPECT_NE(ref1, ref2);
}

TEST(TestQuantityReferenceComparison, LessThanRefRef) {
  kgms::Area quantity1 = 5.0 * meter * meter;
  kgms::Area quantity2 = 6.0 * meter * meter;
  poids::ReferenceQuantity ref1 = quantity1;
  poids::ReferenceQuantity ref2 = quantity2;

  EXPECT_LT(ref1, ref2);
}

TEST(TestQuantityReferenceComparison, GreaterThanRefRef) {
  kgms::Angle quantity1 = 2 * radian;
  kgms::Angle quantity2 = 100 * degree;
  poids::ReferenceQuantity ref1 = quantity1;
  poids::ReferenceQuantity ref2 = quantity2;

  EXPECT_GT(ref1, ref2);
}

TEST(TestQuantityReferenceComparison, GreaterOrEqualRefRef) {
  kgms::Force quantity1 = 6.0 * kilogram * meter / (second * second);
  kgms::Force quantity2 = 6.0 * kilogram * meter / (second * second);
  poids::ReferenceQuantity ref1 = quantity1;
  poids::ReferenceQuantity ref2 = quantity2;

  EXPECT_GE(ref1, ref2);
}

TEST(TestQuantityReferenceComparison, LessOrEqualRefRef) {
  kgms::Force quantity1 = 5.0 * kilogram * meter / (second * second);
  kgms::Force quantity2 = 6.0 * kilogram * meter / (second * second);
  poids::ReferenceQuantity ref1 = quantity1;
  poids::ReferenceQuantity ref2 = quantity2;

  EXPECT_LE(ref1, ref2);
}

TEST(TestQuantityReferenceComparison, EqualRefQuantity) {
  kgms::Energy quantity1 = 10.0 * kilogram * meter * meter / (second * second);
  kgms::Energy quantity2 = 10.0 * kilogram * meter * meter / (second * second);
  poids::ReferenceQuantity ref = quantity1;

  EXPECT_EQ(ref, quantity2);
}

TEST(TestQuantityReferenceComparison, NotEqualRefQuantity) {
  kgms::Energy quantity1 = 10.0 * kilogram * meter * meter / (second * second);
  kgms::Energy quantity2 = 11.0 * kilogram * meter * meter / (second * second);
  poids::ReferenceQuantity ref = quantity1;

  EXPECT_NE(ref, quantity2);
}

TEST(TestQuantityReferenceComparison, LessThanRefQuantity) {
  kgms::Energy quantity1 = 9.5 * kilogram * meter * meter / (second * second);
  kgms::Energy quantity2 = 10.0 * kilogram * meter * meter / (second * second);
  poids::ReferenceQuantity ref = quantity1;

  EXPECT_LT(ref, quantity2);
}

TEST(TestQuantityReferenceComparison, GreaterThanRefQuantity) {
  kgms::Energy quantity1 = 12.0 * kilogram * meter * meter / (second * second);
  kgms::Energy quantity2 = 10.0 * kilogram * meter * meter / (second * second);
  poids::ReferenceQuantity ref = quantity1;

  EXPECT_GT(ref, quantity2);
}

TEST(TestQuantityReferenceComparison, LessOrEqualRefQuantity) {
  kgms::Energy quantity1 = 10.0 * kilogram * meter * meter / (second * second);
  kgms::Energy quantity2 = 10.0 * kilogram * meter * meter / (second * second);
  poids::ReferenceQuantity ref = quantity1;

  EXPECT_LE(ref, quantity2);
}

TEST(TestQuantityReferenceComparison, GreaterOrEqualRefQuantity) {
  kgms::Energy quantity1 = 15.0 * kilogram * meter * meter / (second * second);
  kgms::Energy quantity2 = 10.0 * kilogram * meter * meter / (second * second);
  poids::ReferenceQuantity ref = quantity1;

  EXPECT_GE(ref, quantity2);
}

TEST(TestQuantityReferenceComparison, EqualQuantityRef) {
  kgms::Energy quantity1 = 10.0 * kilogram * meter * meter / (second * second);
  kgms::Energy quantity2 = 10.0 * kilogram * meter * meter / (second * second);
  poids::ReferenceQuantity ref = quantity1;

  EXPECT_EQ(quantity2, ref);
}

TEST(TestQuantityReferenceComparison, NotEqualQuantityRef) {
  kgms::Energy quantity1 = 10.0 * kilogram * meter * meter / (second * second);
  kgms::Energy quantity2 = 11.0 * kilogram * meter * meter / (second * second);
  poids::ReferenceQuantity ref = quantity1;

  EXPECT_NE(quantity2, ref);
}

TEST(TestQuantityReferenceComparison, LessThanQuantityRef) {
  kgms::Energy quantity1 = 9.5 * kilogram * meter * meter / (second * second);
  kgms::Energy quantity2 = 8.0 * kilogram * meter * meter / (second * second);
  poids::ReferenceQuantity ref = quantity1;

  EXPECT_LT(quantity2, ref);
}

TEST(TestQuantityReferenceComparison, GreaterThanQuantityRefy) {
  kgms::Energy quantity1 = 10.0 * kilogram * meter * meter / (second * second);
  kgms::Energy quantity2 = 12.0 * kilogram * meter * meter / (second * second);
  poids::ReferenceQuantity ref = quantity1;

  EXPECT_GT(quantity2, ref);
}

TEST(TestQuantityReferenceComparison, LessOrEqualQuantityRef) {
  kgms::Energy quantity1 = 10.0 * kilogram * meter * meter / (second * second);
  kgms::Energy quantity2 = 10.0 * kilogram * meter * meter / (second * second);
  poids::ReferenceQuantity ref = quantity1;

  EXPECT_LE(quantity2, ref);
}

TEST(TestQuantityReferenceComparison, GreaterOrEqualQuantityRef) {
  kgms::Energy quantity1 = 10.0 * kilogram * meter * meter / (second * second);
  kgms::Energy quantity2 = 15.0 * kilogram * meter * meter / (second * second);
  poids::ReferenceQuantity ref = quantity1;

  EXPECT_GE(quantity2, ref);
}

TEST(TestQuantityReferenceArithmetic, AddRefRef) {
  kgms::Length expected = 0.055 * meter;
  kgms::Length quantity1 = 5 * centi(meter);
  kgms::Length quantity2 = 5 * milli(meter);

  poids::ReferenceQuantity ref1 = quantity1;
  poids::ReferenceQuantity ref2 = quantity2;

  auto actual = ref1 + ref2;

  EXPECT_TRUE((std::is_same_v<decltype(expected), decltype(actual)>));
  EXPECT_NEAR(expected.as(meter), actual.as(meter), 1e-6);
}

TEST(TestQuantityReferenceArithmetic, AddQuantityRef) {
  kgms::Time expected = 10 * second;
  kgms::Time quantity1 = 5 * second;
  kgms::Time quantity2 = 5 * second;

  poids::ReferenceQuantity ref1 = quantity1;

  auto actual = quantity2 + ref1;

  EXPECT_TRUE((std::is_same_v<decltype(expected), decltype(actual)>));
  EXPECT_NEAR(expected.as(second), actual.as(second), 1e-6);
}

TEST(TestQuantityReferenceArithmetic, AddRefQuantity) {
  kgms::Length expected = 17 * meter;
  kgms::Length quantity1 = 5 * meter;
  kgms::Length quantity2 = 12 * meter;

  poids::ReferenceQuantity ref2 = quantity2;

  auto actual = quantity1 + ref2;

  EXPECT_TRUE((std::is_same_v<decltype(expected), decltype(actual)>));
  EXPECT_NEAR(expected.as(meter), actual.as(meter), 1e-6);
}

TEST(TestQuantityReferenceArithmetic, SubtractRefRef) {
  kgms::Length expected = 0.045 * (meter);
  kgms::Length quantity1 = 5 * centi(meter);
  kgms::Length quantity2 = 5 * milli(meter);

  poids::ReferenceQuantity ref1 = quantity1;
  poids::ReferenceQuantity ref2 = quantity2;

  auto actual = ref1 - ref2;

  EXPECT_TRUE((std::is_same_v<decltype(expected), decltype(actual)>));
  EXPECT_NEAR(expected.as(meter), actual.as(meter), 1e-6);
}

TEST(TestQuantityReferenceArithmetic, SubtractQuantityRef) {
  kgms::Time expected = 0 * second;
  kgms::Time quantity1 = 5 * second;
  kgms::Time quantity2 = 5 * second;

  poids::ReferenceQuantity ref1 = quantity1;

  auto actual = quantity2 - ref1;

  EXPECT_TRUE((std::is_same_v<decltype(expected), decltype(actual)>));
  EXPECT_NEAR(expected.as(second), actual.as(second), 1e-6);
}

TEST(TestQuantityReferenceArithmetic, SubtractRefQuantity) {
  kgms::Length expected = 7 * meter;
  kgms::Length quantity1 = 12 * meter;
  kgms::Length quantity2 = 5 * meter;

  poids::ReferenceQuantity ref2 = quantity2;

  auto actual = quantity1 - ref2;

  EXPECT_TRUE((std::is_same_v<decltype(expected), decltype(actual)>));
  EXPECT_NEAR(expected.as(meter), actual.as(meter), 1e-6);
}