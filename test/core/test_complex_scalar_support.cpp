#include <gtest/gtest.h>

#include <complex>
#include <type_traits>

#include "poids/scalar_support/complex.hpp"
#include "poids/si.hpp"

using namespace std::complex_literals;
using CpxDbl = std::complex<double>;

TEST(TestComplexSupport, FactoryConstruct) {
  std::complex<double> expected = 3.0 + 1i;

  auto actual = si::LengthOf<std::complex<double>>::makeFromBaseUnitValue(3.0 + 1.0i);

  EXPECT_EQ(expected, actual.base());
}

TEST(TestComplexSupport, CreateWithBase) {
  std::complex<double> expected = 3.0 + 1i;

  auto actual = (3.0 + 1.0i) * si::base::meter;

  EXPECT_DOUBLE_EQ(expected.real(), actual.realBase());
  EXPECT_DOUBLE_EQ(expected.imag(), actual.imagBase());
}

TEST(TestComplexSupport, GetRealBaseValue) {
  double expected = 15.6;
  auto quantity = si::TimeOf<CpxDbl>::makeFromBaseUnitValue(15.6 - 9.5i);

  auto actual = quantity.realBase();

  EXPECT_DOUBLE_EQ(expected, actual);
}

TEST(TestComplexSupport, GetImaginaryBaseValue) {
  double expected = -9.5;
  auto quantity = si::SolidAngleOf<CpxDbl>::makeFromBaseUnitValue(15.6 - 9.5i);

  auto actual = quantity.imagBase();

  EXPECT_DOUBLE_EQ(expected, actual);
}

TEST(TestComplexSupport, GetRealPart) {
  double expected = 4.0;
  const si::AreaOf<CpxDbl> quantity = (4.0 + 5i) * si::units::meter2;

  auto actual = quantity.real();

  EXPECT_TRUE((std::is_same_v<si::Area, decltype(actual)>));
  EXPECT_DOUBLE_EQ(expected, actual.as(si::units::meter2));
}

TEST(TestComplexSupport, GetImaginaryPart) {
  double expected = 5.0;
  using namespace si::base;

  si::VelocityOf<CpxDbl> quantity = (4.0 + 5i) * (meter / second);

  auto actual = quantity.imag();

  EXPECT_TRUE((std::is_same_v<si::Velocity, decltype(actual)>));
  EXPECT_DOUBLE_EQ(expected, actual.as(meter / second));
}

TEST(TestComplexSupport, GetRealPartInPlace) {
  using namespace si::base;
  si::Mass expected = 4.0 * kilogram;

  auto quantity = (2.0 + 3i) * kilogram;

  quantity.realm() = expected;

  si::Mass actual = quantity.real();

  EXPECT_TRUE((std::is_same_v<si::Mass, decltype(actual)>));
  EXPECT_DOUBLE_EQ(expected.base(), actual.as(kilogram));
}

TEST(TestComplexSupport, GetImaginaryPartInPlace) {
  using namespace si::base;
  si::Mass expected = 4.0 * kilogram;

  auto quantity = (2.0 + 3i) * kilogram;

  quantity.imagm() = expected;

  auto actual = quantity.imag();

  EXPECT_TRUE((std::is_same_v<si::Mass, decltype(actual)>));
  EXPECT_DOUBLE_EQ(expected.base(), actual.as(kilogram));
}

TEST(TestComplexArithmeticSupport, AddComplexQuantityComplexQuantity) {
  auto expected = si::VelocityOf<CpxDbl>::makeFromBaseUnitValue(5.6 + 1.0i);

  auto a = si::VelocityOf<CpxDbl>::makeFromBaseUnitValue(2.6 + 0.75i);
  auto b = si::VelocityOf<CpxDbl>::makeFromBaseUnitValue(3.0 + 0.25i);

  auto actual = a + b;

  EXPECT_TRUE((std::is_same_v<si::Velocity::Unit,
                              decltype(actual)::Unit>));
  EXPECT_TRUE((std::is_same_v<std::complex<double>, decltype(actual)::Scalar>));
  EXPECT_NEAR(expected.realBase(), actual.realBase(), 1e-6);
  EXPECT_NEAR(expected.imagBase(), actual.imagBase(), 1e-6);
}

TEST(TestComplexArithmeticSupport, AddComplexQuantityDoubleQuantity) {
  auto expected = si::MassOf<CpxDbl>::makeFromBaseUnitValue(10.5 + 0.5i);

  auto a = si::MassOf<CpxDbl>::makeFromBaseUnitValue(5.0 + 0.5i);
  auto b = si::Mass::makeFromBaseUnitValue(5.5);

  auto actual = a + b;

  EXPECT_TRUE((std::is_same_v<si::Mass::Unit,
                              decltype(actual)::Unit>));
  EXPECT_TRUE((std::is_same_v<std::complex<double>, decltype(actual)::Scalar>));
  EXPECT_NEAR(expected.realBase(), actual.realBase(), 1e-6);
  EXPECT_NEAR(expected.imagBase(), actual.imagBase(), 1e-6);
}

TEST(TestComplexArithmeticSupport, AddDoubleQuantityComplexQuantity) {
  auto expected = si::MassOf<CpxDbl>::makeFromBaseUnitValue(10.5 + 0.5i);

  auto a = 5.5 * si::base::kilogram;
  auto b = si::MassOf<CpxDbl>::makeFromBaseUnitValue(5.0 + 0.5i);

  auto actual = a + b;

  EXPECT_TRUE((std::is_same_v<si::Mass::Unit,
                              decltype(actual)::Unit>));
  EXPECT_TRUE((std::is_same_v<std::complex<double>, decltype(actual)::Scalar>));
  EXPECT_NEAR(expected.realBase(), actual.realBase(), 1e-6);
  EXPECT_NEAR(expected.imagBase(), actual.imagBase(), 1e-6);
}

TEST(TestComplexArithmeticSupport, SubtractComplexQuantityComplexQuantity) {
  auto expected = si::TimeOf<CpxDbl>::makeFromBaseUnitValue(-0.4 + 0.5i);

  auto a = si::TimeOf<CpxDbl>::makeFromBaseUnitValue(2.6 + 0.75i);
  auto b = si::TimeOf<CpxDbl>::makeFromBaseUnitValue(3.0 + 0.25i);

  auto actual = a - b;

  EXPECT_TRUE((std::is_same_v<si::Time::Unit,
                              decltype(actual)::Unit>));
  EXPECT_TRUE((std::is_same_v<std::complex<double>, decltype(actual)::Scalar>));
  EXPECT_NEAR(expected.realBase(), actual.realBase(), 1e-6);
  EXPECT_NEAR(expected.imagBase(), actual.imagBase(), 1e-6);
}

TEST(TestComplexArithmeticSupport, SubtractComplexQuantityDoubleQuantity) {
  auto expected = si::LengthOf<CpxDbl>::makeFromBaseUnitValue(19.5 + 0.5i);

  auto a = si::LengthOf<CpxDbl>::makeFromBaseUnitValue(25.0 + 0.5i);
  auto b = si::Length::makeFromBaseUnitValue(5.5);

  auto actual = a - b;

  EXPECT_TRUE((std::is_same_v<si::Length::Unit,
                              decltype(actual)::Unit>));
  EXPECT_TRUE((std::is_same_v<std::complex<double>, decltype(actual)::Scalar>));
  EXPECT_NEAR(expected.realBase(), actual.realBase(), 1e-6);
  EXPECT_NEAR(expected.imagBase(), actual.imagBase(), 1e-6);
}

TEST(TestComplexArithmeticSupport, SubtractDoubleQuantityComplexQuantity) {
  auto expected = si::MassOf<CpxDbl>::makeFromBaseUnitValue(10.5 - 0.5i);

  auto a = 15.5 * si::base::kilogram;
  auto b = si::MassOf<CpxDbl>::makeFromBaseUnitValue(5.0 + 0.5i);

  auto actual = a - b;

  EXPECT_TRUE((std::is_same_v<si::Mass::Unit,
                              decltype(actual)::Unit>));
  EXPECT_TRUE((std::is_same_v<std::complex<double>, decltype(actual)::Scalar>));
  EXPECT_NEAR(expected.realBase(), actual.realBase(), 1e-6);
  EXPECT_NEAR(expected.imagBase(), actual.imagBase(), 1e-6);
}

TEST(TestComplexArithmeticSupport, MultiplyComplexQuantityComplexQuantity) {
  auto expected = si::EnergyOf<CpxDbl>::makeFromBaseUnitValue(125.0 - 125i);

  auto a = si::LengthOf<CpxDbl>::makeFromBaseUnitValue(5.0 - 15i);
  auto b = si::ForceOf<CpxDbl>::makeFromBaseUnitValue(10.0 + 5i);

  auto actual = a * b;

  EXPECT_TRUE((std::is_same_v<si::Energy::Unit,
                              decltype(actual)::Unit>));
  EXPECT_TRUE((std::is_same_v<std::complex<double>, decltype(actual)::Scalar>));
  EXPECT_NEAR(expected.realBase(), actual.realBase(), 1e-6);
  EXPECT_NEAR(expected.imagBase(), actual.imagBase(), 1e-6);
}

TEST(TestComplexArithmeticSupport, MultiplyComplexQuantityDoubleQuantity) {
  auto expected = si::EnergyOf<CpxDbl>::makeFromBaseUnitValue(50.0 - 150i);

  auto a = si::LengthOf<CpxDbl>::makeFromBaseUnitValue(5.0 - 15i);
  auto b = si::Force::makeFromBaseUnitValue(10.0);

  auto actual = a * b;

  EXPECT_TRUE((std::is_same_v<si::Energy::Unit,
                              decltype(actual)::Unit>));
  EXPECT_TRUE((std::is_same_v<std::complex<double>, decltype(actual)::Scalar>));
  EXPECT_NEAR(expected.realBase(), actual.realBase(), 1e-6);
  EXPECT_NEAR(expected.imagBase(), actual.imagBase(), 1e-6);
}

TEST(TestComplexArithmeticSupport, MultiplyDoubleQuantityComplexQuantity) {
  auto expected = si::AreaOf<CpxDbl>::makeFromBaseUnitValue(5.0 + 5i);

  auto a = si::Length::makeFromBaseUnitValue(2.5);
  auto b = si::LengthOf<CpxDbl>::makeFromBaseUnitValue(2.0 + 2.0i);

  auto actual = a * b;

  EXPECT_TRUE((std::is_same_v<si::Area::Unit,
                              decltype(actual)::Unit>));
  EXPECT_TRUE((std::is_same_v<std::complex<double>, decltype(actual)::Scalar>));
  EXPECT_NEAR(expected.realBase(), actual.realBase(), 1e-6);
  EXPECT_NEAR(expected.imagBase(), actual.imagBase(), 1e-6);
}

TEST(TestComplexArithmeticSupport, MultiplyComplexQuantityComplex) {
  auto expected = si::VolumeOf<CpxDbl>::makeFromBaseUnitValue(125.0 - 125i);

  auto a = si::VolumeOf<CpxDbl>::makeFromBaseUnitValue(5.0 - 15i);
  auto b = (10.0 + 5i);

  auto actual = a * b;

  EXPECT_TRUE((std::is_same_v<si::Volume::Unit,
                              decltype(actual)::Unit>));
  EXPECT_TRUE((std::is_same_v<std::complex<double>, decltype(actual)::Scalar>));
  EXPECT_NEAR(expected.realBase(), actual.realBase(), 1e-6);
  EXPECT_NEAR(expected.imagBase(), actual.imagBase(), 1e-6);
}

TEST(TestComplexArithmeticSupport, MultiplyComplexComplexQuantity) {
  auto expected = si::FrequencyOf<CpxDbl>::makeFromBaseUnitValue(125.0 - 125i);

  auto a = (5.0 - 15i);
  auto b = si::FrequencyOf<CpxDbl>::makeFromBaseUnitValue(10.0 + 5i);

  auto actual = a * b;

  EXPECT_TRUE((std::is_same_v<si::Frequency::Unit,
                              decltype(actual)::Unit>));
  EXPECT_TRUE((std::is_same_v<std::complex<double>, decltype(actual)::Scalar>));
  EXPECT_NEAR(expected.realBase(), actual.realBase(), 1e-6);
  EXPECT_NEAR(expected.imagBase(), actual.imagBase(), 1e-6);
}

TEST(TestComplexArithmeticSupport, MultiplyComplexQuantityDouble) {
  auto expected = si::LengthOf<CpxDbl>::makeFromBaseUnitValue(38.0 - 84.55i);

  auto a = si::LengthOf<CpxDbl>::makeFromBaseUnitValue(4.0 - 8.9i);
  double b = 9.5;

  auto actual = a * b;

  EXPECT_TRUE((std::is_same_v<si::Length::Unit,
                              decltype(actual)::Unit>));
  EXPECT_TRUE((std::is_same_v<std::complex<double>, decltype(actual)::Scalar>));
  EXPECT_NEAR(expected.realBase(), actual.realBase(), 1e-6);
  EXPECT_NEAR(expected.imagBase(), actual.imagBase(), 1e-6);
}

TEST(TestComplexArithmeticSupport, MultiplyDoubleComplexQuantity) {
  auto expected = si::AccelerationOf<CpxDbl>::makeFromBaseUnitValue(64.8 + 72i);

  double a = 12.0;
  auto b = si::AccelerationOf<CpxDbl>::makeFromBaseUnitValue(5.4 + 6i);

  auto actual = a * b;

  EXPECT_TRUE((std::is_same_v<si::Acceleration::Unit,
                              decltype(actual)::Unit>));
  EXPECT_TRUE((std::is_same_v<std::complex<double>, decltype(actual)::Scalar>));
  EXPECT_NEAR(expected.realBase(), actual.realBase(), 1e-6);
  EXPECT_NEAR(expected.imagBase(), actual.imagBase(), 1e-6);
}

TEST(TestComplexArithmeticSupport, DivideComplexQuantityComplexQuantity) {
  auto expected = si::ForceOf<CpxDbl>::makeFromBaseUnitValue(3.5 + 4.5i);

  auto a = si::EnergyOf<CpxDbl>::makeFromBaseUnitValue(8.0 + 1i);
  auto b = si::LengthOf<CpxDbl>::makeFromBaseUnitValue(1.0 - 1i);

  auto actual = a / b;

  EXPECT_TRUE((std::is_same_v<si::Force::Unit,
                              decltype(actual)::Unit>));
  EXPECT_TRUE((std::is_same_v<std::complex<double>, decltype(actual)::Scalar>));
  EXPECT_NEAR(expected.realBase(), actual.realBase(), 1e-6);
  EXPECT_NEAR(expected.imagBase(), actual.imagBase(), 1e-6);
}

TEST(TestComplexArithmeticSupport, DivideComplexQuantityDoubleQuantity) {
  auto expected = si::LengthOf<CpxDbl>::makeFromBaseUnitValue(5.0 - 15i);

  auto a = si::EnergyOf<CpxDbl>::makeFromBaseUnitValue(50.0 - 150i);
  auto b = si::Force::makeFromBaseUnitValue(10.0);

  auto actual = a / b;

  EXPECT_TRUE((std::is_same_v<si::Length::Unit,
                              decltype(actual)::Unit>));
  EXPECT_TRUE((std::is_same_v<std::complex<double>, decltype(actual)::Scalar>));
  EXPECT_NEAR(expected.realBase(), actual.realBase(), 1e-6);
  EXPECT_NEAR(expected.imagBase(), actual.imagBase(), 1e-6);
}

TEST(TestComplexArithmeticSupport, DivideDoubleQuantityComplexQuantity) {
  auto expected = si::AreaOf<CpxDbl>::makeFromBaseUnitValue(0.625 - 0.625i);

  auto a = si::Volume::makeFromBaseUnitValue(2.5);
  auto b = si::LengthOf<CpxDbl>::makeFromBaseUnitValue(2.0 + 2.0i);

  auto actual = a / b;

  EXPECT_TRUE((std::is_same_v<si::Area::Unit,
                              decltype(actual)::Unit>));
  EXPECT_TRUE((std::is_same_v<std::complex<double>, decltype(actual)::Scalar>));
  EXPECT_NEAR(expected.realBase(), actual.realBase(), 1e-6);
  EXPECT_NEAR(expected.imagBase(), actual.imagBase(), 1e-6);
}

TEST(TestComplexArithmeticSupport, DivideComplexQuantityComplex) {
  auto expected = si::VolumeOf<CpxDbl>::makeFromBaseUnitValue(-12.5i);

  auto a = si::VolumeOf<CpxDbl>::makeFromBaseUnitValue(125.0 - 125i);
  auto b = (10.0 + 10i);

  auto actual = a / b;

  EXPECT_TRUE((std::is_same_v<si::Volume::Unit,
                              decltype(actual)::Unit>));
  EXPECT_TRUE((std::is_same_v<std::complex<double>, decltype(actual)::Scalar>));
  EXPECT_NEAR(expected.realBase(), actual.realBase(), 1e-6);
  EXPECT_NEAR(expected.imagBase(), actual.imagBase(), 1e-6);
}

TEST(TestComplexArithmeticSupport, DivideComplexComplexQuantity) {
  auto expected = si::FrequencyOf<CpxDbl>::makeFromBaseUnitValue(-0.2 - 1.4i);

  auto a = (5.0 - 15i);
  auto b = si::TimeOf<CpxDbl>::makeFromBaseUnitValue(10.0 + 5i);

  //! NOTE: In order to divide a Scalar by a Quantity, wrap the scalar in a Unitless first
  auto actual = si::UnitlessOf<std::complex<double>>{a} / b;

  EXPECT_TRUE((std::is_same_v<si::Frequency::Unit,
                              decltype(actual)::Unit>));
  EXPECT_TRUE((std::is_same_v<std::complex<double>, decltype(actual)::Scalar>));
  EXPECT_NEAR(expected.realBase(), actual.realBase(), 1e-6);
  EXPECT_NEAR(expected.imagBase(), actual.imagBase(), 1e-6);
}

TEST(TestComplexArithmeticSupport, DivideComplexQuantityDouble) {
  auto expected = si::LengthOf<CpxDbl>::makeFromBaseUnitValue(2.0 - 4.45i);

  auto a = si::LengthOf<CpxDbl>::makeFromBaseUnitValue(4.0 - 8.9i);
  double b = 2.0;

  auto actual = a / b;

  EXPECT_TRUE((std::is_same_v<si::Length::Unit,
                              decltype(actual)::Unit>));
  EXPECT_TRUE((std::is_same_v<std::complex<double>, decltype(actual)::Scalar>));
  EXPECT_NEAR(expected.realBase(), actual.realBase(), 1e-6);
  EXPECT_NEAR(expected.imagBase(), actual.imagBase(), 1e-6);
}

TEST(TestComplexArithmeticSupport, DivideDoubleComplexQuantity) {
  auto expected = si::FrequencyOf<CpxDbl>::makeFromBaseUnitValue(2.4 - 1.2i);

  double a = 12.0;
  auto b = si::TimeOf<CpxDbl>::makeFromBaseUnitValue(4.0 + 2i);

  //! NOTE: In order to divide a Scalar by a Quantity, wrap the scalar in a Unitless first
  auto actual = si::Unitless{a} / b;

  EXPECT_TRUE((std::is_same_v<si::Frequency::Unit,
                              decltype(actual)::Unit>));
  EXPECT_TRUE((std::is_same_v<std::complex<double>, decltype(actual)::Scalar>));
  EXPECT_NEAR(expected.realBase(), actual.realBase(), 1e-6);
  EXPECT_NEAR(expected.imagBase(), actual.imagBase(), 1e-6);
}
