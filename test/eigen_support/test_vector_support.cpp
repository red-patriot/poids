#include <eigen3/Eigen/Core>
#include <gtest/gtest.h>

#include "poids/kgms.hpp"
#include "poids/kgms/eigen_support.hpp"

using Eigen::Vector2d;
using Eigen::Vector3d;
using Eigen::Vector4d;
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

  expected.begin();

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
  kgms::LengthVector<5> expected{Eigen::Vector<double, 5>{-0.23, 192.3, 293.4, 5.6, 10.0} * meter};

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

TEST(TestEigenSupport, Size) {
  kgms::EnergyVector<3> actual{Vector3d{1.0, 0.0, 0.0} * joule};

  EXPECT_EQ(3, actual.size());
}

TEST(TestEigenSupport, GetX) {
  kgms::Mass expected = 1 * mega(gram);

  kgms::MassVector<2> quantity{Vector2d{1.0, 2.0} * mega(gram)};

  kgms::Mass actual{quantity.x()};

  EXPECT_EQ(expected, actual);
}

TEST(TestEigenSupport, GetXConst) {
  kgms::Force expected = 4 * newton;

  const kgms::ForceVector<2> quantity{Vector2d{4.0, 2.0} * newton};

  kgms::Force actual = quantity.x();

  EXPECT_EQ(expected, actual);
}

TEST(TestEigenSupport, SetX) {
  kgms::MassVector<2> expected{Vector2d{1.0, 2.0} * mega(gram)};

  kgms::MassVector<2> actual{Vector2d{0.0, 2.0} * mega(gram)};

  actual.x() = mega(gram);

  EXPECT_TRUE(expected.as(kilogram).isApprox(actual.as(kilogram), 1e-6));
}

TEST(TestEigenSupport, GetY) {
  kgms::Length expected = 4 * mega(meter);

  kgms::LengthVector<3> quantity{Vector3d{2.0, 4.0, 8.0} * mega(meter)};

  kgms::Length actual{quantity.y()};

  EXPECT_EQ(expected, actual);
}

TEST(TestEigenSupport, GetYConst) {
  kgms::Energy expected = 4 * joule;

  const kgms::EnergyVector<2> quantity{Vector2d{2.0, 4.0} * joule};

  kgms::Energy actual = quantity.y();

  EXPECT_EQ(expected, actual);
}

TEST(TestEigenSupport, SetY) {
  kgms::MassVector<4> expected{Vector4d{1.0, 1.0, 1.0, 0.0} * mega(gram)};

  kgms::MassVector<4> actual{Vector4d{1.0, 2.0, 1.0, 0.0} * mega(gram)};

  actual.y() = mega(gram);

  EXPECT_TRUE(expected.as(kilogram).isApprox(actual.as(kilogram), 1e-6));
}

TEST(TestEigenSupport, GetZ) {
  kgms::Mass expected = 1 * mega(gram);

  kgms::MassVector<3> quantity{Vector3d{1.5, 2.0, 1.0} * mega(gram)};

  kgms::Mass actual{quantity.z()};

  EXPECT_EQ(expected, actual);
}

TEST(TestEigenSupport, GetZConst) {
  kgms::Time expected = 1 * minute;

  const kgms::TimeVector<3> quantity{Vector3d{5.0, 2.0, 1.0} * minute};

  kgms::Time actual = quantity.z();

  EXPECT_EQ(expected, actual);
}

TEST(TestEigenSupport, SetZ) {
  kgms::FrequencyVector<4> expected{Vector4d{1.0, 2.0, 12.0, 5.0} * hertz};

  kgms::FrequencyVector<4> actual{Vector4d{1.0, 2.0, 5.0, 5.0} * hertz};

  actual.z() = 12 * hertz;

  EXPECT_TRUE(expected.as(hertz).isApprox(actual.as(hertz), 1e-6));
}

TEST(TestEigenSupport, GetW) {
  kgms::Mass expected = 1 * mega(gram);

  kgms::MassVector<4> quantity{Vector4d{10.0, 2.0, 3.0, 1.0} * mega(gram)};

  kgms::Mass actual = quantity.w();

  EXPECT_EQ(expected, actual);
}

TEST(TestEigenSupport, GetWConst) {
  kgms::Force expected = 4 * newton;

  const kgms::ForceVector<5> quantity{Eigen::Vector<double, 5>{1.0, 2.0, 5.0, 4.0, 8.0} * newton};

  kgms::Force actual = quantity.w();

  EXPECT_EQ(expected, actual);
}

TEST(TestEigenSupport, SetW) {
  kgms::MassVector<4> expected{Vector4d{1.0, 2.0, 1.0, 4.5} * mega(gram)};

  kgms::MassVector<4> actual{Vector4d{1.0, 2.0, 1.0, 0.0} * mega(gram)};

  actual.w() = 4.5 * mega(gram);

  EXPECT_TRUE(expected.as(kilogram).isApprox(actual.as(kilogram), 1e-6));
}
