import "gtest/gtest.h";

import poids.metric;

#define METRIC_LITERALS_TEST(name, expectedType, expectedValue, actualValue) \
  TEST(TestLiteralsMetric, name) {                                           \
    expectedType expected{expectedValue};                                    \
    auto actual = actualValue;                                               \
    EXPECT_EQ(expected.dimension, actual.dimension);                         \
    EXPECT_NEAR(expected.base(), actual.base(), 1e-10);                      \
  }

// Base Unit tests
METRIC_LITERALS_TEST(Second, poids::Unit<poids::TimeD(1)>, 1.0, poids::metric::second);
METRIC_LITERALS_TEST(Kilogram, poids::Unit<poids::MassD(1)>, 1.0, poids::metric::kilogram);
METRIC_LITERALS_TEST(Meter, poids::Unit<poids::LengthD(1)>, 1.0, poids::metric::meter);
METRIC_LITERALS_TEST(Kelvin, poids::Unit<poids::TemperatureD(1)>, 1.0, poids::metric::kelvin);
METRIC_LITERALS_TEST(Ampere, poids::Unit<poids::CurrentD(1)>, 1.0, poids::metric::ampere);
METRIC_LITERALS_TEST(Mole, poids::Unit<poids::AmountD(1)>, 1.0, poids::metric::mole);
METRIC_LITERALS_TEST(Candela, poids::Unit<poids::LuminosityD(1)>, 1.0, poids::metric::candela);

// Pretty unit types
METRIC_LITERALS_TEST(PrettySecond, poids::Time, 1.0, poids::metric::second);
METRIC_LITERALS_TEST(PrettyKilogram, poids::Mass, 1.0, poids::metric::kilogram);
METRIC_LITERALS_TEST(PrettyMeter, poids::Length, 1.0, poids::metric::meter);
METRIC_LITERALS_TEST(PrettyKelvin, poids::Temperature, 1.0, poids::metric::kelvin);
METRIC_LITERALS_TEST(PrettyAmpere, poids::Current, 1.0, poids::metric::ampere);
METRIC_LITERALS_TEST(PrettyMole, poids::Amount, 1.0, poids::metric::mole);
METRIC_LITERALS_TEST(PrettyCandela, poids::Luminosity, 1.0, poids::metric::candela);
