import "gtest/gtest.h";

import poid.util.dimension;
import poid.util.rational;

using poid::util::Dimension;
using poid::util::Rational;

TEST(TestDimension, ConstructTime) {
  Dimension type = poid::util::TimeD(Rational(1));

  EXPECT_EQ(poid::util::Rational(1, 1), type.time);
  EXPECT_EQ(poid::util::Rational(0, 1), type.mass);
  EXPECT_EQ(poid::util::Rational(0, 1), type.length);
  EXPECT_EQ(poid::util::Rational(0, 1), type.temperature);
  EXPECT_EQ(poid::util::Rational(0, 1), type.current);
  EXPECT_EQ(poid::util::Rational(0, 1), type.amount);
  EXPECT_EQ(poid::util::Rational(0, 1), type.luminosity);
}

TEST(TestDimension, ConstructMass) {
  Dimension type{poid::util::MassD({2, 3})};

  EXPECT_EQ(poid::util::Rational(0, 1), type.time);
  EXPECT_EQ(poid::util::Rational(2, 3), type.mass);
  EXPECT_EQ(poid::util::Rational(0, 1), type.length);
  EXPECT_EQ(poid::util::Rational(0, 1), type.temperature);
  EXPECT_EQ(poid::util::Rational(0, 1), type.current);
  EXPECT_EQ(poid::util::Rational(0, 1), type.amount);
  EXPECT_EQ(poid::util::Rational(0, 1), type.luminosity);
}

TEST(TestDimension, ConstructLength) {
  Dimension type{poid::util::LengthD({5, 4})};

  EXPECT_EQ(poid::util::Rational(0, 1), type.time);
  EXPECT_EQ(poid::util::Rational(0, 1), type.mass);
  EXPECT_EQ(poid::util::Rational(5, 4), type.length);
  EXPECT_EQ(poid::util::Rational(0, 1), type.temperature);
  EXPECT_EQ(poid::util::Rational(0, 1), type.current);
  EXPECT_EQ(poid::util::Rational(0, 1), type.amount);
  EXPECT_EQ(poid::util::Rational(0, 1), type.luminosity);
}

TEST(TestDimension, ConstructTemperature) {
  Dimension type{poid::util::TemperatureD({7, 2})};

  EXPECT_EQ(poid::util::Rational(0, 1), type.time);
  EXPECT_EQ(poid::util::Rational(0, 1), type.mass);
  EXPECT_EQ(poid::util::Rational(0, 1), type.length);
  EXPECT_EQ(poid::util::Rational(7, 2), type.temperature);
  EXPECT_EQ(poid::util::Rational(0, 1), type.current);
  EXPECT_EQ(poid::util::Rational(0, 1), type.amount);
  EXPECT_EQ(poid::util::Rational(0, 1), type.luminosity);
}

TEST(TestDimension, ConstructCurrent) {
  Dimension type{poid::util::CurrentD({9, 5})};

  EXPECT_EQ(poid::util::Rational(0, 1), type.time);
  EXPECT_EQ(poid::util::Rational(0, 1), type.mass);
  EXPECT_EQ(poid::util::Rational(0, 1), type.length);
  EXPECT_EQ(poid::util::Rational(0, 1), type.temperature);
  EXPECT_EQ(poid::util::Rational(9, 5), type.current);
  EXPECT_EQ(poid::util::Rational(0, 1), type.amount);
  EXPECT_EQ(poid::util::Rational(0, 1), type.luminosity);
}

TEST(TestDimension, ConstructAmount) {
  Dimension type{poid::util::AmountD({5, 9})};

  EXPECT_EQ(poid::util::Rational(0, 1), type.time);
  EXPECT_EQ(poid::util::Rational(0, 1), type.mass);
  EXPECT_EQ(poid::util::Rational(0, 1), type.length);
  EXPECT_EQ(poid::util::Rational(0, 1), type.temperature);
  EXPECT_EQ(poid::util::Rational(0, 1), type.current);
  EXPECT_EQ(poid::util::Rational(5, 9), type.amount);
  EXPECT_EQ(poid::util::Rational(0, 1), type.luminosity);
}

TEST(TestDimension, ConstructLuminosity) {
  Dimension type{poid::util::LuminosityD({4, 7})};

  EXPECT_EQ(poid::util::Rational(0, 1), type.time);
  EXPECT_EQ(poid::util::Rational(0, 1), type.mass);
  EXPECT_EQ(poid::util::Rational(0, 1), type.length);
  EXPECT_EQ(poid::util::Rational(0, 1), type.temperature);
  EXPECT_EQ(poid::util::Rational(0, 1), type.current);
  EXPECT_EQ(poid::util::Rational(0, 1), type.amount);
  EXPECT_EQ(poid::util::Rational({4, 7}), type.luminosity);
}
