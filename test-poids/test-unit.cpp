#include "gtest/gtest.h"

#include <array>
#include <type_traits>

#include <Unit.h>

TEST(TestUnit, DefaultConstructible) {
  EXPECT_TRUE(std::is_default_constructible_v<poids::Unit<poids::TimeD(1)>>);
}

TEST(TestUnit, SimpleInstantiate) {
  double expected = 3.2;
  poids::Unit<poids::LengthD(4)> value{expected};

  EXPECT_DOUBLE_EQ(expected, value.base());
}

TEST(TestUnit, CompoundInstantiate) {
  double expected = -2.4;
  poids::Unit<poids::AmountD(3) - poids::LuminosityD(1) + poids::TemperatureD(3)> value{expected};

  EXPECT_DOUBLE_EQ(expected, value.base());
}

template <poids::Dimension Left, poids::Dimension Right>
inline void testComparison(const poids::Unit<Left>& lhs, const poids::Unit<Right>& rhs,
                           const std::array<bool, 6>& comparisons) {
  EXPECT_EQ(comparisons[0], lhs == rhs);
  EXPECT_EQ(comparisons[1], lhs != rhs);

  EXPECT_EQ(comparisons[2], lhs > rhs);
  EXPECT_EQ(comparisons[3], lhs < rhs);

  EXPECT_EQ(comparisons[4], lhs >= rhs);
  EXPECT_EQ(comparisons[5], lhs <= rhs);
}

TEST(TestUnit, EqualComparisons) {
  poids::Unit<poids::AmountD({2, 3})> a{-5}, b{-5};

  testComparison(a, b, {true, false, false, false, true, true});
}

TEST(TestUnit, TestLessComparisons) {
  poids::Unit<poids::AmountD({2, 3})> a{4.5}, b{5.0};

  testComparison(a, b, {false, true, false, true, false, true});
}

TEST(TestUnit, GreaterComparisons) {
  poids::Unit<poids::AmountD({2, 3})> a{170.54}, b{-65.754};

  testComparison(a, b, {false, true, true, false, true, false});
}

// TODO: Figure out how to make this test work
// TEST(TestUnit, DifferentTypesComparisons) {
//  poids::Unit<poids::TimeD(1)> a{5.67};
//  poids::Unit<poids::LengthD(3)> b{5.67};
//
//  testComparison(a, b, {false, true, false, false, false, false});
//}

TEST(TestUnit, ArithmeticNegation) {
  poids::Unit<poids::LuminosityD(1) + poids::MassD(-1)> a{12};
  poids::Unit<poids::LuminosityD(1) + poids::MassD(-1)> expected{-12};

  auto actual = -a;

  EXPECT_EQ(expected.dimension, actual.dimension);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-10);
}

TEST(TestUnit, ArithmeticAddition) {
  poids::Unit<poids::LengthD(3)> a{-6.7}, b{3};
  poids::Unit<poids::LengthD(3)> expected{-3.7};

  auto actual = a + b;

  EXPECT_EQ(expected.dimension, actual.dimension);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-10);
}

TEST(TestUnit, ArithmeticSubtraction) {
  poids::Unit<poids::CurrentD({-2, 3})> a{18}, b{6.8};
  poids::Unit<poids::CurrentD({-2, 3})> expected{11.2};

  auto actual = a - b;

  EXPECT_EQ(expected.dimension, actual.dimension);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-10);
}

TEST(TestUnit, ArithmeticMultiplication) {
  poids::Unit<poids::LengthD(1)> a(3);
  poids::Unit<poids::TimeD(-1)> b{2.2};
  poids::Unit<poids::LengthD(1) + poids::TimeD(-1)> expected{6.6};

  auto actual = a * b;

  EXPECT_EQ(expected.dimension, actual.dimension);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-10);
}

TEST(TestUnit, ArithmeticDivision) {
  poids::Unit<poids::LengthD(1)> a(14);
  poids::Unit<poids::TimeD(1)> b{2};
  poids::Unit<poids::LengthD(1) - poids::TimeD(1)> expected{7};

  auto actual = a / b;

  EXPECT_EQ(expected.dimension, actual.dimension);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-10);
}

TEST(TestUnit, ArithmeticDoublePostMultiplication) { 
  poids::Unit<poids::AmountD(4)> a{3};
  double b{2.6};
  poids::Unit<poids::AmountD(4)> expected{7.8};

  auto actual = a * b;

  EXPECT_EQ(expected.dimension, actual.dimension);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-10);
}

TEST(TestUnit, ArithmeticDoublePreMultiplication) {
  poids::Unit<poids::AmountD(4)> a{3};
  double b{2.6};
  poids::Unit<poids::AmountD(4)> expected{7.8};

  auto actual = b * a;

  EXPECT_EQ(expected.dimension, actual.dimension);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-10);
}


TEST(TestUnit, ArithmeticDoublePreDivision) {
  poids::Unit<poids::TemperatureD(4)> a{5.8};
  double b{1.43};
  poids::Unit<poids::TemperatureD(4)> expected{4.0559440559};

  auto actual = a / b;

  EXPECT_EQ(expected.dimension, actual.dimension);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-10);
}

TEST(TestUnit, ArithmeticDoublePostDivision) {
  poids::Unit<poids::TemperatureD(4)> a{5.8};
  double b{1.43};
  poids::Unit<poids::TemperatureD(-4)> expected{0.2465517241};

  auto actual = b / a;

  EXPECT_EQ(expected.dimension, actual.dimension);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-10);
}
