#include "gtest/gtest.h"

#include <Metric.h>

#define METRIC_LITERALS_TEST(name, expectedType, expectedValue, actualValue) \
  TEST(TestLiteralsMetric, name) {                                           \
    expectedType expected{expectedValue};                                    \
    auto actual = actualValue;                                               \
    EXPECT_EQ(expected.dimension, actual.dimension);                         \
    EXPECT_NEAR(expected.base(), actual.base(), 1e-10);                      \
  }

// Base Unit tests
METRIC_LITERALS_TEST(Second, poids::Unit<poids::TimeD(1)>, 1.0, poids::metric::second)
METRIC_LITERALS_TEST(Kilogram, poids::Unit<poids::MassD(1)>, 1.0, poids::metric::kilogram)
METRIC_LITERALS_TEST(Meter, poids::Unit<poids::LengthD(1)>, 1.0, poids::metric::meter)
METRIC_LITERALS_TEST(Kelvin, poids::Unit<poids::TemperatureD(1)>, 1.0, poids::metric::kelvin)
METRIC_LITERALS_TEST(Ampere, poids::Unit<poids::CurrentD(1)>, 1.0, poids::metric::ampere)
METRIC_LITERALS_TEST(Mole, poids::Unit<poids::AmountD(1)>, 1.0, poids::metric::mole)
METRIC_LITERALS_TEST(Candela, poids::Unit<poids::LuminosityD(1)>, 1.0, poids::metric::candela)

// Pretty unit types
METRIC_LITERALS_TEST(PrettySecond, poids::Time, 1.0, poids::metric::second)
METRIC_LITERALS_TEST(PrettyKilogram, poids::Mass, 1.0, poids::metric::kilogram)
METRIC_LITERALS_TEST(PrettyMeter, poids::Length, 1.0, poids::metric::meter)
METRIC_LITERALS_TEST(PrettyKelvin, poids::Temperature, 1.0, poids::metric::kelvin)
METRIC_LITERALS_TEST(PrettyAmpere, poids::Current, 1.0, poids::metric::ampere)
METRIC_LITERALS_TEST(PrettyMole, poids::Amount, 1.0, poids::metric::mole)
METRIC_LITERALS_TEST(PrettyCandela, poids::Luminosity, 1.0, poids::metric::candela)

// Secondary units tests
METRIC_LITERALS_TEST(Gram, poids::Mass, 0.001, poids::metric::gram);

METRIC_LITERALS_TEST(Hertz, poids::Frequency, 3.5, 3.5 * poids::metric::hertz)

METRIC_LITERALS_TEST(MetersSquared, poids::Area, 6.78, 6.78 * poids::metric::meter2)
METRIC_LITERALS_TEST(MetersCubed, poids::Volume, -9.043, -9.043 * poids::metric::meter3)
METRIC_LITERALS_TEST(MetersFourth, poids::SecondMomentOfArea, 6.7e8, 6.7e8 * poids::metric::meter4)

METRIC_LITERALS_TEST(MetersPerSecond, poids::Velocity, 6.67, 6.67 * poids::metric::meter / poids::metric::second)
METRIC_LITERALS_TEST(MetersPerSecondSquared, poids::Acceleration, 0.4, 0.4 * poids::metric::meter / poids::metric::second2)
METRIC_LITERALS_TEST(MetersPerSecondCubed, poids::Jerk, 1.1, 1.1 * poids::metric::meter / poids::metric::second3)

METRIC_LITERALS_TEST(Newtons, poids::Force, -5, -5 * poids::metric::newton)
METRIC_LITERALS_TEST(Joules, poids::Energy, 8.8, 8.8 * poids::metric::joule)
METRIC_LITERALS_TEST(Watts, poids::Power, 0.456, 0.456 * poids::metric::watt)

METRIC_LITERALS_TEST(Coulombs, poids::Charge, 12, 12 * poids::metric::coulomb)
METRIC_LITERALS_TEST(Volts, poids::Voltage, -5.5, -5.5 * poids::metric::volt)
METRIC_LITERALS_TEST(Ohms, poids::Resistance, 6.5e2, 6.5e2 * poids::metric::ohm)
METRIC_LITERALS_TEST(Farads, poids::Capacitance, 43e-5, 43e-5 * poids::metric::farad)
METRIC_LITERALS_TEST(Henries, poids::Inductance, 0.34e-2, 0.34e-2 * poids::metric::henry)

METRIC_LITERALS_TEST(KilogramPerCubicMeter, poids::Density, 3.23, 3.23 * poids::metric::kilogram / poids::metric::meter3)
METRIC_LITERALS_TEST(Pascals, poids::Pressure, 5.6e4, 5.6e4 * poids::metric::pascal)
METRIC_LITERALS_TEST(KilogramPerMole, poids::MolarMass, 3.23e-4, 3.23e-4 * poids::metric::kilogram / poids::metric::mole)
METRIC_LITERALS_TEST(PascalSecond, poids::DynamicViscosity, 28.1, 28.1 * poids::metric::pascal * poids::metric::second)
METRIC_LITERALS_TEST(JouleSecondPerKilogram, poids::KinematicViscosity, 0.23, 0.23 * poids::metric::meter2 / poids::metric::second)

// Prefix tests
using poids::metric::meter;
METRIC_LITERALS_TEST(PrefixNano, poids::Length, 12.45e-9, 12.45 * poids::metric::nano(meter));
METRIC_LITERALS_TEST(PrefixMicro, poids::Length, 12.45e-6, 12.45 * poids::metric::micro(meter));
METRIC_LITERALS_TEST(PrefixMilli, poids::Length, 12.45e-3, 12.45 * poids::metric::milli(meter));
METRIC_LITERALS_TEST(PrefixKilo, poids::Length, 12.45e3, 12.45 * poids::metric::kilo(meter));
METRIC_LITERALS_TEST(PrefixMega, poids::Length, 12.45e6, 12.45 * poids::metric::mega(meter));
METRIC_LITERALS_TEST(PrefixGiga, poids::Length, 12.45e9, 12.45 * poids::metric::giga(meter));
