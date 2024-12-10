#include <gtest/gtest.h>

#include <type_traits>

#include "poids/kgms/types.hpp"

TEST(TestQuantityArithmetic, Add) {
  kgms::Mass expected = kgms::Mass::makeFromBaseUnitValue(4.53);

  kgms::Mass a = kgms::Mass::makeFromBaseUnitValue(0.54);
  kgms::Mass b = kgms::Mass::makeFromBaseUnitValue(3.99);

  auto actual = a + b;

  EXPECT_TRUE((std::is_same_v<kgms::Mass, decltype(actual)>));
  EXPECT_NEAR(expected.base(), actual.base(), 1e-6);
}

TEST(TestQuantityArithmetic, AddBases) {
  auto expected = poids::makeBase<kgms::Mass>(4.53);

  auto a = poids::makeBase<kgms::Mass>(0.54);
  auto b = poids::makeBase<kgms::Mass>(3.99);

  kgms::Mass::BaseType actual = a + b;

  EXPECT_TRUE((std::is_same_v<kgms::Mass::BaseType, decltype(actual)>));
  EXPECT_NEAR(expected.base(), actual.base(), 1e-6);
}

TEST(TestQuantityArithmetic, AddQuantityBaseQuantity) {
  auto expected = poids::makeBase<kgms::Time>(4.53);

  auto a = kgms::Time::makeFromBaseUnitValue(0.4);
  auto b = poids::makeBase<kgms::Time>(4.13);

  auto actual = a + b;

  EXPECT_TRUE((std::is_same_v<kgms::Time, decltype(actual)>));
  EXPECT_NEAR(expected.base(), actual.base(), 1e-6);
}

TEST(TestQuantityArithmetic, AddBaseQuantityQuantity) {
  auto expected = poids::makeBase<kgms::Time>(4.53);

  auto a = poids::makeBase<kgms::Time>(4.13);
  auto b = kgms::Time::makeFromBaseUnitValue(0.4);

  kgms::Time actual = a + b;

  EXPECT_TRUE((std::is_same_v<kgms::Time, decltype(actual)>));
  EXPECT_NEAR(expected.base(), actual.base(), 1e-6);
}

TEST(TestQuantityArithmetic, Subtract) {
  kgms::Time expected = kgms::Time::makeFromBaseUnitValue(60.0);

  kgms::Time a = kgms::Time::makeFromBaseUnitValue(150.0);
  kgms::Time b = kgms::Time::makeFromBaseUnitValue(90.0);

  auto actual = a - b;

  EXPECT_TRUE((std::is_same_v<kgms::Time, decltype(actual)>));
  EXPECT_NEAR(expected.base(), actual.base(), 1e-6);
}

TEST(TestQuantityArithmetic, SubtractBases) {
  auto expected = poids::makeBase<kgms::Velocity>(10.0);

  auto a = poids::makeBase<kgms::Velocity>(15.5);
  auto b = poids::makeBase<kgms::Velocity>(5.5);

  auto actual = a - b;

  EXPECT_TRUE((std::is_same_v<kgms::Velocity::BaseType, decltype(actual)>));
  EXPECT_NEAR(expected.base(), actual.base(), 1e-6);
}

TEST(TestQuantityArithmetic, MultiplyQuantityQuantity) {
  auto expected = kgms::Area::makeFromBaseUnitValue(12.0);

  auto a = kgms::Length::makeFromBaseUnitValue(3.0);
  auto b = kgms::Length::makeFromBaseUnitValue(4.0);

  kgms::Area actual = a * b;

  EXPECT_TRUE((std::is_same_v<kgms::Area, decltype(actual)>));
  EXPECT_NEAR(expected.base(), actual.base(), 1e-6);
}

TEST(TestQuantityArithmetic, MultiplyQuantityBaseQuantity) {
  auto expected = kgms::Area::makeFromBaseUnitValue(12.0);

  auto a = kgms::Length::makeFromBaseUnitValue(3.0);
  auto b = poids::makeBase<double,
                           kgms::UnitType<std::ratio<0>, std::ratio<1>,
                                          std::ratio<0>>>(4.0);

  kgms::Area actual = a * b;

  EXPECT_TRUE((std::is_same_v<kgms::Area, decltype(actual)>));
  EXPECT_NEAR(expected.base(), actual.base(), 1e-6);
}

TEST(TestQuantityArithmetic, MultiplyBaseQuantityBaseQuantity) {
  auto expected = poids::makeBase<kgms::SecondMomentOfArea>(12.0);

  auto a = poids::makeBase<kgms::Area>(4.0);
  auto b = poids::makeBase<kgms::Area>(3.0);

  auto actual = a * b;

  EXPECT_TRUE((std::is_same_v<kgms::SecondMomentOfArea::BaseType, decltype(actual)>));
  EXPECT_NEAR(expected.base(), actual.base(), 1e-6);
}

TEST(TestQuantityArithmetic, MultiplyBaseQuantityQuantity) {
  auto expected = kgms::Length::makeFromBaseUnitValue(12.0);

  auto a = poids::makeBase<kgms::Velocity>(4.0);
  auto b = kgms::Time::makeFromBaseUnitValue(3.0);

  kgms::Length actual = a * b;

  EXPECT_TRUE((std::is_same_v<kgms::Length, decltype(actual)>));
  EXPECT_NEAR(expected.base(), actual.base(), 1e-6);
}

TEST(TestQuantityArithmetic, DivideQuantityQuantity) {
  auto expected = kgms::Area::makeFromBaseUnitValue(3.0);

  auto a = kgms::Volume::makeFromBaseUnitValue(15.0);
  auto b = kgms::Length::makeFromBaseUnitValue(5.0);

  kgms::Area actual = a / b;

  EXPECT_TRUE((std::is_same_v<kgms::Area, decltype(actual)>));
  EXPECT_NEAR(expected.base(), actual.base(), 1e-6);
}

TEST(TestQuantityArithmetic, DivideBaseQuantityBaseQuantity) {
  auto expected = poids::makeBase<kgms::Velocity>(30.0);

  auto a = poids::makeBase<kgms::Length>(90.0);
  auto b = poids::makeBase<kgms::Time>(3.0);

  auto actual = a / b;

  EXPECT_TRUE((std::is_same_v<kgms::Velocity::BaseType, decltype(actual)>));
  EXPECT_NEAR(expected.base(), actual.base(), 1e-6);
}

TEST(TestQuantityArithmetic, DivideQuantityBaseQuantity) {
  auto expected = kgms::Acceleration::makeFromBaseUnitValue(30.0);

  auto a = kgms::Velocity::makeFromBaseUnitValue(90.0);
  auto b = poids::makeBase<kgms::Time>(3.0);

  auto actual = a / b;

  EXPECT_TRUE((std::is_same_v<kgms::Acceleration, decltype(actual)>));
  EXPECT_NEAR(expected.base(), actual.base(), 1e-6);
}

TEST(TestQuantityArithmetic, DivideBaseQuantityQuantity) {
  auto expected = kgms::Acceleration::makeFromBaseUnitValue(45.0);

  auto a = poids::makeBase<kgms::Force>(90.0);
  auto b = kgms::Mass::makeFromBaseUnitValue(2.0);

  auto actual = a / b;

  EXPECT_TRUE((std::is_same_v<kgms::Acceleration, decltype(actual)>));
  EXPECT_NEAR(expected.base(), actual.base(), 1e-6);
}
