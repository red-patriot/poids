import "gtest/gtest.h";

import <array>;
import <type_traits>;

import poid.unit;

TEST(TestUnit, DefaultConstructible) {
  EXPECT_TRUE(std::is_default_constructible_v<poid::Unit<poid::TimeD(1)>>);
}

TEST(TestUnit, SimpleInstantiate) {
  double expected = 3.2;
  poid::Unit<poid::LengthD(4)> value{expected};

  EXPECT_DOUBLE_EQ(expected, value.base());
}

TEST(TestUnit, CompoundInstantiate) {
  double expected = -2.4;
  poid::Unit<poid::AmountD(3) - poid::LuminosityD(1) + poid::TemperatureD(3)> value{expected};

  EXPECT_DOUBLE_EQ(expected, value.base());
}

template <poid::Dimension Left, poid::Dimension Right>
inline void testComparison(const poid::Unit<Left>& lhs, const poid::Unit<Right>& rhs,
                           const std::array<bool, 6>& comparisons) {
  EXPECT_EQ(comparisons[0], lhs == rhs);
  EXPECT_EQ(comparisons[1], lhs != rhs);

  EXPECT_EQ(comparisons[2], lhs > rhs);
  EXPECT_EQ(comparisons[3], lhs < rhs);

  EXPECT_EQ(comparisons[4], lhs >= rhs);
  EXPECT_EQ(comparisons[5], lhs <= rhs);
}

TEST(TestUnit, EqualComparisons) {
  poid::Unit<poid::AmountD({2, 3})> a{-5}, b{-5};

  testComparison(a, b, {true, false, false, false, true, true});
}

TEST(TestUnit, TestLessComparisons) {
  poid::Unit<poid::AmountD({2, 3})> a{4.5}, b{5.0};

  testComparison(a, b, {false, true, false, true, false, true});
}

TEST(TestUnit, GreaterComparisons) {
  poid::Unit<poid::AmountD({2, 3})> a{170.54}, b{-65.754};

  testComparison(a, b, {false, true, true, false, true, false});
}

// TODO: Figure out how to make this test work
// TEST(TestUnit, DifferentTypesComparisons) {
//  poid::Unit<poid::TimeD(1)> a{5.67};
//  poid::Unit<poid::LengthD(3)> b{5.67};
//
//  testComparison(a, b, {false, true, false, false, false, false});
//}
