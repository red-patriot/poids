#include "gtest/gtest.h"

#include <array>
#include <limits>
#include <tuple>
#include <type_traits>

#include <Unit.h>

using std::tuple;

TEST(TestUnit, DefaultConstructible) {
  EXPECT_TRUE(std::is_default_constructible_v<poids::Unit<poids::metric::TimeD(1)>>);
}

TEST(TestUnit, SimpleInstantiate) {
  double expected = 3.2;
  poids::Unit<poids::metric::LengthD(4)> value{expected};

  EXPECT_DOUBLE_EQ(expected, value.base());
}

TEST(TestUnit, DimensionType) {
  double expected = 3.2;
  poids::Unit<poids::metric::LengthD(4)> value{expected};
  auto dimensionTypeCorrect = std::is_same_v<poids::metric::Dimension, decltype(value)::DimensionType>;

  EXPECT_DOUBLE_EQ(expected, value.base());
  EXPECT_TRUE(dimensionTypeCorrect);
}

TEST(TestUnit, CompoundInstantiate) {
  double expected = -2.4;
  poids::Unit<poids::metric::AmountD(3) - poids::metric::LuminosityD(1) + poids::metric::TemperatureD(3)> value{expected};

  EXPECT_DOUBLE_EQ(expected, value.base());
}

template <poids::metric::Dimension Left, poids::metric::Dimension Right>
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
  poids::Unit<poids::metric::AmountD({2, 3})> a{-5}, b{-5};

  testComparison(a, b, {true, false, false, false, true, true});
}

TEST(TestUnit, TestLessComparisons) {
  poids::Unit<poids::metric::AmountD({2, 3})> a{4.5}, b{5.0};

  testComparison(a, b, {false, true, false, true, false, true});
}

TEST(TestUnit, GreaterComparisons) {
  poids::Unit<poids::metric::AmountD({2, 3})> a{170.54}, b{-65.754};

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
  poids::Unit<poids::metric::LuminosityD(1) + poids::metric::MassD(-1)> a{12};
  poids::Unit<poids::metric::LuminosityD(1) + poids::metric::MassD(-1)> expected{-12};

  auto actual = -a;

  EXPECT_EQ(expected.dimension, actual.dimension);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-10);
}

TEST(TestUnit, ArithmeticAddition) {
  poids::Unit<poids::metric::LengthD(3)> a{-6.7}, b{3};
  poids::Unit<poids::metric::LengthD(3)> expected{-3.7};

  auto actual = a + b;

  EXPECT_EQ(expected.dimension, actual.dimension);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-10);
}

TEST(TestUnit, ArithmeticSubtraction) {
  poids::Unit<poids::metric::CurrentD({-2, 3})> a{18}, b{6.8};
  poids::Unit<poids::metric::CurrentD({-2, 3})> expected{11.2};

  auto actual = a - b;

  EXPECT_EQ(expected.dimension, actual.dimension);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-10);
}

TEST(TestUnit, ArithmeticMultiplication) {
  poids::Unit<poids::metric::LengthD(1)> a(3);
  poids::Unit<poids::metric::TimeD(-1)> b{2.2};
  poids::Unit<poids::metric::LengthD(1) + poids::metric::TimeD(-1)> expected{6.6};

  auto actual = a * b;

  EXPECT_EQ(expected.dimension, actual.dimension);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-10);
}

TEST(TestUnit, ArithmeticDivision) {
  poids::Unit<poids::metric::LengthD(1)> a(14);
  poids::Unit<poids::metric::TimeD(1)> b{2};
  poids::Unit<poids::metric::LengthD(1) - poids::metric::TimeD(1)> expected{7};

  auto actual = a / b;

  EXPECT_EQ(expected.dimension, actual.dimension);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-10);
}

TEST(TestUnit, ArithmeticDoublePostMultiplication) {
  poids::Unit<poids::metric::AmountD(4)> a{3};
  double b{2.6};
  poids::Unit<poids::metric::AmountD(4)> expected{7.8};

  auto actual = a * b;

  EXPECT_EQ(expected.dimension, actual.dimension);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-10);
}

TEST(TestUnit, ArithmeticDoublePreMultiplication) {
  poids::Unit<poids::metric::AmountD(4)> a{3};
  double b{2.6};
  poids::Unit<poids::metric::AmountD(4)> expected{7.8};

  auto actual = b * a;

  EXPECT_EQ(expected.dimension, actual.dimension);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-10);
}

TEST(TestUnit, ArithmeticDoublePreDivision) {
  poids::Unit<poids::metric::TemperatureD(4)> a{5.8};
  double b{1.43};
  poids::Unit<poids::metric::TemperatureD(4)> expected{4.0559440559};

  auto actual = a / b;

  EXPECT_EQ(expected.dimension, actual.dimension);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-10);
}

TEST(TestUnit, ArithmeticDoublePostDivision) {
  poids::Unit<poids::metric::TemperatureD(4)> a{5.8};
  double b{1.43};
  poids::Unit<poids::metric::TemperatureD(-4)> expected{0.2465517241};

  auto actual = b / a;

  EXPECT_EQ(expected.dimension, actual.dimension);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-10);
}

// TODO: Make this work
//TEST(TestUnit, UnitlessConvertsToDouble) {
//  double expected = 5.8;
//  poids::Unit<poids::metric::TemperatureD(0)> a{5.8};
//
//  double actual = a;
//
//  EXPECT_DOUBLE_EQ(expected, actual);
//}

class TestUnitAsConversion : public ::testing::TestWithParam<tuple<double,
                                                                   poids::Unit<poids::metric::LengthD(1)>,
                                                                   poids::Unit<poids::metric::LengthD(1)>>> {
};

TEST_P(TestUnitAsConversion, test) {
  const auto& [expected, value, as] = GetParam();

  auto actual = value.as(as);

  EXPECT_DOUBLE_EQ(expected, actual);
}

INSTANTIATE_TEST_CASE_P(AsConversion, TestUnitAsConversion,
                        ::testing::Values(tuple{125.0,
                                                poids::Unit<poids::metric::LengthD(1)>{12.5},
                                                poids::Unit<poids::metric::LengthD(1)>{0.1}},
                                          tuple{0.0,
                                                poids::Unit<poids::metric::LengthD(1)>{0.0},
                                                poids::Unit<poids::metric::LengthD(1)>{1.0}},
                                          tuple{std::numeric_limits<double>::infinity(),
                                                poids::Unit<poids::metric::LengthD(1)>{12.5},
                                                poids::Unit<poids::metric::LengthD(1)>{0.0}}));
