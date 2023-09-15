#include "gtest/gtest.h"

#include <Dimension.h>
#include <rational.h>

using poids::Dimension;
using poids::util::Rational;

TEST(TestDimension, ConstructTime) {
  Dimension type = poids::TimeD(Rational(1));

  EXPECT_EQ(poids::util::Rational(1, 1), type.time);
  EXPECT_EQ(poids::util::Rational(0, 1), type.mass);
  EXPECT_EQ(poids::util::Rational(0, 1), type.length);
  EXPECT_EQ(poids::util::Rational(0, 1), type.temperature);
  EXPECT_EQ(poids::util::Rational(0, 1), type.current);
  EXPECT_EQ(poids::util::Rational(0, 1), type.amount);
  EXPECT_EQ(poids::util::Rational(0, 1), type.luminosity);
}

TEST(TestDimension, ConstructMass) {
  Dimension type{poids::MassD({2, 3})};

  EXPECT_EQ(poids::util::Rational(0, 1), type.time);
  EXPECT_EQ(poids::util::Rational(2, 3), type.mass);
  EXPECT_EQ(poids::util::Rational(0, 1), type.length);
  EXPECT_EQ(poids::util::Rational(0, 1), type.temperature);
  EXPECT_EQ(poids::util::Rational(0, 1), type.current);
  EXPECT_EQ(poids::util::Rational(0, 1), type.amount);
  EXPECT_EQ(poids::util::Rational(0, 1), type.luminosity);
}

TEST(TestDimension, ConstructLength) {
  Dimension type{poids::LengthD({5, 4})};

  EXPECT_EQ(poids::util::Rational(0, 1), type.time);
  EXPECT_EQ(poids::util::Rational(0, 1), type.mass);
  EXPECT_EQ(poids::util::Rational(5, 4), type.length);
  EXPECT_EQ(poids::util::Rational(0, 1), type.temperature);
  EXPECT_EQ(poids::util::Rational(0, 1), type.current);
  EXPECT_EQ(poids::util::Rational(0, 1), type.amount);
  EXPECT_EQ(poids::util::Rational(0, 1), type.luminosity);
}

TEST(TestDimension, ConstructTemperature) {
  Dimension type{poids::TemperatureD({7, 2})};

  EXPECT_EQ(poids::util::Rational(0, 1), type.time);
  EXPECT_EQ(poids::util::Rational(0, 1), type.mass);
  EXPECT_EQ(poids::util::Rational(0, 1), type.length);
  EXPECT_EQ(poids::util::Rational(7, 2), type.temperature);
  EXPECT_EQ(poids::util::Rational(0, 1), type.current);
  EXPECT_EQ(poids::util::Rational(0, 1), type.amount);
  EXPECT_EQ(poids::util::Rational(0, 1), type.luminosity);
}

TEST(TestDimension, ConstructCurrent) {
  Dimension type{poids::CurrentD({9, 5})};

  EXPECT_EQ(poids::util::Rational(0, 1), type.time);
  EXPECT_EQ(poids::util::Rational(0, 1), type.mass);
  EXPECT_EQ(poids::util::Rational(0, 1), type.length);
  EXPECT_EQ(poids::util::Rational(0, 1), type.temperature);
  EXPECT_EQ(poids::util::Rational(9, 5), type.current);
  EXPECT_EQ(poids::util::Rational(0, 1), type.amount);
  EXPECT_EQ(poids::util::Rational(0, 1), type.luminosity);
}

TEST(TestDimension, ConstructAmount) {
  Dimension type{poids::AmountD({5, 9})};

  EXPECT_EQ(poids::util::Rational(0, 1), type.time);
  EXPECT_EQ(poids::util::Rational(0, 1), type.mass);
  EXPECT_EQ(poids::util::Rational(0, 1), type.length);
  EXPECT_EQ(poids::util::Rational(0, 1), type.temperature);
  EXPECT_EQ(poids::util::Rational(0, 1), type.current);
  EXPECT_EQ(poids::util::Rational(5, 9), type.amount);
  EXPECT_EQ(poids::util::Rational(0, 1), type.luminosity);
}

TEST(TestDimension, ConstructLuminosity) {
  Dimension type{poids::LuminosityD({4, 7})};

  EXPECT_EQ(poids::util::Rational(0, 1), type.time);
  EXPECT_EQ(poids::util::Rational(0, 1), type.mass);
  EXPECT_EQ(poids::util::Rational(0, 1), type.length);
  EXPECT_EQ(poids::util::Rational(0, 1), type.temperature);
  EXPECT_EQ(poids::util::Rational(0, 1), type.current);
  EXPECT_EQ(poids::util::Rational(0, 1), type.amount);
  EXPECT_EQ(poids::util::Rational({4, 7}), type.luminosity);
}

TEST(TestDimension, CreateCompound1) {
  poids::Dimension type{poids::TimeD({1, 2}) + poids::LengthD(1)};

  EXPECT_EQ(poids::util::Rational(1, 2), type.time);
  EXPECT_EQ(poids::util::Rational(0, 1), type.mass);
  EXPECT_EQ(poids::util::Rational(1, 1), type.length);
  EXPECT_EQ(poids::util::Rational(0, 1), type.temperature);
  EXPECT_EQ(poids::util::Rational(0, 1), type.current);
  EXPECT_EQ(poids::util::Rational(0, 1), type.amount);
  EXPECT_EQ(poids::util::Rational(0, 1), type.luminosity);
}

TEST(TestDimension, CreateCompound2) {
  poids::Dimension type = poids::MassD({3, 2}) +
                         poids::AmountD(-2);

  EXPECT_EQ(poids::util::Rational(0, 1), type.time);
  EXPECT_EQ(poids::util::Rational(3, 2), type.mass);
  EXPECT_EQ(poids::util::Rational(0, 1), type.length);
  EXPECT_EQ(poids::util::Rational(0, 1), type.temperature);
  EXPECT_EQ(poids::util::Rational(0, 1), type.current);
  EXPECT_EQ(poids::util::Rational(-2, 1), type.amount);
  EXPECT_EQ(poids::util::Rational(0, 1), type.luminosity);
}

TEST(TestDimension, CreateCompound3) {
  poids::Dimension type = poids::LuminosityD(4) -
                         poids::LengthD({3, 4}) +
                         poids::TemperatureD({6}) -
                         poids::TimeD(-1);

  EXPECT_EQ(poids::util::Rational(1, 1), type.time);
  EXPECT_EQ(poids::util::Rational(0, 1), type.mass);
  EXPECT_EQ(poids::util::Rational(-3, 4), type.length);
  EXPECT_EQ(poids::util::Rational(6, 1), type.temperature);
  EXPECT_EQ(poids::util::Rational(0, 1), type.current);
  EXPECT_EQ(poids::util::Rational(0, 1), type.amount);
  EXPECT_EQ(poids::util::Rational(4, 1), type.luminosity);
}
