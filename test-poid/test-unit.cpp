import "gtest/gtest.h";

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
