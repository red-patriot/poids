#include "gtest/gtest.h"

import <tuple>;

import poid.util.rational;

using std::tuple;
using poid::util::Rational;

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

//TEST(TestRational, Addition) {
//  Rational a(3, 2), b(4, 9);
//  Rational expected(35, 18);
//
//  Rational actual = a + b;
//
//  EXPECT_EQ(expected, actual);
//}
//
//TEST(TestRational, Subtraction) {
//  Rational a(13, 5), b(3, 6);
//  Rational expected(21, 10);
//
//  Rational actual = a - b;
//
//  EXPECT_EQ(expected, actual);
//}
//
//TEST(TestRational, Multiplication) {
//  Rational a(1, 2), b(3, 5);
//  Rational expected(3, 10);
//
//  Rational actual = a * b;
//
//  EXPECT_EQ(expected, actual);
//}
//
//TEST(TestRational, Division) {
//  Rational a(6, 7), b(4, 3);
//  Rational expected(9, 14);
//
//  Rational actual = a / b;
//
//  EXPECT_EQ(expected, actual);
//}
