#include <gtest/gtest.h>

#include "poids/si/constants.hpp"

using namespace si::base;
using poids::pow;
using poids::square;

#define DERIVED_UNIT_TEST(unit, expression)                              \
  TEST(TestSIDerivedUnits, unit) {                                       \
    si::unit expected = si::unit::makeFromBaseUnitValue(1.0);            \
                                                                         \
    si::unit actual = (expression);                                      \
                                                                         \
    EXPECT_TRUE((std::is_same_v<decltype(expected), decltype(actual)>)); \
    EXPECT_NEAR(expected.base(), actual.base(), 1e-6);                   \
  }

// clang-format off

DERIVED_UNIT_TEST(SolidAngle, si::Unitless{1.0})
DERIVED_UNIT_TEST(Frequency, si::Unitless{1.0} / second)
DERIVED_UNIT_TEST(Area, meter * meter);
DERIVED_UNIT_TEST(Volume, meter * meter * meter);
DERIVED_UNIT_TEST(SecondMomentOfArea, meter * meter * meter * meter);
DERIVED_UNIT_TEST(Velocity, meter / second)
DERIVED_UNIT_TEST(Acceleration, meter / square(second))
DERIVED_UNIT_TEST(Jerk, meter / (pow<3,1>(second)))
DERIVED_UNIT_TEST(Momentum, kilogram * meter / second)
DERIVED_UNIT_TEST(Density, kilogram / (pow<3,1>(meter)))
DERIVED_UNIT_TEST(Force, kilogram * meter / square(second))
DERIVED_UNIT_TEST(SpecificWeight, kilogram * meter / (square(second) * pow<3,1>(meter)))
DERIVED_UNIT_TEST(MomentOfInertia, kilogram * square(meter))
DERIVED_UNIT_TEST(Energy, kilogram * square(meter) / square(second))
DERIVED_UNIT_TEST(Power, kilogram * square(meter) / (pow<3, 1>(second)))
DERIVED_UNIT_TEST(Pressure, kilogram * meter / (square(second) * square(meter)))
DERIVED_UNIT_TEST(DynamicViscosity, kilogram * meter * second / (square(second) * square(meter)))
DERIVED_UNIT_TEST(KinematicViscosity, square(meter) / second)
DERIVED_UNIT_TEST(ElectricCharge, second * ampere)
DERIVED_UNIT_TEST(Voltage, kilogram * square(meter) / (pow<3, 1>(second) * ampere))
DERIVED_UNIT_TEST(Resistance, kilogram * square(meter) / (pow<3, 1>(second) * square(ampere)))
DERIVED_UNIT_TEST(Capacitance, (pow<4,1>(second) * square(ampere) / (kilogram * square(meter))))
DERIVED_UNIT_TEST(Conductance, (pow<3,1>(second) * square(ampere) / (kilogram * square(meter))))
DERIVED_UNIT_TEST(Inductance, kilogram * square(meter) / (square(second) * square(ampere)))
DERIVED_UNIT_TEST(MagneticFlux, kilogram * square(meter) / (square(second) * ampere))
DERIVED_UNIT_TEST(MagneticFieldStrength, kilogram / (square(second) * ampere))
DERIVED_UNIT_TEST(LuminousFlux, candela / square(radian))
DERIVED_UNIT_TEST(Illuminance, candela * square(radian) / square(meter))
DERIVED_UNIT_TEST(CatalyticActivity, mole / second);

// clang-format on

#undef DERIVED_UNIT_TEST
