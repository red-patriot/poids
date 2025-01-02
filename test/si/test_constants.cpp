#include <gtest/gtest.h>

#include "poids/core/quantity.hpp"
#include "poids/si/constants.hpp"

TEST(TestSIBaseConstant, Unitless) {
  auto expected = si::Unitless::makeFromBaseUnitValue(1.0);

  si::Unitless actual{1.0};

  EXPECT_EQ(expected, actual);
}

TEST(TestSIBaseConstant, Radian) {
  auto expected = si::Angle::makeFromBaseUnitValue(1.0);

  si::Angle actual = si::base::radian;

  EXPECT_EQ(expected, actual);
}

TEST(TestSIBaseConstant, Second) {
  auto expected = si::Time::makeFromBaseUnitValue(1.0);

  si::Time actual = si::base::second;

  EXPECT_EQ(expected, actual);
}

TEST(TestSIBaseConstant, Meter) {
  auto expected = si::Length::makeFromBaseUnitValue(1.0);

  si::Length actual = si::base::meter;

  EXPECT_EQ(expected, actual);
}

TEST(TestSIBaseConstant, Kilogram) {
  auto expected = si::Mass::makeFromBaseUnitValue(1.0);

  si::Mass actual = si::base::kilogram;

  EXPECT_EQ(expected, actual);
}

TEST(TestSIBaseConstant, Ampere) {
  auto expected = si::Current::makeFromBaseUnitValue(1.0);

  si::Current actual = si::base::ampere;

  EXPECT_EQ(expected, actual);
}

TEST(TestSIBaseConstant, Kelvin) {
  auto expected = si::Temperature::makeFromBaseUnitValue(1.0);

  si::Temperature actual = si::base::kelvin;

  EXPECT_EQ(expected, actual);
}

TEST(TestSIBaseConstant, Mole) {
  auto expected = si::Amount::makeFromBaseUnitValue(1.0);

  si::Amount actual = si::base::mole;

  EXPECT_EQ(expected, actual);
}

TEST(TestSIBaseConstant, Candela) {
  auto expected = si::Luminosity::makeFromBaseUnitValue(1.0);

  si::Luminosity actual = si::base::candela;

  EXPECT_EQ(expected, actual);
}

TEST(TestSIDerivedConstant, AccessBaseFromUnitsNamespace1) {
  [[maybe_unused]] auto angle = si::units::radian;
  [[maybe_unused]] auto time = si::units::second;
  [[maybe_unused]] auto length = si::units::meter;
  [[maybe_unused]] auto mass = si::units::kilogram;
  [[maybe_unused]] auto current = si::units::ampere;
  [[maybe_unused]] auto temperature = si::units::kelvin;
  [[maybe_unused]] auto amount = si::units::mole;
  [[maybe_unused]] auto luminosity = si::units::candela;

  SUCCEED();
}

TEST(TestSIDerivedConstant, AccessBaseFromUnitsNamespace2) {
  using namespace si::units;

  [[maybe_unused]] auto angle = radian;
  [[maybe_unused]] auto time = second;
  [[maybe_unused]] auto length = meter;
  [[maybe_unused]] auto mass = kilogram;
  [[maybe_unused]] auto current = ampere;
  [[maybe_unused]] auto temperature = kelvin;
  [[maybe_unused]] auto amount = mole;
  [[maybe_unused]] auto luminosity = candela;

  SUCCEED();
}

TEST(TestSIDerivedConstant, Sterarian) {
  using namespace si::base;
  auto expected = si::SolidAngle::makeFromBaseUnitValue(1.0);

  si::SolidAngle actual = si::units::steradian;

  EXPECT_EQ(expected, actual);
}

TEST(TestSIDerivedConstant, Hertz) {
  using namespace si::base;
  auto expected = si::Frequency::makeFromBaseUnitValue(1.0);

  si::Frequency actual = si::units::hertz;

  EXPECT_EQ(expected, actual);
}

TEST(TestSIDerivedConstant, Meter2) {
  using namespace si::base;
  auto expected = si::Area::makeFromBaseUnitValue(1.0);

  si::Area actual = si::units::meter2;

  EXPECT_EQ(expected, actual);
}

TEST(TestSIDerivedConstant, Meter3) {
  using namespace si::base;
  auto expected = si::Volume::makeFromBaseUnitValue(1.0);

  si::Volume actual = si::units::meter3;

  EXPECT_EQ(expected, actual);
}

TEST(TestSIDerivedConstant, Gram) {
  using namespace si::base;
  auto expected = si::Mass::makeFromBaseUnitValue(1e-3);

  si::Mass actual = si::units::gram;

  EXPECT_EQ(expected, actual);
}

TEST(TestSIDerivedConstant, Newton) {
  using namespace si::base;
  auto expected = si::Force::makeFromBaseUnitValue(1.0);

  si::Force actual = si::units::newton;

  EXPECT_EQ(expected, actual);
}

TEST(TestSIDerivedConstant, Joule) {
  using namespace si::base;
  auto expected = si::Energy::makeFromBaseUnitValue(1.0);

  si::Energy actual = si::units::joule;

  EXPECT_EQ(expected, actual);
}

TEST(TestSIDerivedConstant, Watt) {
  using namespace si::base;
  auto expected = si::Power::makeFromBaseUnitValue(1.0);

  si::Power actual = si::units::watt;

  EXPECT_EQ(expected, actual);
}

TEST(TestSIDerivedConstant, Pascal) {
  using namespace si::base;
  auto expected = si::Pressure::makeFromBaseUnitValue(1.0);

  si::Pressure actual = si::units::pascal;

  EXPECT_EQ(expected, actual);
}

TEST(TestSIDerivedConstant, Coulomb) {
  using namespace si::base;
  auto expected = si::ElectricCharge::makeFromBaseUnitValue(1.0);

  si::ElectricCharge actual = si::units::coulomb;

  EXPECT_EQ(expected, actual);
}

TEST(TestSIDerivedConstant, Volt) {
  using namespace si::base;
  auto expected = si::Voltage::makeFromBaseUnitValue(1.0);

  si::Voltage actual = si::units::volt;

  EXPECT_EQ(expected, actual);
}

TEST(TestSIDerivedConstant, Farad) {
  using namespace si::base;
  auto expected = si::Capacitance::makeFromBaseUnitValue(1.0);

  si::Capacitance actual = si::units::farad;

  EXPECT_EQ(expected, actual);
}

TEST(TestSIDerivedConstant, Ohm) {
  using namespace si::base;
  auto expected = si::Resistance::makeFromBaseUnitValue(1.0);

  si::Resistance actual = si::units::ohm;

  EXPECT_EQ(expected, actual);
}

TEST(TestSIDerivedConstant, Siemen) {
  using namespace si::base;
  auto expected = si::Conductance::makeFromBaseUnitValue(1.0);

  si::Conductance actual = si::units::siemen;

  EXPECT_EQ(expected, actual);
}

TEST(TestSIDerivedConstant, Weber) {
  using namespace si::base;
  auto expected = si::MagneticFlux::makeFromBaseUnitValue(1.0);

  si::MagneticFlux actual = si::units::weber;

  EXPECT_EQ(expected, actual);
}

TEST(TestSIDerivedConstant, Henry) {
  using namespace si::base;
  auto expected = si::Inductance::makeFromBaseUnitValue(1.0);

  si::Inductance actual = si::units::henry;

  EXPECT_EQ(expected, actual);
}

TEST(TestSIDerivedConstant, Tesla) {
  using namespace si::base;
  auto expected = si::MagneticFieldStrength::makeFromBaseUnitValue(1.0);

  si::MagneticFieldStrength actual = si::units::tesla;

  EXPECT_EQ(expected, actual);
}

TEST(TestSIDerivedConstant, Lumen) {
  using namespace si::base;
  auto expected = si::LuminousFlux::makeFromBaseUnitValue(1.0);

  si::LuminousFlux actual = si::units::lumen;

  EXPECT_EQ(expected, actual);
}

TEST(TestSIDerivedConstant, Lux) {
  using namespace si::base;
  auto expected = si::Illuminance::makeFromBaseUnitValue(1.0);

  si::Illuminance actual = si::units::lux;

  EXPECT_EQ(expected, actual);
}

TEST(TestSIDerivedConstant, Katal) {
  using namespace si::base;
  auto expected = si::CatalyticActivity::makeFromBaseUnitValue(1.0);

  si::CatalyticActivity actual = si::units::katal;

  EXPECT_EQ(expected, actual);
}
