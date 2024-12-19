#include <gtest/gtest.h>

#include "poids/kgms.hpp"
#include "poids/kgms/eigen_support.hpp"

using Eigen::Vector2d;
using Eigen::Vector3d;
using Eigen::Vector4d;
using poids::square;

using namespace kgms::base;

TEST(TestVectorArithmetic, AddVectorVector) {
  kgms::LengthVector<2> expected{Vector2d{4.0, 6.0} * kilo(meter)};

  kgms::LengthVector<2> a{Vector2d{1.0, 2.0} * kilo(meter)};
  kgms::LengthVector<2> b{Vector2d{3.0, 4.0} * kilo(meter)};

  kgms::LengthVector<2> actual{a + b};

  EXPECT_TRUE(expected.isApprox(actual));
}

TEST(TestVectorArithmetic, SubtractVectorVector) {
  kgms::AreaVector<2> expected{Vector2d{12.0, -6.0} * meter2};

  kgms::AreaVector<2> a{Vector2d{15.0, 2.0} * meter2};
  kgms::AreaVector<2> b{Vector2d{3.0, 8.0} * meter2};

  kgms::AreaVector<2> actual{a - b};

  EXPECT_TRUE(expected.isApprox(actual));
}

//! Vector * Vector multiplication can result in matrix types, which are not yet
//! supported, so don't support this operation yet.
// TODO: Implement Vector * Vector multiplication in the future.

TEST(TestVectorArithmetic, MultiplyVectorQuantity) {
  kgms::ForceVector<3> expected{Vector3d{2.0, 6.0, 12.0} * kilo(newton)};

  kgms::AccelerationVector<3> a{Vector3d{1.0, 3.0, 6.0} * kilo(meter) / square(second)};
  kgms::Mass b{2 * kilogram};

  kgms::ForceVector<3> actual{a * b};

  EXPECT_TRUE(expected.isApprox(actual));
}

TEST(TestVectorArithmetic, MultiplyQuantityVector) {
  kgms::ForceVector<3> expected{Vector3d{-150.0, 60.0, 1.2} * kilo(newton)};

  kgms::Mass b{-3 * kilogram};
  kgms::AccelerationVector<3> a{Vector3d{50.0, -20.0, -0.4} * kilo(meter) / square(second)};

  kgms::ForceVector<3> actual{a * b};

  EXPECT_TRUE(expected.isApprox(actual));
}

TEST(TestVectorArithmetic, DivideVectorQuantity) {
  kgms::VolumeVector<4> expected{Vector4d{10.0, 2.0, 30.0, 40.0} * meter3};

  kgms::SecondMomentOfAreaVector<4> a{Vector4d{100.0, 20.0, 300.0, 400.0} * meter4};
  kgms::Length b{10 * meter};

  kgms::VolumeVector<4> actual{a / b};

  EXPECT_TRUE(expected.isApprox(actual));
}
