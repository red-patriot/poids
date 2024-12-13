#include <gtest/gtest.h>

#include <complex>
#include <type_traits>

#include "poids/kgms/units.hpp"
#include "poids/kgms/base.hpp"
#include "poids/scalar_support/complex.hpp"

using namespace std::complex_literals;
using CpxDbl = std::complex<double>;

TEST(TestComplexSupport, FactoryConstruct) {
  std::complex<double> expected = 3.0 + 1i;

  auto actual = kgms::templates::Length<std::complex<double>>::makeFromBaseUnitValue(3.0 + 1.0i);

  EXPECT_EQ(expected, actual.base());
}

// TEST(TestComplexSupport, CreateWithBase) {
//   std::complex<double> expected = 3.0 + 1i;

//   auto actual = (3.0 + 1.0i) * kgms::base::meter;

//   EXPECT_DOUBLE_EQ(expected, actual.base());
// }

TEST(TestComplexSupport, GetRealPart) {
  double expected = 15.6;
  auto quantity = kgms::templates::Time<CpxDbl>::makeFromBaseUnitValue(15.6 - 9.5i);

  auto actual = quantity.real();

  EXPECT_DOUBLE_EQ(expected, actual);
}

TEST(TestComplexSupport, GetImaginaryPart) {
  double expected = -9.5;
  auto quantity = kgms::templates::Force<CpxDbl>::makeFromBaseUnitValue(15.6 - 9.5i);

  auto actual = quantity.imag();

  EXPECT_DOUBLE_EQ(expected, actual);
}

TEST(TestComplexSupport, AddComplexQuantityComplexQuantity) {
  auto expected = kgms::templates::Velocity<CpxDbl>::makeFromBaseUnitValue(5.6 + 1.0i);

  auto a = kgms::templates::Velocity<CpxDbl>::makeFromBaseUnitValue(2.6 + 0.75i);
  auto b = kgms::templates::Velocity<CpxDbl>::makeFromBaseUnitValue(3.0 + 0.25i);

  auto actual = a + b;

  EXPECT_TRUE((std::is_same_v<kgms::units::VelocityUnit,
                              decltype(actual)::Unit>));
  EXPECT_TRUE((std::is_same_v<std::complex<double>, decltype(actual)::Scalar>));
  EXPECT_NEAR(expected.real(), actual.real(), 1e-6);
  EXPECT_NEAR(expected.imag(), actual.imag(), 1e-6);
}

TEST(TestComplexSupport, AddComplexQuantityDoubleQuantity) {
  auto expected = kgms::templates::Mass<CpxDbl>::makeFromBaseUnitValue(10.5 + 0.5i);

  auto a = kgms::templates::Mass<CpxDbl>::makeFromBaseUnitValue(5.0 + 0.5i);
  auto b = kgms::Mass::makeFromBaseUnitValue(5.5);

  auto actual = a + b;

  EXPECT_TRUE((std::is_same_v<kgms::units::MassUnit,
                              decltype(actual)::Unit>));
  EXPECT_TRUE((std::is_same_v<std::complex<double>, decltype(actual)::Scalar>));
  EXPECT_NEAR(expected.real(), actual.real(), 1e-6);
  EXPECT_NEAR(expected.imag(), actual.imag(), 1e-6);
}

TEST(TestComplexSupport, AddDoubleQuantityComplexQuantity) {
  auto expected = kgms::templates::Mass<CpxDbl>::makeFromBaseUnitValue(10.5 + 0.5i);

  auto a = 5.5 * kgms::base::kilogram;
  auto b = kgms::templates::Mass<CpxDbl>::makeFromBaseUnitValue(5.0 + 0.5i);

  auto actual = a + b;

  EXPECT_TRUE((std::is_same_v<kgms::units::MassUnit,
                              decltype(actual)::Unit>));
  EXPECT_TRUE((std::is_same_v<std::complex<double>, decltype(actual)::Scalar>));
  EXPECT_NEAR(expected.real(), actual.real(), 1e-6);
  EXPECT_NEAR(expected.imag(), actual.imag(), 1e-6);
}

TEST(TestComplexSupport, SubtractComplexQuantityComplexQuantity) {
  auto expected = kgms::templates::Time<CpxDbl>::makeFromBaseUnitValue(-0.4 + 0.5i);

  auto a = kgms::templates::Time<CpxDbl>::makeFromBaseUnitValue(2.6 + 0.75i);
  auto b = kgms::templates::Time<CpxDbl>::makeFromBaseUnitValue(3.0 + 0.25i);

  auto actual = a - b;

  EXPECT_TRUE((std::is_same_v<kgms::units::TimeUnit,
                              decltype(actual)::Unit>));
  EXPECT_TRUE((std::is_same_v<std::complex<double>, decltype(actual)::Scalar>));
  EXPECT_NEAR(expected.real(), actual.real(), 1e-6);
  EXPECT_NEAR(expected.imag(), actual.imag(), 1e-6);
}

TEST(TestComplexSupport, SubtractComplexQuantityDoubleQuantity) {
  auto expected = kgms::templates::Length<CpxDbl>::makeFromBaseUnitValue(19.5 + 0.5i);

  auto a = kgms::templates::Length<CpxDbl>::makeFromBaseUnitValue(25.0 + 0.5i);
  auto b = kgms::Length::makeFromBaseUnitValue(5.5);

  auto actual = a - b;

  EXPECT_TRUE((std::is_same_v<kgms::units::LengthUnit,
                              decltype(actual)::Unit>));
  EXPECT_TRUE((std::is_same_v<std::complex<double>, decltype(actual)::Scalar>));
  EXPECT_NEAR(expected.real(), actual.real(), 1e-6);
  EXPECT_NEAR(expected.imag(), actual.imag(), 1e-6);
}

TEST(TestComplexSupport, SubtractDoubleQuantityComplexQuantity) {
  auto expected = kgms::templates::Mass<CpxDbl>::makeFromBaseUnitValue(10.5 - 0.5i);

  auto a = 15.5 * kgms::base::kilogram;
  auto b = kgms::templates::Mass<CpxDbl>::makeFromBaseUnitValue(5.0 + 0.5i);

  auto actual = a - b;

  EXPECT_TRUE((std::is_same_v<kgms::units::MassUnit,
                              decltype(actual)::Unit>));
  EXPECT_TRUE((std::is_same_v<std::complex<double>, decltype(actual)::Scalar>));
  EXPECT_NEAR(expected.real(), actual.real(), 1e-6);
  EXPECT_NEAR(expected.imag(), actual.imag(), 1e-6);
}
