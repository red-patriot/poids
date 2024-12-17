#include <eigen3/Eigen/Core>
#include <gtest/gtest.h>

#include "poids/kgms.hpp"
#include "poids/scalar_support/eigen_vector.hpp"

using Eigen::Vector2d;
using Eigen::Vector3d;
using poids::square;

using namespace kgms::base;

TEST(TestEigenSupport, ConstructExplicitly) {
  Vector2d expected{3.4, 0.56};

  auto actual = poids::Quantity<Vector2d,
                                kgms::units::AreaUnit>::makeFromBaseUnitValue(3.4, 0.56);

  EXPECT_TRUE(expected.isApprox(actual.base(), 1e-6));
}

TEST(TestEigenSupport, ConstructFromBaseMultiply) {
  auto expected = poids::Quantity<Vector3d,
                                  kgms::units::AccelerationUnit>::makeFromBaseUnitValue(1.2, 3.4, 7.8);

  poids::Quantity<Vector3d,
                  kgms::units::AccelerationUnit>
      actual{Vector3d{1.2, 3.4, 7.8} * (meter / square(second))};

  EXPECT_EQ(expected, actual);
}
