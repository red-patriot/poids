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
