#include <eigen3/Eigen/Core>
#include <gtest/gtest.h>

#include "poids/kgms.hpp"
#include "poids/kgms/eigen_support.hpp"

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

TEST(TestEigenSupport, AsConversion) {
  kgms::TimeVector<3> expected{Vector3d{1.0, 2.0, 3.0} * second};

  kgms::TimeVector<3> actual{Vector3d{1000.0, 2000.0, 3000.0} * milli(second)};

  EXPECT_TRUE(expected.as(second).isApprox(actual.as(second), 1e-6));
}

TEST(TestEigenSupport, IndexElements) {
  Eigen::Vector<double, 7> expected{1.0, 5.0, 6.0, 12.0, -10.0, 0.0, 8.0};

  const kgms::EnergyVector<7> actual{expected * joule};

  EXPECT_NEAR(expected[0], actual[0].as(joule), 1e-6);
  EXPECT_NEAR(expected[1], actual[1].as(joule), 1e-6);
  EXPECT_NEAR(expected[2], actual[2].as(joule), 1e-6);
  EXPECT_NEAR(expected[3], actual[3].as(joule), 1e-6);
  EXPECT_NEAR(expected[4], actual[4].as(joule), 1e-6);
  EXPECT_NEAR(expected[5], actual[5].as(joule), 1e-6);
  EXPECT_NEAR(expected[6], actual[6].as(joule), 1e-6);
}

TEST(TestEigenSupport, IndexModifyElements) {
  const kgms::LengthVector<5> expected{Eigen::Vector<double, 5>{-0.23, 192.3, 293.4, 5.6, 10.0} * meter};

  kgms::LengthVector<5> actual{Eigen::Vector<double, 5>::Zero() * meter};

  actual[0] = expected[0];
  actual[1] = expected[1];
  actual[2] = expected[2];
  actual[3] = expected[3];
  actual[4] = expected[4];

  EXPECT_DOUBLE_EQ(expected[0].as(meter), actual[0].as(meter));
  EXPECT_DOUBLE_EQ(expected[1].as(meter), actual[1].as(meter));
  EXPECT_DOUBLE_EQ(expected[2].as(meter), actual[2].as(meter));
  EXPECT_DOUBLE_EQ(expected[3].as(meter), actual[3].as(meter));
  EXPECT_DOUBLE_EQ(expected[4].as(meter), actual[4].as(meter));
}
