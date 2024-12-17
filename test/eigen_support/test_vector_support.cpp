#include <eigen3/Eigen/Core>
#include <gtest/gtest.h>

#include "poids/kgms.hpp"
#include "poids/scalar_support/eigen_vector.hpp"

TEST(TestEigenSupport, ConstructExplicitly) {
  Eigen::Vector2d expected{3.4, 0.56};

  auto actual = poids::Quantity<Eigen::Vector2d,
                                kgms::units::AreaUnit>::makeFromBaseUnitValue({3.4, 0.56});

  EXPECT_TRUE(expected.isApprox(actual.base(), 1e-6));
}
