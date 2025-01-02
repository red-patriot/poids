#include <gtest/gtest.h>

#include "poids/si.hpp"
#include "poids/scalar_support/eigen_vector.hpp"

using Eigen::Vector2d;
using Eigen::Vector3d;
using Eigen::Vector4d;
using poids::square;

using namespace si::units;
using namespace si::prefix;

TEST(TestVectorArithmetic, UnaryMinus) {
  poids::Vector<si::Volume, 2> expected{Vector2d{-0.1, -0.2} * meter3};

  poids::Vector<si::Volume, 2> a{Vector2d{0.1, 0.2} * meter3};

  poids::Vector<si::Volume, 2> actual{-a};

  EXPECT_TRUE(expected.isApprox(actual));
}

TEST(TestVectorArithmetic, AddVectorVector) {
  poids::Vector<si::Length, 2> expected{Vector2d{4.0, 6.0} * kilo(meter)};

  poids::Vector<si::Length, 2> a{Vector2d{1.0, 2.0} * kilo(meter)};
  poids::Vector<si::Length, 2> b{Vector2d{3.0, 4.0} * kilo(meter)};

  poids::Vector<si::Length, 2> actual{a + b};

  EXPECT_TRUE(expected.isApprox(actual));
}

TEST(TestVectorArithmetic, SubtractVectorVector) {
  poids::Vector<si::Area, 2> expected{Vector2d{12.0, -6.0} * meter2};

  poids::Vector<si::Area, 2> a{Vector2d{15.0, 2.0} * meter2};
  poids::Vector<si::Area, 2> b{Vector2d{3.0, 8.0} * meter2};

  poids::Vector<si::Area, 2> actual{a - b};

  EXPECT_TRUE(expected.isApprox(actual));
}

//! Vector * Vector multiplication can result in matrix types, which are not yet
//! supported, so don't support this operation yet.
// TODO: Implement Vector * Vector multiplication in the future.

TEST(TestVectorArithmetic, MultiplyVectorQuantity) {
  poids::Vector<si::Force, 3> expected{Vector3d{2.0, 6.0, 12.0} * kilo(newton)};

  poids::Vector<si::Acceleration, 3> a{Vector3d{1.0, 3.0, 6.0} * kilo(meter) / square(second)};
  si::Mass b{2 * kilogram};

  poids::Vector<si::Force, 3> actual{a * b};

  EXPECT_TRUE(expected.isApprox(actual));
}

TEST(TestVectorArithmetic, MultiplyQuantityVector) {
  poids::Vector<si::Force, 3> expected{Vector3d{-150.0, 60.0, 1.2} * kilo(newton)};

  si::Mass b{-3 * kilogram};
  poids::Vector<si::Acceleration, 3> a{Vector3d{50.0, -20.0, -0.4} * kilo(meter) / square(second)};

  poids::Vector<si::Force, 3> actual{a * b};

  EXPECT_TRUE(expected.isApprox(actual));
}

TEST(TestVectorArithmetic, DivideVectorQuantity) {
  poids::Vector<si::Volume, 4> expected{Vector4d{10.0, 2.0, 30.0, 40.0} * meter3};

  poids::Vector<si::SecondMomentOfArea, 4> a{Vector4d{100.0, 20.0, 300.0, 400.0} * meter4};
  si::Length b{10 * meter};

  poids::Vector<si::Volume, 4> actual{a / b};

  EXPECT_TRUE(expected.isApprox(actual));
}

TEST(TestVectorArithmetic, PlusEqual) {
  poids::Vector<si::Mass, 4> expected{Vector4d{1.0, 2.5, 3.4, 4.8} * kilogram};

  poids::Vector<si::Mass, 4> actual{Vector4d{1.0, 1.5, 1.4, 5.8} * kilogram};
  actual += (Vector4d{0.0, 1.0, 2.0, -1.0} * kilogram);

  EXPECT_TRUE(expected.isApprox(actual, milli(gram)));
}

TEST(TestVectorArithmetic, MinusEqual) {
  poids::Vector<si::Mass, 4> expected{Vector4d{1.0, 0.5, -0.6, 6.8} * kilogram};

  poids::Vector<si::Mass, 4> actual{Vector4d{1.0, 1.5, 1.4, 5.8} * kilogram};
  actual -= (Vector4d{0.0, 1.0, 2.0, -1.0} * kilogram);

  EXPECT_TRUE(expected.isApprox(actual, milli(gram)));
}

TEST(TestVectorArithmetic, TimesEqual) {
  auto minute = 60 * second;
  poids::Vector<si::Time, 2> expected{Vector2d{90.0, 6.0} * minute};

  poids::Vector<si::Time, 2> actual{Vector2d{3'600.0, 240.0} * second};
  actual *= 1.5;

  EXPECT_TRUE(expected.isApprox(actual, milli(second)));
}

TEST(TestVectorArithmetic, DivideEqual) {
  poids::Vector<si::Time, 2> expected{Vector2d{8.0, 9.0} * second};

  poids::Vector<si::Time, 2> actual{Vector2d{60.8, 68.4} * second};
  actual /= 7.6;

  EXPECT_TRUE(expected.isApprox(actual, milli(second)));
}
