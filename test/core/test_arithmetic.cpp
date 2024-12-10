#include <gtest/gtest.h>

#include <type_traits>

#include "poids/kgms/types.hpp"

TEST(TestQuantityArithmetic, Add) {
  kgms::Mass expected = kgms::Mass::makeFromBaseUnitValue(4.53);

  kgms::Mass a = kgms::Mass::makeFromBaseUnitValue(0.54);
  kgms::Mass b = kgms::Mass::makeFromBaseUnitValue(3.99);

  auto actual = a + b;

  EXPECT_NEAR(expected.base(), actual.base(), 1e-6);
}

TEST(TestQuantityArithmetic, Subtract) {
  kgms::Time expected = kgms::Time::makeFromBaseUnitValue(60.0);

  kgms::Time a = kgms::Time::makeFromBaseUnitValue(150.0);
  kgms::Time b = kgms::Time::makeFromBaseUnitValue(90.0);

  auto actual = a - b;

  EXPECT_NEAR(expected.base(), actual.base(), 1e-6);
}