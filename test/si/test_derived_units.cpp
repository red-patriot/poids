#include <gtest/gtest.h>

#include "poids/si/constants.hpp"

using namespace si::base;
using poids::square;

#define EXPECT_TYPE_EQ(expected, actual) \
  EXPECT_TRUE((std::is_same_v<decltype(expected), decltype(actual)>))

TEST(TestSIDerivedUnits, Force) {
  si::Force expected = si::Force::makeFromBaseUnitValue(1.0);

  si::Force actual = kilogram * meter / square(second);

  EXPECT_TYPE_EQ(expected, actual);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-6);
}

TEST(TestSIDerivedUnits, Energy) {
  si::Energy expected = si::Energy::makeFromBaseUnitValue(1.0);

  si::Energy actual = kilogram * square(meter) / square(second);

  EXPECT_TYPE_EQ(expected, actual);
  EXPECT_NEAR(expected.base(), actual.base(), 1e-6);
}

#undef EXPECT_TYPE_EQ
