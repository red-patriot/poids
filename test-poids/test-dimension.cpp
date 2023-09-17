#include "gtest/gtest.h"

#include <Dimension.h>
#include <metric/SIDimension.h>
#include <util/rational.h>

using poids::metric::Dimension;
using poids::util::Rational;

TEST(TestDimension, ConstructTime) {
  Dimension type = poids::metric::TimeD(Rational(1));

  EXPECT_EQ(poids::util::Rational(1, 1), type.time);
  EXPECT_EQ(poids::util::Rational(0, 1), type.mass);
  EXPECT_EQ(poids::util::Rational(0, 1), type.length);
  EXPECT_EQ(poids::util::Rational(0, 1), type.temperature);
  EXPECT_EQ(poids::util::Rational(0, 1), type.current);
  EXPECT_EQ(poids::util::Rational(0, 1), type.amount);
  EXPECT_EQ(poids::util::Rational(0, 1), type.luminosity);
}

TEST(TestDimension, ConstructMass) {
  Dimension type{poids::metric::MassD({2, 3})};

  EXPECT_EQ(poids::util::Rational(0, 1), type.time);
  EXPECT_EQ(poids::util::Rational(2, 3), type.mass);
  EXPECT_EQ(poids::util::Rational(0, 1), type.length);
  EXPECT_EQ(poids::util::Rational(0, 1), type.temperature);
  EXPECT_EQ(poids::util::Rational(0, 1), type.current);
  EXPECT_EQ(poids::util::Rational(0, 1), type.amount);
  EXPECT_EQ(poids::util::Rational(0, 1), type.luminosity);
}

TEST(TestDimension, ConstructLength) {
  Dimension type{poids::metric::LengthD({5, 4})};

  EXPECT_EQ(poids::util::Rational(0, 1), type.time);
  EXPECT_EQ(poids::util::Rational(0, 1), type.mass);
  EXPECT_EQ(poids::util::Rational(5, 4), type.length);
  EXPECT_EQ(poids::util::Rational(0, 1), type.temperature);
  EXPECT_EQ(poids::util::Rational(0, 1), type.current);
  EXPECT_EQ(poids::util::Rational(0, 1), type.amount);
  EXPECT_EQ(poids::util::Rational(0, 1), type.luminosity);
}

TEST(TestDimension, ConstructTemperature) {
  Dimension type{poids::metric::TemperatureD({7, 2})};

  EXPECT_EQ(poids::util::Rational(0, 1), type.time);
  EXPECT_EQ(poids::util::Rational(0, 1), type.mass);
  EXPECT_EQ(poids::util::Rational(0, 1), type.length);
  EXPECT_EQ(poids::util::Rational(7, 2), type.temperature);
  EXPECT_EQ(poids::util::Rational(0, 1), type.current);
  EXPECT_EQ(poids::util::Rational(0, 1), type.amount);
  EXPECT_EQ(poids::util::Rational(0, 1), type.luminosity);
}

TEST(TestDimension, ConstructCurrent) {
  Dimension type{poids::metric::CurrentD({9, 5})};

  EXPECT_EQ(poids::util::Rational(0, 1), type.time);
  EXPECT_EQ(poids::util::Rational(0, 1), type.mass);
  EXPECT_EQ(poids::util::Rational(0, 1), type.length);
  EXPECT_EQ(poids::util::Rational(0, 1), type.temperature);
  EXPECT_EQ(poids::util::Rational(9, 5), type.current);
  EXPECT_EQ(poids::util::Rational(0, 1), type.amount);
  EXPECT_EQ(poids::util::Rational(0, 1), type.luminosity);
}

TEST(TestDimension, ConstructAmount) {
  Dimension type{poids::metric::AmountD({5, 9})};

  EXPECT_EQ(poids::util::Rational(0, 1), type.time);
  EXPECT_EQ(poids::util::Rational(0, 1), type.mass);
  EXPECT_EQ(poids::util::Rational(0, 1), type.length);
  EXPECT_EQ(poids::util::Rational(0, 1), type.temperature);
  EXPECT_EQ(poids::util::Rational(0, 1), type.current);
  EXPECT_EQ(poids::util::Rational(5, 9), type.amount);
  EXPECT_EQ(poids::util::Rational(0, 1), type.luminosity);
}

TEST(TestDimension, ConstructLuminosity) {
  Dimension type{poids::metric::LuminosityD({4, 7})};

  EXPECT_EQ(poids::util::Rational(0, 1), type.time);
  EXPECT_EQ(poids::util::Rational(0, 1), type.mass);
  EXPECT_EQ(poids::util::Rational(0, 1), type.length);
  EXPECT_EQ(poids::util::Rational(0, 1), type.temperature);
  EXPECT_EQ(poids::util::Rational(0, 1), type.current);
  EXPECT_EQ(poids::util::Rational(0, 1), type.amount);
  EXPECT_EQ(poids::util::Rational({4, 7}), type.luminosity);
}

TEST(TestDimension, ConstructDimensionless) {
  Dimension type{poids::metric::Dimensionless()};

  EXPECT_EQ(poids::util::Rational(0, 1), type.time);
  EXPECT_EQ(poids::util::Rational(0, 1), type.mass);
  EXPECT_EQ(poids::util::Rational(0, 1), type.length);
  EXPECT_EQ(poids::util::Rational(0, 1), type.temperature);
  EXPECT_EQ(poids::util::Rational(0, 1), type.current);
  EXPECT_EQ(poids::util::Rational(0, 1), type.amount);
  EXPECT_EQ(poids::util::Rational(0, 7), type.luminosity);
}

TEST(TestDimension, CreateCompound1) {
  Dimension type{poids::metric::TimeD({1, 2}) + poids::metric::LengthD(1)};

  EXPECT_EQ(poids::util::Rational(1, 2), type.time);
  EXPECT_EQ(poids::util::Rational(0, 1), type.mass);
  EXPECT_EQ(poids::util::Rational(1, 1), type.length);
  EXPECT_EQ(poids::util::Rational(0, 1), type.temperature);
  EXPECT_EQ(poids::util::Rational(0, 1), type.current);
  EXPECT_EQ(poids::util::Rational(0, 1), type.amount);
  EXPECT_EQ(poids::util::Rational(0, 1), type.luminosity);
}

TEST(TestDimension, CreateCompound2) {
  Dimension type = poids::metric::MassD({3, 2}) +
                   poids::metric::AmountD(-2);

  EXPECT_EQ(poids::util::Rational(0, 1), type.time);
  EXPECT_EQ(poids::util::Rational(3, 2), type.mass);
  EXPECT_EQ(poids::util::Rational(0, 1), type.length);
  EXPECT_EQ(poids::util::Rational(0, 1), type.temperature);
  EXPECT_EQ(poids::util::Rational(0, 1), type.current);
  EXPECT_EQ(poids::util::Rational(-2, 1), type.amount);
  EXPECT_EQ(poids::util::Rational(0, 1), type.luminosity);
}

TEST(TestDimension, CreateCompound3) {
  Dimension type = poids::metric::LuminosityD(4) -
                         poids::metric::LengthD({3, 4}) +
                         poids::metric::TemperatureD({6}) -
                         poids::metric::TimeD(-1);

  EXPECT_EQ(poids::util::Rational(1, 1), type.time);
  EXPECT_EQ(poids::util::Rational(0, 1), type.mass);
  EXPECT_EQ(poids::util::Rational(-3, 4), type.length);
  EXPECT_EQ(poids::util::Rational(6, 1), type.temperature);
  EXPECT_EQ(poids::util::Rational(0, 1), type.current);
  EXPECT_EQ(poids::util::Rational(0, 1), type.amount);
  EXPECT_EQ(poids::util::Rational(4, 1), type.luminosity);
}
