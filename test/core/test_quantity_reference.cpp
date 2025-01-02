#include <gtest/gtest.h>

#include "poids/si.hpp"

using namespace si::base;
using namespace si::prefix;

TEST(TestQuantityReference, ImplicitlyConstructFromQuantity) {
  double expected = 4.5;
  si::Mass quantity = si::Mass::makeFromBaseUnitValue(4.5);

  poids::ReferenceQuantity<double, si::Mass::Unit> actual = quantity;

  EXPECT_DOUBLE_EQ(expected, actual.base());
}

TEST(TestQuantityReference, ReferencesOriginalQuantity) {
  double expected = 10.0;
  si::Mass actual = si::Mass::makeFromBaseUnitValue(4.5);

  poids::ReferenceQuantity<double, si::Mass::Unit> reference = actual;

  reference = expected * kilogram;

  EXPECT_DOUBLE_EQ(expected, actual.as(kilogram));
}

TEST(TestQuantityReference, ConstructFromScalar) {
  double expected = 3.0;
  double actual = 10.0;

  auto reference = poids::ReferenceQuantity<double, si::Length::Unit>::makeReference(actual);

  reference = 3 * meter;

  EXPECT_DOUBLE_EQ(expected, actual);
}

TEST(TestQuantityReference, Copyable) {
  auto quantity = si::Velocity::makeFromBaseUnitValue(1.5);
  poids::ReferenceQuantity<double, si::Velocity::Unit> ref1 = quantity;

  auto ref2 = ref1;

  EXPECT_DOUBLE_EQ(ref1.base(), ref2.base());
}

TEST(TestQuantityReference, ExplicitlyConvertibleToQuantity) {
  double expected = 9.7;
  auto reference = poids::ReferenceQuantity<double, si::Area::Unit>::makeReference(expected);

  si::Area actual{reference};

  EXPECT_DOUBLE_EQ(expected, actual.as(meter * meter));
}

TEST(TestQuantityReference, AsConversion) {
  double expected = 9'700;
  double value = 9.7;
  auto actual = poids::ReferenceQuantity<double, si::Length::Unit>::makeReference(value);

  EXPECT_DOUBLE_EQ(expected, actual.as(milli(meter)));
  EXPECT_DOUBLE_EQ(9.7, value);
}

TEST(TestQuantityReferenceComparison, EqualRefRef) {
  si::Force quantity1 = 5.0 * kilogram * meter / (second * second);
  si::Force quantity2 = 5.0 * kilogram * meter / (second * second);
  poids::ReferenceQuantity ref1 = quantity1;
  poids::ReferenceQuantity ref2 = quantity2;

  EXPECT_EQ(ref1, ref2);
}

TEST(TestQuantityReferenceComparison, NotEqualRefRef) {
  si::Force quantity1 = 5.0 * kilogram * meter / (second * second);
  si::Force quantity2 = 6.0 * kilogram * meter / (second * second);
  poids::ReferenceQuantity ref1 = quantity1;
  poids::ReferenceQuantity ref2 = quantity2;

  EXPECT_NE(ref1, ref2);
}

TEST(TestQuantityReferenceComparison, LessThanRefRef) {
  si::Area quantity1 = 5.0 * meter * meter;
  si::Area quantity2 = 6.0 * meter * meter;
  poids::ReferenceQuantity ref1 = quantity1;
  poids::ReferenceQuantity ref2 = quantity2;

  EXPECT_LT(ref1, ref2);
}

TEST(TestQuantityReferenceComparison, GreaterThanRefRef) {
  si::Angle quantity1 = 20 * radian;
  si::Angle quantity2 = 1 * radian;
  poids::ReferenceQuantity ref1 = quantity1;
  poids::ReferenceQuantity ref2 = quantity2;

  EXPECT_GT(ref1, ref2);
}

TEST(TestQuantityReferenceComparison, GreaterOrEqualRefRef) {
  si::Force quantity1 = 6.0 * kilogram * meter / (second * second);
  si::Force quantity2 = 6.0 * kilogram * meter / (second * second);
  poids::ReferenceQuantity ref1 = quantity1;
  poids::ReferenceQuantity ref2 = quantity2;

  EXPECT_GE(ref1, ref2);
}

TEST(TestQuantityReferenceComparison, LessOrEqualRefRef) {
  si::Force quantity1 = 5.0 * kilogram * meter / (second * second);
  si::Force quantity2 = 6.0 * kilogram * meter / (second * second);
  poids::ReferenceQuantity ref1 = quantity1;
  poids::ReferenceQuantity ref2 = quantity2;

  EXPECT_LE(ref1, ref2);
}

TEST(TestQuantityReferenceComparison, EqualRefQuantity) {
  si::Energy quantity1 = 10.0 * kilogram * meter * meter / (second * second);
  si::Energy quantity2 = 10.0 * kilogram * meter * meter / (second * second);
  poids::ReferenceQuantity ref = quantity1;

  EXPECT_EQ(ref, quantity2);
}

TEST(TestQuantityReferenceComparison, NotEqualRefQuantity) {
  si::Energy quantity1 = 10.0 * kilogram * meter * meter / (second * second);
  si::Energy quantity2 = 11.0 * kilogram * meter * meter / (second * second);
  poids::ReferenceQuantity ref = quantity1;

  EXPECT_NE(ref, quantity2);
}

TEST(TestQuantityReferenceComparison, LessThanRefQuantity) {
  si::Energy quantity1 = 9.5 * kilogram * meter * meter / (second * second);
  si::Energy quantity2 = 10.0 * kilogram * meter * meter / (second * second);
  poids::ReferenceQuantity ref = quantity1;

  EXPECT_LT(ref, quantity2);
}

TEST(TestQuantityReferenceComparison, GreaterThanRefQuantity) {
  si::Energy quantity1 = 12.0 * kilogram * meter * meter / (second * second);
  si::Energy quantity2 = 10.0 * kilogram * meter * meter / (second * second);
  poids::ReferenceQuantity ref = quantity1;

  EXPECT_GT(ref, quantity2);
}

TEST(TestQuantityReferenceComparison, LessOrEqualRefQuantity) {
  si::Energy quantity1 = 10.0 * kilogram * meter * meter / (second * second);
  si::Energy quantity2 = 10.0 * kilogram * meter * meter / (second * second);
  poids::ReferenceQuantity ref = quantity1;

  EXPECT_LE(ref, quantity2);
}

TEST(TestQuantityReferenceComparison, GreaterOrEqualRefQuantity) {
  si::Energy quantity1 = 15.0 * kilogram * meter * meter / (second * second);
  si::Energy quantity2 = 10.0 * kilogram * meter * meter / (second * second);
  poids::ReferenceQuantity ref = quantity1;

  EXPECT_GE(ref, quantity2);
}

TEST(TestQuantityReferenceComparison, EqualQuantityRef) {
  si::Energy quantity1 = 10.0 * kilogram * meter * meter / (second * second);
  si::Energy quantity2 = 10.0 * kilogram * meter * meter / (second * second);
  poids::ReferenceQuantity ref = quantity1;

  EXPECT_EQ(quantity2, ref);
}

TEST(TestQuantityReferenceComparison, NotEqualQuantityRef) {
  si::Energy quantity1 = 10.0 * kilogram * meter * meter / (second * second);
  si::Energy quantity2 = 11.0 * kilogram * meter * meter / (second * second);
  poids::ReferenceQuantity ref = quantity1;

  EXPECT_NE(quantity2, ref);
}

TEST(TestQuantityReferenceComparison, LessThanQuantityRef) {
  si::Energy quantity1 = 9.5 * kilogram * meter * meter / (second * second);
  si::Energy quantity2 = 8.0 * kilogram * meter * meter / (second * second);
  poids::ReferenceQuantity ref = quantity1;

  EXPECT_LT(quantity2, ref);
}

TEST(TestQuantityReferenceComparison, GreaterThanQuantityRefy) {
  si::Energy quantity1 = 10.0 * kilogram * meter * meter / (second * second);
  si::Energy quantity2 = 12.0 * kilogram * meter * meter / (second * second);
  poids::ReferenceQuantity ref = quantity1;

  EXPECT_GT(quantity2, ref);
}

TEST(TestQuantityReferenceComparison, LessOrEqualQuantityRef) {
  si::Energy quantity1 = 10.0 * kilogram * meter * meter / (second * second);
  si::Energy quantity2 = 10.0 * kilogram * meter * meter / (second * second);
  poids::ReferenceQuantity ref = quantity1;

  EXPECT_LE(quantity2, ref);
}

TEST(TestQuantityReferenceComparison, GreaterOrEqualQuantityRef) {
  si::Energy quantity1 = 10.0 * kilogram * meter * meter / (second * second);
  si::Energy quantity2 = 15.0 * kilogram * meter * meter / (second * second);
  poids::ReferenceQuantity ref = quantity1;

  EXPECT_GE(quantity2, ref);
}

TEST(TestQuantityReferenceArithmetic, AddRefRef) {
  si::Length expected = 0.055 * meter;
  si::Length quantity1 = 5 * centi(meter);
  si::Length quantity2 = 5 * milli(meter);

  poids::ReferenceQuantity ref1 = quantity1;
  poids::ReferenceQuantity ref2 = quantity2;

  auto actual = ref1 + ref2;

  EXPECT_TRUE((std::is_same_v<decltype(expected), decltype(actual)>));
  EXPECT_NEAR(expected.as(meter), actual.as(meter), 1e-6);
}

TEST(TestQuantityReferenceArithmetic, AddQuantityRef) {
  si::Time expected = 10 * second;
  si::Time quantity1 = 5 * second;
  si::Time quantity2 = 5 * second;

  poids::ReferenceQuantity ref1 = quantity1;

  auto actual = quantity2 + ref1;

  EXPECT_TRUE((std::is_same_v<decltype(expected), decltype(actual)>));
  EXPECT_NEAR(expected.as(second), actual.as(second), 1e-6);
}

TEST(TestQuantityReferenceArithmetic, AddRefQuantity) {
  si::Length expected = 17 * meter;
  si::Length quantity1 = 5 * meter;
  si::Length quantity2 = 12 * meter;

  poids::ReferenceQuantity ref2 = quantity2;

  auto actual = quantity1 + ref2;

  EXPECT_TRUE((std::is_same_v<decltype(expected), decltype(actual)>));
  EXPECT_NEAR(expected.as(meter), actual.as(meter), 1e-6);
}

TEST(TestQuantityReferenceArithmetic, SubtractRefRef) {
  si::Length expected = 0.045 * meter;
  si::Length quantity1 = 5 * centi(meter);
  si::Length quantity2 = 5 * milli(meter);

  poids::ReferenceQuantity ref1 = quantity1;
  poids::ReferenceQuantity ref2 = quantity2;

  auto actual = ref1 - ref2;

  EXPECT_TRUE((std::is_same_v<decltype(expected), decltype(actual)>));
  EXPECT_NEAR(expected.as(meter), actual.as(meter), 1e-6);
}

TEST(TestQuantityReferenceArithmetic, SubtractQuantityRef) {
  si::Time expected = 0 * second;
  si::Time quantity1 = 5 * second;
  si::Time quantity2 = 5 * second;

  poids::ReferenceQuantity ref1 = quantity1;

  auto actual = quantity2 - ref1;

  EXPECT_TRUE((std::is_same_v<decltype(expected), decltype(actual)>));
  EXPECT_NEAR(expected.as(second), actual.as(second), 1e-6);
}

TEST(TestQuantityReferenceArithmetic, SubtractRefQuantity) {
  si::Length expected = 7 * meter;
  si::Length quantity1 = 12 * meter;
  si::Length quantity2 = 5 * meter;

  poids::ReferenceQuantity ref2 = quantity2;

  auto actual = quantity1 - ref2;

  EXPECT_TRUE((std::is_same_v<decltype(expected), decltype(actual)>));
  EXPECT_NEAR(expected.as(meter), actual.as(meter), 1e-6);
}

TEST(TestQuantityReference, IsCopyable) {
  EXPECT_TRUE((std::is_copy_constructible_v<poids::ReferenceQuantity<double, si::Area::Unit>>));
}

TEST(TestQuantityReference, IsCopyAssignable) {
  EXPECT_TRUE((std::is_copy_assignable_v<poids::ReferenceQuantity<double, si::Area::Unit>>));
}
