import "gtest/gtest.h";

import poid.dimension;
import poid.util.rational;

using poid::Dimension;
using poid::util::Rational;

TEST(TestDimension, ConstructTime) {
  Dimension type = poid::TimeD(Rational(1));

  EXPECT_EQ(poid::util::Rational(1, 1), type.time);
  EXPECT_EQ(poid::util::Rational(0, 1), type.mass);
  EXPECT_EQ(poid::util::Rational(0, 1), type.length);
  EXPECT_EQ(poid::util::Rational(0, 1), type.temperature);
  EXPECT_EQ(poid::util::Rational(0, 1), type.current);
  EXPECT_EQ(poid::util::Rational(0, 1), type.amount);
  EXPECT_EQ(poid::util::Rational(0, 1), type.luminosity);
}

TEST(TestDimension, ConstructMass) {
  Dimension type{poid::MassD({2, 3})};

  EXPECT_EQ(poid::util::Rational(0, 1), type.time);
  EXPECT_EQ(poid::util::Rational(2, 3), type.mass);
  EXPECT_EQ(poid::util::Rational(0, 1), type.length);
  EXPECT_EQ(poid::util::Rational(0, 1), type.temperature);
  EXPECT_EQ(poid::util::Rational(0, 1), type.current);
  EXPECT_EQ(poid::util::Rational(0, 1), type.amount);
  EXPECT_EQ(poid::util::Rational(0, 1), type.luminosity);
}

TEST(TestDimension, ConstructLength) {
  Dimension type{poid::LengthD({5, 4})};

  EXPECT_EQ(poid::util::Rational(0, 1), type.time);
  EXPECT_EQ(poid::util::Rational(0, 1), type.mass);
  EXPECT_EQ(poid::util::Rational(5, 4), type.length);
  EXPECT_EQ(poid::util::Rational(0, 1), type.temperature);
  EXPECT_EQ(poid::util::Rational(0, 1), type.current);
  EXPECT_EQ(poid::util::Rational(0, 1), type.amount);
  EXPECT_EQ(poid::util::Rational(0, 1), type.luminosity);
}

TEST(TestDimension, ConstructTemperature) {
  Dimension type{poid::TemperatureD({7, 2})};

  EXPECT_EQ(poid::util::Rational(0, 1), type.time);
  EXPECT_EQ(poid::util::Rational(0, 1), type.mass);
  EXPECT_EQ(poid::util::Rational(0, 1), type.length);
  EXPECT_EQ(poid::util::Rational(7, 2), type.temperature);
  EXPECT_EQ(poid::util::Rational(0, 1), type.current);
  EXPECT_EQ(poid::util::Rational(0, 1), type.amount);
  EXPECT_EQ(poid::util::Rational(0, 1), type.luminosity);
}

TEST(TestDimension, ConstructCurrent) {
  Dimension type{poid::CurrentD({9, 5})};

  EXPECT_EQ(poid::util::Rational(0, 1), type.time);
  EXPECT_EQ(poid::util::Rational(0, 1), type.mass);
  EXPECT_EQ(poid::util::Rational(0, 1), type.length);
  EXPECT_EQ(poid::util::Rational(0, 1), type.temperature);
  EXPECT_EQ(poid::util::Rational(9, 5), type.current);
  EXPECT_EQ(poid::util::Rational(0, 1), type.amount);
  EXPECT_EQ(poid::util::Rational(0, 1), type.luminosity);
}

TEST(TestDimension, ConstructAmount) {
  Dimension type{poid::AmountD({5, 9})};

  EXPECT_EQ(poid::util::Rational(0, 1), type.time);
  EXPECT_EQ(poid::util::Rational(0, 1), type.mass);
  EXPECT_EQ(poid::util::Rational(0, 1), type.length);
  EXPECT_EQ(poid::util::Rational(0, 1), type.temperature);
  EXPECT_EQ(poid::util::Rational(0, 1), type.current);
  EXPECT_EQ(poid::util::Rational(5, 9), type.amount);
  EXPECT_EQ(poid::util::Rational(0, 1), type.luminosity);
}

TEST(TestDimension, ConstructLuminosity) {
  Dimension type{poid::LuminosityD({4, 7})};

  EXPECT_EQ(poid::util::Rational(0, 1), type.time);
  EXPECT_EQ(poid::util::Rational(0, 1), type.mass);
  EXPECT_EQ(poid::util::Rational(0, 1), type.length);
  EXPECT_EQ(poid::util::Rational(0, 1), type.temperature);
  EXPECT_EQ(poid::util::Rational(0, 1), type.current);
  EXPECT_EQ(poid::util::Rational(0, 1), type.amount);
  EXPECT_EQ(poid::util::Rational({4, 7}), type.luminosity);
}

TEST(TestDimension, CreateCompound1) {
  poid::Dimension type{poid::TimeD({1, 2}) + poid::LengthD(1)};

  EXPECT_EQ(poid::util::Rational(1, 2), type.time);
  EXPECT_EQ(poid::util::Rational(0, 1), type.mass);
  EXPECT_EQ(poid::util::Rational(1, 1), type.length);
  EXPECT_EQ(poid::util::Rational(0, 1), type.temperature);
  EXPECT_EQ(poid::util::Rational(0, 1), type.current);
  EXPECT_EQ(poid::util::Rational(0, 1), type.amount);
  EXPECT_EQ(poid::util::Rational(0, 1), type.luminosity);
}

TEST(TestDimension, CreateCompound2) {
  poid::Dimension type = poid::MassD({3, 2}) +
                         poid::AmountD(-2);

  EXPECT_EQ(poid::util::Rational(0, 1), type.time);
  EXPECT_EQ(poid::util::Rational(3, 2), type.mass);
  EXPECT_EQ(poid::util::Rational(0, 1), type.length);
  EXPECT_EQ(poid::util::Rational(0, 1), type.temperature);
  EXPECT_EQ(poid::util::Rational(0, 1), type.current);
  EXPECT_EQ(poid::util::Rational(-2, 1), type.amount);
  EXPECT_EQ(poid::util::Rational(0, 1), type.luminosity);
}

TEST(TestDimension, CreateCompound3) {
  poid::Dimension type = poid::LuminosityD(4) -
                         poid::LengthD({3, 4}) +
                         poid::TemperatureD({6}) -
                         poid::TimeD(-1);

  EXPECT_EQ(poid::util::Rational(1, 1), type.time);
  EXPECT_EQ(poid::util::Rational(0, 1), type.mass);
  EXPECT_EQ(poid::util::Rational(-3, 4), type.length);
  EXPECT_EQ(poid::util::Rational(6, 1), type.temperature);
  EXPECT_EQ(poid::util::Rational(0, 1), type.current);
  EXPECT_EQ(poid::util::Rational(0, 1), type.amount);
  EXPECT_EQ(poid::util::Rational(4, 1), type.luminosity);
}
