#include <gtest/gtest.h>

#include <type_traits>

#include "poids/kgms/base.hpp"

TEST(TestLongDoubleScalarSupport, DefineConstant) {
  long double expected = 5.67;

  auto actual = poids::makeBase<kgms::Area_l>(5.67);

  EXPECT_TRUE((std::is_same_v<long double, decltype(actual)::Scalar>));
  EXPECT_EQ(expected, actual.value());
}

TEST(TestLongDoubleScalarSupport, AddQuantityQuantity) {
  auto expected = kgms::Acceleration_l::makeFromBaseUnitValue(-4.5);

  auto a = kgms::Acceleration_l::makeFromBaseUnitValue(-18.0);
  auto b = kgms::Acceleration_l::makeFromBaseUnitValue(13.5);

  auto actual = a + b;

  EXPECT_TRUE((std::is_same_v<kgms::Acceleration_l, decltype(actual)>));
  EXPECT_NEAR(expected.base(), actual.base(), 1e-6);
}

TEST(TestLongDoubleScalarSupport, SubtractQuantityQuantity) {
  auto expected = kgms::Force_l::makeFromBaseUnitValue(-5.5);

  auto a = kgms::Force_l::makeFromBaseUnitValue(8.0);
  auto b = kgms::Force_l::makeFromBaseUnitValue(13.5);

  auto actual = a - b;

  EXPECT_TRUE((std::is_same_v<kgms::Force_l, decltype(actual)>));
  EXPECT_NEAR(expected.base(), actual.base(), 1e-6);
}
