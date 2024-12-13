#include <gtest/gtest.h>

#include "poids/kgms/base.hpp"

using namespace kgms::base;

TEST(TestMetricPrefix, Nano) {
  auto expected = poids::makeBase<kgms::Length>(1e-9);

  auto actual = nano(meter);

  EXPECT_NEAR(expected.value(), actual.value(), 1e-15);
}

TEST(TestMetricPrefix, Micro) {
  auto expected = poids::makeBase<kgms::Length>(1e-6);

  constexpr auto actual = micro(meter);

  EXPECT_NEAR(expected.value(), actual.value(), 1e-12);
}

TEST(TestMetricPrefix, Milli) {
  auto expected = poids::makeBase<kgms::Length>(1e-3);

  constexpr auto actual = milli(meter);

  EXPECT_NEAR(expected.value(), actual.value(), 1e-9);
}

TEST(TestMetricPrefix, Centi) {
  auto expected = poids::makeBase<kgms::Length>(1e-2);

  constexpr auto actual = centi(meter);

  EXPECT_NEAR(expected.value(), actual.value(), 1e-8);
}

TEST(TestMetricPrefix, Kilo) {
  auto expected = poids::makeBase<kgms::Mass>(1.0);

  auto actual = kilo(gram);

  EXPECT_NEAR(expected.value(), actual.value(), 1e-3);
}

TEST(TestMetricPrefix, Mega) {
  auto expected = poids::makeBase<kgms::Mass>(1e3);

  auto actual = mega(gram);

  EXPECT_NEAR(expected.value(), actual.value(), 1e-3);
}

TEST(TestMetricPrefix, Giga) {
  auto expected = poids::makeBase<kgms::Mass>(1e6);

  auto actual = giga(gram);

  EXPECT_NEAR(expected.value(), actual.value(), 1.0);
}
