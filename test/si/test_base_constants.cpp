#include <gtest/gtest.h>

#include "poids/core/quantity.hpp"
#include "poids/si/constants.hpp"

TEST(TestSIBaseConstants, Unitless) {
  auto expected = si::Unitless::makeFromBaseUnitValue(1.0);

  si::Unitless actual{1.0};

  EXPECT_EQ(expected, actual);
}

TEST(TestSIBaseConstants, Radian) {
  auto expected = si::Angle::makeFromBaseUnitValue(1.0);

  si::Angle actual = si::base::radian;

  EXPECT_EQ(expected, actual);
}

TEST(TestSIBaseConstants, Second) {
  auto expected = si::Time::makeFromBaseUnitValue(1.0);

  si::Time actual = si::base::second;

  EXPECT_EQ(expected, actual);
}

TEST(TestSIBaseConstants, Meter) {
  auto expected = si::Length::makeFromBaseUnitValue(1.0);

  si::Length actual = si::base::meter;

  EXPECT_EQ(expected, actual);
}

TEST(TestSIBaseConstants, Kilogram) {
  auto expected = si::Mass::makeFromBaseUnitValue(1.0);

  si::Mass actual = si::base::kilogram;

  EXPECT_EQ(expected, actual);
}

TEST(TestSIBaseConstants, Ampere) {
  auto expected = si::Current::makeFromBaseUnitValue(1.0);

  si::Current actual = si::base::ampere;

  EXPECT_EQ(expected, actual);
}

TEST(TestSIBaseConstants, Kelvin) {
  auto expected = si::Temperature::makeFromBaseUnitValue(1.0);

  si::Temperature actual = si::base::kelvin;

  EXPECT_EQ(expected, actual);
}

TEST(TestSIBaseConstants, Mole) {
  auto expected = si::Amount::makeFromBaseUnitValue(1.0);

  si::Amount actual = si::base::mole;

  EXPECT_EQ(expected, actual);
}

TEST(TestSIBaseConstants, Candela) {
  auto expected = si::Luminosity::makeFromBaseUnitValue(1.0);

  si::Luminosity actual = si::base::candela;

  EXPECT_EQ(expected, actual);
}
