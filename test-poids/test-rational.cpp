#include "gtest/gtest.h"

#include <tuple>

#include <util/rational.h>

using poids::util::Rational;
using std::tuple;

class TestRationalConstruct : public ::testing::TestWithParam<tuple<Rational,
                                                                    int, int>> {
};

TEST_P(TestRationalConstruct, InstantiateWithTwoInts) {
  auto [expected, numerator, denominator] = GetParam();

  Rational actual(numerator, denominator);

  EXPECT_EQ(expected, actual);
}

INSTANTIATE_TEST_CASE_P(TestRational, TestRationalConstruct,
                        testing::Values(tuple{Rational{1, 2}, 1, 2},
                                        tuple{Rational{1, 1}, 1, 1},
                                        tuple{Rational{2, 3}, 2, 3},
                                        tuple{Rational{2, 2}, 1, 1}));

TEST(TestRational, ImplicitDenominator) {
  Rational expected(2, 1);

  Rational actual(2);

  EXPECT_EQ(expected, actual);
}

TEST(TestRational, ZeroDemoninator) {
  EXPECT_ANY_THROW(Rational(1, 0));
}

TEST(TestRational, Addition) {
  constexpr Rational a(3, 2), b(4, 9);
  Rational expected(35, 18);

  Rational actual = Rational::add(a, b);

  EXPECT_EQ(expected, actual);
}

TEST(TestRational, Subtraction) {
  constexpr Rational a(13, 5), b(3, 6);
  Rational expected(21, 10);

  Rational actual = Rational::subtract(a, b);

  EXPECT_EQ(expected, actual);
}

TEST(TestRational, Multiplication) {
  constexpr Rational a(1, 2), b(3, 5);
  Rational expected(3, 10);

  Rational actual = Rational::multiply(a, b);

  EXPECT_EQ(expected, actual);
}

TEST(TestRational, Division) {
  constexpr Rational a(6, 7), b(4, 3);
  Rational expected(9, 14);

  Rational actual = Rational::divide(a, b);

  EXPECT_EQ(expected, actual);
}

TEST(TestRational, Negate) {
  constexpr Rational a(5, 3);
  Rational expected(-5, 3);

  Rational actual = Rational::negate(a);
  EXPECT_EQ(expected, actual);
}
