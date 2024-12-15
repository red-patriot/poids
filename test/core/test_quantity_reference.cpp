#include <gtest/gtest.h>

#include "poids/core/quantity.hpp"
#include "poids/core/reference.hpp"
#include "poids/kgms.hpp"

using namespace kgms::base;

TEST(TestQuantityReference, ImplicitlyConstructFromQuantity) {
  double expected = 4.5;
  kgms::Mass quantity = kgms::Mass::makeFromBaseUnitValue(4.5);

  poids::ReferenceQuantity<double, kgms::units::MassUnit> actual = quantity;

  EXPECT_DOUBLE_EQ(expected, actual.base());
}

TEST(TestQuantityReference, ReferencesOriginalQuantity) {
  double expected = 10.0;
  kgms::Mass actual = kgms::Mass::makeFromBaseUnitValue(4.5);

  poids::ReferenceQuantity<double, kgms::units::MassUnit> reference = actual;

  reference = expected * kilogram;

  EXPECT_DOUBLE_EQ(expected, actual.as(kilogram));
}

TEST(TestQuantityReference, ConstructFromScalar) {
  double expected = 3.0;
  double actual = 10.0;

  auto reference = poids::ReferenceQuantity<double, kgms::units::LengthUnit>::makeReference(actual);

  reference = 3 * meter;

  EXPECT_DOUBLE_EQ(expected, actual);
}

TEST(TestQuantityReference, Copyable) {
  auto quantity = kgms::Velocity::makeFromBaseUnitValue(1.5);
  poids::ReferenceQuantity<double, kgms::units::VelocityUnit> ref1 = quantity;

  auto ref2 = ref1;

  EXPECT_DOUBLE_EQ(ref1.base(), ref2.base());
}

TEST(TestQuantityReference, ExplicitlyConvertibleToQuantity) {
  double expected = 9.7;
  auto reference = poids::ReferenceQuantity<double, kgms::units::AreaUnit>::makeReference(expected);

  kgms::Area actual{reference};

  EXPECT_DOUBLE_EQ(expected, actual.as(meter * meter));
}

TEST(TestQuantityReference, AsConversion) {
  double expected = 9'700;
  double value = 9.7;
  auto actual = poids::ReferenceQuantity<double, kgms::units::LengthUnit>::makeReference(value);

  EXPECT_DOUBLE_EQ(expected, actual.as(milli(meter)));
  EXPECT_DOUBLE_EQ(9.7, value);
}
