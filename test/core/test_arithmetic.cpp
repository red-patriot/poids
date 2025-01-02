#include <gtest/gtest.h>

#include <type_traits>

#include "poids/si.hpp"

TEST(TestQuantityArithmetic, UnaryMinus) {
  si::Density expected = si::Density::makeFromBaseUnitValue(-10.8);

  si::Density value = si::Density::makeFromBaseUnitValue(10.8);

  auto actual = -value;

  EXPECT_TRUE((std::is_same_v<si::Density, decltype(actual)>));
  EXPECT_NEAR(expected.base(), actual.base(), 1e-6);
}

TEST(TestQuantityArithmetic, UnaryPlus) {
  si::Volume expected = si::Volume::makeFromBaseUnitValue(46.5812);

  si::Volume value = si::Volume::makeFromBaseUnitValue(46.5812);

  auto actual = +value;

  EXPECT_TRUE((std::is_same_v<si::Volume, decltype(actual)>));
  EXPECT_NEAR(expected.base(), actual.base(), 1e-6);
}

TEST(TestQuantityArithmetic, Add) {
  si::Mass expected = si::Mass::makeFromBaseUnitValue(4.53);

  si::Mass a = si::Mass::makeFromBaseUnitValue(0.54);
  si::Mass b = si::Mass::makeFromBaseUnitValue(3.99);

  auto actual = a + b;

  EXPECT_TRUE((std::is_same_v<si::Mass, decltype(actual)>));
  EXPECT_NEAR(expected.base(), actual.base(), 1e-6);
}

TEST(TestQuantityArithmetic, AddBases) {
  auto expected = poids::makeBase<si::Mass>(4.53);

  auto a = poids::makeBase<si::Mass>(0.54);
  auto b = poids::makeBase<si::Mass>(3.99);

  auto actual = a + b;

  EXPECT_TRUE((std::is_same_v<si::Mass::BaseType, decltype(actual)>));
  EXPECT_NEAR(expected.base(), actual.base(), 1e-6);
}

TEST(TestQuantityArithmetic, AddQuantityBaseQuantity) {
  auto expected = poids::makeBase<si::Time>(4.53);

  auto a = si::Time::makeFromBaseUnitValue(0.4);
  auto b = poids::makeBase<si::Time>(4.13);

  auto actual = a + b;

  EXPECT_TRUE((std::is_same_v<si::Time, decltype(actual)>));
  EXPECT_NEAR(expected.base(), actual.base(), 1e-6);
}

TEST(TestQuantityArithmetic, AddBaseQuantityQuantity) {
  auto expected = poids::makeBase<si::Time>(4.53);

  auto a = poids::makeBase<si::Time>(4.13);
  auto b = si::Time::makeFromBaseUnitValue(0.4);

  si::Time actual = a + b;

  EXPECT_TRUE((std::is_same_v<si::Time, decltype(actual)>));
  EXPECT_NEAR(expected.base(), actual.base(), 1e-6);
}

TEST(TestQuantityArithmetic, Subtract) {
  si::Time expected = si::Time::makeFromBaseUnitValue(60.0);

  si::Time a = si::Time::makeFromBaseUnitValue(150.0);
  si::Time b = si::Time::makeFromBaseUnitValue(90.0);

  auto actual = a - b;

  EXPECT_TRUE((std::is_same_v<si::Time, decltype(actual)>));
  EXPECT_NEAR(expected.base(), actual.base(), 1e-6);
}

TEST(TestQuantityArithmetic, SubtractBases) {
  auto expected = poids::makeBase<si::Velocity>(10.0);

  auto a = poids::makeBase<si::Velocity>(15.5);
  auto b = poids::makeBase<si::Velocity>(5.5);

  auto actual = a - b;

  EXPECT_TRUE((std::is_same_v<si::Velocity::BaseType, decltype(actual)>));
  EXPECT_NEAR(expected.base(), actual.base(), 1e-6);
}

TEST(TestQuantityArithmetic, MultiplyQuantityQuantity) {
  auto expected = si::Area::makeFromBaseUnitValue(12.0);

  auto a = si::Length::makeFromBaseUnitValue(3.0);
  auto b = si::Length::makeFromBaseUnitValue(4.0);

  si::Area actual = a * b;

  EXPECT_TRUE((std::is_same_v<si::Area, decltype(actual)>));
  EXPECT_NEAR(expected.base(), actual.base(), 1e-6);
}

TEST(TestQuantityArithmetic, MultiplyQuantityBaseQuantity) {
  auto expected = si::Area::makeFromBaseUnitValue(12.0);

  auto a = si::Length::makeFromBaseUnitValue(3.0);
  auto b = poids::makeBase<double,
                           si::UnitType<std::ratio<0>, std::ratio<1>,
                                        std::ratio<0>>>(4.0);

  si::Area actual = a * b;

  EXPECT_TRUE((std::is_same_v<si::Area, decltype(actual)>));
  EXPECT_NEAR(expected.base(), actual.base(), 1e-6);
}

TEST(TestQuantityArithmetic, MultiplyBaseQuantityBaseQuantity) {
  auto expected = poids::makeBase<si::SecondMomentOfArea>(12.0);

  auto a = poids::makeBase<si::Area>(4.0);
  auto b = poids::makeBase<si::Area>(3.0);

  auto actual = a * b;

  EXPECT_TRUE((std::is_same_v<si::SecondMomentOfArea::BaseType, decltype(actual)>));
  EXPECT_NEAR(expected.base(), actual.base(), 1e-6);
}

TEST(TestQuantityArithmetic, MultiplyBaseQuantityQuantity) {
  auto expected = si::Length::makeFromBaseUnitValue(12.0);

  auto a = poids::makeBase<si::Velocity>(4.0);
  auto b = si::Time::makeFromBaseUnitValue(3.0);

  si::Length actual = a * b;

  EXPECT_TRUE((std::is_same_v<si::Length, decltype(actual)>));
  EXPECT_NEAR(expected.base(), actual.base(), 1e-6);
}

TEST(TestQuantityArithmetic, MultiplyQuantityScalar) {
  auto expected = si::Mass::makeFromBaseUnitValue(14.0);

  auto a = si::Mass::makeFromBaseUnitValue(7.0);
  double b = 2.0;

  auto actual = a * b;

  EXPECT_TRUE((std::is_same_v<si::Mass, decltype(actual)>));
  EXPECT_NEAR(expected.base(), actual.base(), 1e-6);
}

TEST(TestQuantityArithmetic, MultiplyScalarQuantity) {
  auto expected = si::Energy::makeFromBaseUnitValue(14.0);

  double a = 2.0;
  auto b = si::Energy::makeFromBaseUnitValue(7.0);

  auto actual = a * b;

  EXPECT_TRUE((std::is_same_v<si::Energy, decltype(actual)>));
  EXPECT_NEAR(expected.base(), actual.base(), 1e-6);
}

TEST(TestQuantityArithmetic, MultiplyBaseQuantityScalar) {
  auto expected = si::Time::makeFromBaseUnitValue(63.0);

  auto a = poids::makeBase<si::Time>(9.0);
  double b = 7.0;

  auto actual = a * b;

  EXPECT_TRUE((std::is_same_v<si::Time, decltype(actual)>));
  EXPECT_NEAR(expected.base(), actual.base(), 1e-6);
}

TEST(TestQuantityArithmetic, MultiplyScalarBaseQuantity) {
  auto expected = si::Time::makeFromBaseUnitValue(63.0);

  double a = 7.0;
  auto b = poids::makeBase<si::Time>(9.0);

  auto actual = a * b;

  EXPECT_TRUE((std::is_same_v<si::Time, decltype(actual)>));
  EXPECT_NEAR(expected.base(), actual.base(), 1e-6);
}

TEST(TestQuantityArithmetic, DivideQuantityQuantity) {
  auto expected = si::Area::makeFromBaseUnitValue(3.0);

  auto a = si::Volume::makeFromBaseUnitValue(15.0);
  auto b = si::Length::makeFromBaseUnitValue(5.0);

  si::Area actual = a / b;

  EXPECT_TRUE((std::is_same_v<si::Area, decltype(actual)>));
  EXPECT_NEAR(expected.base(), actual.base(), 1e-6);
}

TEST(TestQuantityArithmetic, DivideBaseQuantityBaseQuantity) {
  auto expected = poids::makeBase<si::Velocity>(30.0);

  auto a = poids::makeBase<si::Length>(90.0);
  auto b = poids::makeBase<si::Time>(3.0);

  auto actual = a / b;

  EXPECT_TRUE((std::is_same_v<si::Velocity::BaseType, decltype(actual)>));
  EXPECT_NEAR(expected.base(), actual.base(), 1e-6);
}

TEST(TestQuantityArithmetic, DivideQuantityBaseQuantity) {
  auto expected = si::Acceleration::makeFromBaseUnitValue(30.0);

  auto a = si::Velocity::makeFromBaseUnitValue(90.0);
  auto b = poids::makeBase<si::Time>(3.0);

  auto actual = a / b;

  EXPECT_TRUE((std::is_same_v<si::Acceleration, decltype(actual)>));
  EXPECT_NEAR(expected.base(), actual.base(), 1e-6);
}

TEST(TestQuantityArithmetic, DivideBaseQuantityQuantity) {
  auto expected = si::Acceleration::makeFromBaseUnitValue(45.0);

  auto a = poids::makeBase<si::Force>(90.0);
  auto b = si::Mass::makeFromBaseUnitValue(2.0);

  auto actual = a / b;

  EXPECT_TRUE((std::is_same_v<si::Acceleration, decltype(actual)>));
  EXPECT_NEAR(expected.base(), actual.base(), 1e-6);
}

TEST(TestQuantityArithmetic, DivideQuantityScalar) {
  auto expected = si::Time::makeFromBaseUnitValue(12.0);

  auto a = si::Time::makeFromBaseUnitValue(48.0);
  double b = 4.0;

  auto actual = a / b;

  EXPECT_TRUE((std::is_same_v<si::Time, decltype(actual)>));
  EXPECT_NEAR(expected.base(), actual.base(), 1e-6);
}

TEST(TestQuantityArithmetic, DivideScalarQuantity) {
  auto expected = si::Frequency::makeFromBaseUnitValue(0.5);

  double a = 4.0;
  auto b = si::Time::makeFromBaseUnitValue(8.0);

  //! NOTE: In order to divide a Scalar by a Quantity, wrap the scalar in a Unitless first
  auto actual = si::Unitless{a} / b;

  EXPECT_TRUE((std::is_same_v<si::Frequency, decltype(actual)>));
  EXPECT_NEAR(expected.base(), actual.base(), 1e-6);
}

TEST(TestQuantityArithmetic, DivideBaseQuantityScalar) {
  auto expected = si::Volume::makeFromBaseUnitValue(4.5);

  auto a = poids::makeBase<si::Volume>(9.0);
  double b = 2.0;

  auto actual = a / b;

  EXPECT_TRUE((std::is_same_v<si::Volume, decltype(actual)>));
  EXPECT_NEAR(expected.base(), actual.base(), 1e-6);
}

TEST(TestQuantityArithmetic, DivideScalarBaseQuantity) {
  auto expected = si::Frequency::makeFromBaseUnitValue(0.5);

  double a = 4.0;
  auto b = poids::makeBase<si::Time>(8.0);

  //! NOTE: In order to divide a Scalar by a Quantity, wrap the scalar in a Unitless first
  auto actual = si::Unitless{a} / b;

  EXPECT_TRUE((std::is_same_v<si::Frequency, decltype(actual)>));
  EXPECT_NEAR(expected.base(), actual.base(), 1e-6);
}

TEST(TestQuantityArithmetic, DivideQuantityWithSelf) {
  double expected = 10.0;

  auto a = si::Length::makeFromBaseUnitValue(100.0);
  auto b = si::Length::makeFromBaseUnitValue(10.0);

  double actual{a / b};

  EXPECT_NEAR(expected, actual, 1e-6);
}

TEST(TestQuantityArithmetic, Pow) {
  using ExpectedUnit = si::combine_units_t<si::LengthUnit<2, 3>,
                                           si::TimeUnit<-4, 3>>;

  auto expected = poids::Quantity<double, ExpectedUnit>::makeFromBaseUnitValue(16.0);

  auto a = si::Acceleration::makeFromBaseUnitValue(64.0);

  auto actual = poids::pow<2, 3>(a);

  EXPECT_TRUE((std::is_same_v<decltype(expected), decltype(actual)>));
  EXPECT_NEAR(expected.base(), actual.base(), 1e-6);
}

TEST(TestQuantityArithmetic, Square) {
  auto expected = si::Area::makeFromBaseUnitValue(25.0);

  auto a = si::Length::makeFromBaseUnitValue(5.0);

  auto actual = poids::square(a);

  EXPECT_TRUE((std::is_same_v<si::Area, decltype(actual)>));
  EXPECT_NEAR(expected.base(), actual.base(), 1e-6);
}

TEST(TestQuantityArithmetic, Sqrt) {
  auto expected = si::Area::makeFromBaseUnitValue(15.0);

  auto a = si::SecondMomentOfArea::makeFromBaseUnitValue(225.0);

  auto actual = poids::sqrt(a);

  EXPECT_TRUE((std::is_same_v<si::Area, decltype(actual)>));
  EXPECT_NEAR(expected.base(), actual.base(), 1e-6);
}

TEST(TestQuantityArithmetic, IncrementPre) {
  auto expected = si::Force::makeFromBaseUnitValue(2.5);

  auto actualInPlace = si::Force::makeFromBaseUnitValue(1.5);

  auto actualReturned = ++actualInPlace;

  EXPECT_TRUE((std::is_same_v<si::Force, decltype(actualInPlace)>));
  EXPECT_NEAR(expected.base(), actualInPlace.base(), 1e-6);

  EXPECT_TRUE((std::is_same_v<si::Force, decltype(actualReturned)>));
  EXPECT_NEAR(expected.base(), actualReturned.base(), 1e-6);
}

TEST(TestQuantityArithmetic, IncrementPost) {
  auto expectedInPlace = si::Time::makeFromBaseUnitValue(2.5);
  auto expectedReturn = si::Time::makeFromBaseUnitValue(1.5);

  auto actualInPlace = si::Time::makeFromBaseUnitValue(1.5);

  auto actualReturned = actualInPlace++;

  EXPECT_TRUE((std::is_same_v<si::Time, decltype(actualInPlace)>));
  EXPECT_NEAR(expectedInPlace.base(), actualInPlace.base(), 1e-6);

  EXPECT_TRUE((std::is_same_v<si::Time, decltype(actualReturned)>));
  EXPECT_NEAR(expectedReturn.base(), actualReturned.base(), 1e-6);
}

TEST(TestQuantityArithmetic, DecrementPre) {
  auto expected = si::Frequency::makeFromBaseUnitValue(-8.5);

  auto actualInPlace = si::Frequency::makeFromBaseUnitValue(-7.5);

  auto actualReturned = --actualInPlace;

  EXPECT_TRUE((std::is_same_v<si::Frequency, decltype(actualInPlace)>));
  EXPECT_NEAR(expected.base(), actualInPlace.base(), 1e-6);

  EXPECT_TRUE((std::is_same_v<si::Frequency, decltype(actualReturned)>));
  EXPECT_NEAR(expected.base(), actualReturned.base(), 1e-6);
}

TEST(TestQuantityArithmetic, DecrementPost) {
  auto expectedInPlace = si::Length::makeFromBaseUnitValue(10.0);
  auto expectedReturn = si::Length::makeFromBaseUnitValue(11.0);

  auto actualInPlace = si::Length::makeFromBaseUnitValue(11.0);

  auto actualReturned = actualInPlace--;

  EXPECT_TRUE((std::is_same_v<si::Length, decltype(actualInPlace)>));
  EXPECT_NEAR(expectedInPlace.base(), actualInPlace.base(), 1e-6);

  EXPECT_TRUE((std::is_same_v<si::Length, decltype(actualReturned)>));
  EXPECT_NEAR(expectedReturn.base(), actualReturned.base(), 1e-6);
}

TEST(TestQuantityArithmetic, PlusEqual) {
  auto expected = si::Density::makeFromBaseUnitValue(14.5);

  auto actual = si::Density::makeFromBaseUnitValue(12.0);
  actual += si::Density::makeFromBaseUnitValue(2.5);

  EXPECT_NEAR(expected.base(), actual.base(), 1e-6);
}

TEST(TestQuantityArithmetic, MinusEqual) {
  auto expected = si::Power::makeFromBaseUnitValue(27.643);

  auto actual = si::Power::makeFromBaseUnitValue(94.7);
  actual -= si::Power::makeFromBaseUnitValue(67.057);

  EXPECT_NEAR(expected.base(), actual.base(), 1e-6);
}

TEST(TestQuantityArithmetic, TimesEqual) {
  auto expected = si::Acceleration::makeFromBaseUnitValue(18.5);

  auto actual = si::Acceleration::makeFromBaseUnitValue(9.25);
  actual *= 2.0;

  EXPECT_NEAR(expected.base(), actual.base(), 1e-6);
}

TEST(TestQuantityArithmetic, DivideEqual) {
  auto expected = si::Acceleration::makeFromBaseUnitValue(12.0);

  auto actual = si::Acceleration::makeFromBaseUnitValue(36.0);
  actual /= 3.0;

  EXPECT_NEAR(expected.base(), actual.base(), 1e-6);
}
