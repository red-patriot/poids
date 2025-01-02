#include <gtest/gtest.h>

#include "poids/si/constants.hpp"

using namespace si::base;
using si::units::gram;

TEST(TestSIPrefix, Nano) {
  auto expected = poids::makeBase<si::Length>(1e-9);

  constexpr auto actual = si::prefix::nano(meter);

  EXPECT_NEAR(expected.value(), actual.value(), 1e-15);
}

TEST(TestSIPrefix, Micro) {
  auto expected = poids::makeBase<si::Length>(1e-6);

  constexpr auto actual = si::prefix::micro(meter);

  EXPECT_NEAR(expected.value(), actual.value(), 1e-12);
}

TEST(TestSIPrefix, Milli) {
  auto expected = poids::makeBase<si::Length>(1e-3);

  constexpr auto actual = si::prefix::milli(meter);

  EXPECT_NEAR(expected.value(), actual.value(), 1e-9);
}

TEST(TestSIPrefix, Centi) {
  auto expected = poids::makeBase<si::Length>(1e-2);

  constexpr auto actual = si::prefix::centi(meter);

  EXPECT_NEAR(expected.value(), actual.value(), 1e-8);
}

TEST(TestSIPrefix, Kilo) {
  auto expected = poids::makeBase<si::Mass>(1.0);

  constexpr auto actual = si::prefix::kilo(gram);

  EXPECT_NEAR(expected.value(), actual.value(), 1e-3);
}

TEST(TestSIPrefix, Mega) {
  auto expected = poids::makeBase<si::Mass>(1e3);

  constexpr auto actual = si::prefix::mega(gram);

  EXPECT_NEAR(expected.value(), actual.value(), 1e-3);
}

TEST(TestSIPrefix, Giga) {
  auto expected = poids::makeBase<si::Mass>(1e6);

  constexpr auto actual = si::prefix::giga(gram);

  EXPECT_NEAR(expected.value(), actual.value(), 1.0);
}