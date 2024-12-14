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

TEST(TestComplexSupport, MultiplyComplexQuantityComplexQuantity) {
  auto expected = kgms::templates::Energy<CpxDbl>::makeFromBaseUnitValue(125.0 - 125i);

  auto a = kgms::templates::Length<CpxDbl>::makeFromBaseUnitValue(5.0 - 15i);
  auto b = kgms::templates::Force<CpxDbl>::makeFromBaseUnitValue(10.0 + 5i);

  auto actual = a * b;

  EXPECT_TRUE((std::is_same_v<kgms::units::EnergyUnit,
                              decltype(actual)::Unit>));
  EXPECT_TRUE((std::is_same_v<std::complex<double>, decltype(actual)::Scalar>));
  EXPECT_NEAR(expected.real(), actual.real(), 1e-6);
  EXPECT_NEAR(expected.imag(), actual.imag(), 1e-6);
}

TEST(TestComplexSupport, MultiplyComplexQuantityDoubleQuantity) {
  auto expected = kgms::templates::Energy<CpxDbl>::makeFromBaseUnitValue(50.0 - 150i);

  auto a = kgms::templates::Length<CpxDbl>::makeFromBaseUnitValue(5.0 - 15i);
  auto b = kgms::Force::makeFromBaseUnitValue(10.0);

  auto actual = a * b;

  EXPECT_TRUE((std::is_same_v<kgms::units::EnergyUnit,
                              decltype(actual)::Unit>));
  EXPECT_TRUE((std::is_same_v<std::complex<double>, decltype(actual)::Scalar>));
  EXPECT_NEAR(expected.real(), actual.real(), 1e-6);
  EXPECT_NEAR(expected.imag(), actual.imag(), 1e-6);
}

TEST(TestComplexSupport, MultiplyDoubleQuantityComplexQuantity) {
  auto expected = kgms::templates::Area<CpxDbl>::makeFromBaseUnitValue(5.0 + 5i);

  auto a = kgms::Length::makeFromBaseUnitValue(2.5);
  auto b = kgms::templates::Length<CpxDbl>::makeFromBaseUnitValue(2.0 + 2.0i);

  auto actual = a * b;

  EXPECT_TRUE((std::is_same_v<kgms::units::AreaUnit,
                              decltype(actual)::Unit>));
  EXPECT_TRUE((std::is_same_v<std::complex<double>, decltype(actual)::Scalar>));
  EXPECT_NEAR(expected.real(), actual.real(), 1e-6);
  EXPECT_NEAR(expected.imag(), actual.imag(), 1e-6);
}

TEST(TestComplexSupport, MultiplyComplexQuantityComplex) {
  auto expected = kgms::templates::Volume<CpxDbl>::makeFromBaseUnitValue(125.0 - 125i);

  auto a = kgms::templates::Volume<CpxDbl>::makeFromBaseUnitValue(5.0 - 15i);
  auto b = (10.0 + 5i);

  auto actual = a * b;

  EXPECT_TRUE((std::is_same_v<kgms::units::VolumeUnit,
                              decltype(actual)::Unit>));
  EXPECT_TRUE((std::is_same_v<std::complex<double>, decltype(actual)::Scalar>));
  EXPECT_NEAR(expected.real(), actual.real(), 1e-6);
  EXPECT_NEAR(expected.imag(), actual.imag(), 1e-6);
}

TEST(TestComplexSupport, MultiplyComplexComplexQuantity) {
  auto expected = kgms::templates::Frequency<CpxDbl>::makeFromBaseUnitValue(125.0 - 125i);

  auto a = (5.0 - 15i);
  auto b = kgms::templates::Frequency<CpxDbl>::makeFromBaseUnitValue(10.0 + 5i);

  auto actual = a * b;

  EXPECT_TRUE((std::is_same_v<kgms::units::FrequencyUnit,
                              decltype(actual)::Unit>));
  EXPECT_TRUE((std::is_same_v<std::complex<double>, decltype(actual)::Scalar>));
  EXPECT_NEAR(expected.real(), actual.real(), 1e-6);
  EXPECT_NEAR(expected.imag(), actual.imag(), 1e-6);
}

TEST(TestComplexSupport, MultiplyComplexQuantityDouble) {
  auto expected = kgms::templates::Length<CpxDbl>::makeFromBaseUnitValue(38.0 - 84.55i);

  auto a = kgms::templates::Length<CpxDbl>::makeFromBaseUnitValue(4.0 - 8.9i);
  double b = 9.5;

  auto actual = a * b;

  EXPECT_TRUE((std::is_same_v<kgms::units::LengthUnit,
                              decltype(actual)::Unit>));
  EXPECT_TRUE((std::is_same_v<std::complex<double>, decltype(actual)::Scalar>));
  EXPECT_NEAR(expected.real(), actual.real(), 1e-6);
  EXPECT_NEAR(expected.imag(), actual.imag(), 1e-6);
}

TEST(TestComplexSupport, MultiplyDoubleComplexQuantity) {
  auto expected = kgms::templates::Acceleration<CpxDbl>::makeFromBaseUnitValue(64.8 + 72i);

  double a = 12.0;
  auto b = kgms::templates::Acceleration<CpxDbl>::makeFromBaseUnitValue(5.4 + 6i);

  auto actual = a * b;

  EXPECT_TRUE((std::is_same_v<kgms::units::AccelerationUnit,
                              decltype(actual)::Unit>));
  EXPECT_TRUE((std::is_same_v<std::complex<double>, decltype(actual)::Scalar>));
  EXPECT_NEAR(expected.real(), actual.real(), 1e-6);
  EXPECT_NEAR(expected.imag(), actual.imag(), 1e-6);
}

TEST(TestComplexSupport, DivideComplexQuantityComplexQuantity) {
  auto expected = kgms::templates::Force<CpxDbl>::makeFromBaseUnitValue(3.5 + 4.5i);

  auto a = kgms::templates::Energy<CpxDbl>::makeFromBaseUnitValue(8.0 + 1i);
  auto b = kgms::templates::Length<CpxDbl>::makeFromBaseUnitValue(1.0 - 1i);

  auto actual = a / b;

  EXPECT_TRUE((std::is_same_v<kgms::units::ForceUnit,
                              decltype(actual)::Unit>));
  EXPECT_TRUE((std::is_same_v<std::complex<double>, decltype(actual)::Scalar>));
  EXPECT_NEAR(expected.real(), actual.real(), 1e-6);
  EXPECT_NEAR(expected.imag(), actual.imag(), 1e-6);
}

TEST(TestComplexSupport, DivideComplexQuantityDoubleQuantity) {
  auto expected = kgms::templates::Length<CpxDbl>::makeFromBaseUnitValue(5.0 - 15i);

  auto a = kgms::templates::Energy<CpxDbl>::makeFromBaseUnitValue(50.0 - 150i);
  auto b = kgms::Force::makeFromBaseUnitValue(10.0);

  auto actual = a / b;

  EXPECT_TRUE((std::is_same_v<kgms::units::LengthUnit,
                              decltype(actual)::Unit>));
  EXPECT_TRUE((std::is_same_v<std::complex<double>, decltype(actual)::Scalar>));
  EXPECT_NEAR(expected.real(), actual.real(), 1e-6);
  EXPECT_NEAR(expected.imag(), actual.imag(), 1e-6);
}

TEST(TestComplexSupport, DivideDoubleQuantityComplexQuantity) {
  auto expected = kgms::templates::Area<CpxDbl>::makeFromBaseUnitValue(0.625 - 0.625i);

  auto a = kgms::Volume::makeFromBaseUnitValue(2.5);
  auto b = kgms::templates::Length<CpxDbl>::makeFromBaseUnitValue(2.0 + 2.0i);

  auto actual = a / b;

  EXPECT_TRUE((std::is_same_v<kgms::units::AreaUnit,
                              decltype(actual)::Unit>));
  EXPECT_TRUE((std::is_same_v<std::complex<double>, decltype(actual)::Scalar>));
  EXPECT_NEAR(expected.real(), actual.real(), 1e-6);
  EXPECT_NEAR(expected.imag(), actual.imag(), 1e-6);
}

TEST(TestComplexSupport, DivideComplexQuantityComplex) {
  auto expected = kgms::templates::Volume<CpxDbl>::makeFromBaseUnitValue(-12.5i);

  auto a = kgms::templates::Volume<CpxDbl>::makeFromBaseUnitValue(125.0 - 125i);
  auto b = (10.0 + 10i);

  auto actual = a / b;

  EXPECT_TRUE((std::is_same_v<kgms::units::VolumeUnit,
                              decltype(actual)::Unit>));
  EXPECT_TRUE((std::is_same_v<std::complex<double>, decltype(actual)::Scalar>));
  EXPECT_NEAR(expected.real(), actual.real(), 1e-6);
  EXPECT_NEAR(expected.imag(), actual.imag(), 1e-6);
}

TEST(TestComplexSupport, DivideComplexComplexQuantity) {
  auto expected = kgms::templates::Frequency<CpxDbl>::makeFromBaseUnitValue(-0.2 - 1.4i);

  auto a = (5.0 - 15i);
  auto b = kgms::templates::Time<CpxDbl>::makeFromBaseUnitValue(10.0 + 5i);

  //! NOTE: In order to divide a Scalar by a Quantity, wrap the scalar in a Unitless first
  auto actual = kgms::templates::Unitless<std::complex<double>>{a} / b;

  EXPECT_TRUE((std::is_same_v<kgms::units::FrequencyUnit,
                              decltype(actual)::Unit>));
  EXPECT_TRUE((std::is_same_v<std::complex<double>, decltype(actual)::Scalar>));
  EXPECT_NEAR(expected.real(), actual.real(), 1e-6);
  EXPECT_NEAR(expected.imag(), actual.imag(), 1e-6);
}

TEST(TestComplexSupport, DivideComplexQuantityDouble) {
  auto expected = kgms::templates::Length<CpxDbl>::makeFromBaseUnitValue(2.0 - 4.45i);

  auto a = kgms::templates::Length<CpxDbl>::makeFromBaseUnitValue(4.0 - 8.9i);
  double b = 2.0;

  auto actual = a / b;

  EXPECT_TRUE((std::is_same_v<kgms::units::LengthUnit,
                              decltype(actual)::Unit>));
  EXPECT_TRUE((std::is_same_v<std::complex<double>, decltype(actual)::Scalar>));
  EXPECT_NEAR(expected.real(), actual.real(), 1e-6);
  EXPECT_NEAR(expected.imag(), actual.imag(), 1e-6);
}

TEST(TestComplexSupport, DivideDoubleComplexQuantity) {
  auto expected = kgms::templates::Frequency<CpxDbl>::makeFromBaseUnitValue(2.4 - 1.2i);

  double a = 12.0;
  auto b = kgms::templates::Time<CpxDbl>::makeFromBaseUnitValue(4.0 + 2i);

  //! NOTE: In order to divide a Scalar by a Quantity, wrap the scalar in a Unitless first
  auto actual = kgms::Unitless{a} / b;

  EXPECT_TRUE((std::is_same_v<kgms::units::FrequencyUnit,
                              decltype(actual)::Unit>));
  EXPECT_TRUE((std::is_same_v<std::complex<double>, decltype(actual)::Scalar>));
  EXPECT_NEAR(expected.real(), actual.real(), 1e-6);
  EXPECT_NEAR(expected.imag(), actual.imag(), 1e-6);
}
