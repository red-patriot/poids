#include <Eigen/Core>
#include <gtest/gtest.h>

#include "poids/si.hpp"
#include "poids/scalar_support/eigen_vector.hpp"

using Eigen::Vector2d;
using Eigen::Vector3d;
using Eigen::Vector4d;
using poids::square;

using namespace si::units;
using namespace si::prefix;

TEST(TestVectorSupport, ConstructExplicitly) {
  Vector2d expected{3.4, 0.56};

  auto actual = poids::Quantity<Vector2d,
                                si::Area::Unit>::makeFromBaseUnitValue(3.4, 0.56);

  EXPECT_TRUE(expected.isApprox(actual.base(), 1e-6));
}

TEST(TestVectorSupport, ConstructFromBaseMultiply) {
  auto expected = poids::Quantity<Vector3d,
                                  si::Acceleration::Unit>::makeFromBaseUnitValue(1.2, 3.4, 7.8);

  poids::Quantity<Vector3d,
                  si::Acceleration::Unit>
      actual{Vector3d{1.2, 3.4, 7.8} * (meter / square(second))};

  EXPECT_EQ(expected, actual);
}

TEST(TestVectorSupport, AsConversion) {
  poids::Vector<si::Time, 3> expected{Vector3d{1.0, 2.0, 3.0} * second};

  poids::Vector<si::Time, 3> actual{Vector3d{1000.0, 2000.0, 3000.0} * milli(second)};

  EXPECT_TRUE(expected.as(second).isApprox(actual.as(second), 1e-6));
}

TEST(TestVectorSupport, IndexElements) {
  Eigen::Vector<double, 7> expected{1.0, 5.0, 6.0, 12.0, -10.0, 0.0, 8.0};

  expected.begin();

  const poids::Vector<si::Energy, 7> actual{expected * joule};

  EXPECT_NEAR(expected[0], actual[0].as(joule), 1e-6);
  EXPECT_NEAR(expected[1], actual[1].as(joule), 1e-6);
  EXPECT_NEAR(expected[2], actual[2].as(joule), 1e-6);
  EXPECT_NEAR(expected[3], actual[3].as(joule), 1e-6);
  EXPECT_NEAR(expected[4], actual[4].as(joule), 1e-6);
  EXPECT_NEAR(expected[5], actual[5].as(joule), 1e-6);
  EXPECT_NEAR(expected[6], actual[6].as(joule), 1e-6);
}

TEST(TestVectorSupport, IndexModifyElements) {
  poids::Vector<si::Length, 5> expected{Eigen::Vector<double, 5>{-0.23, 192.3, 293.4, 5.6, 10.0} * meter};

  poids::Vector<si::Length, 5> actual{Eigen::Vector<double, 5>::Zero() * meter};

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

TEST(TestVectorSupport, Size) {
  poids::Vector<si::Energy, 3> actual{Vector3d{1.0, 0.0, 0.0} * joule};

  EXPECT_EQ(3, actual.size());
}

TEST(TestVectorSupport, GetX) {
  si::Mass expected = 1 * mega(gram);

  poids::Vector<si::Mass, 2> quantity{Vector2d{1.0, 2.0} * mega(gram)};

  si::Mass actual{quantity.x()};

  EXPECT_EQ(expected, actual);
}

TEST(TestVectorSupport, GetXConst) {
  si::Force expected = 4 * newton;

  const poids::Vector<si::Force, 2> quantity{Vector2d{4.0, 2.0} * newton};

  si::Force actual = quantity.x();

  EXPECT_EQ(expected, actual);
}

TEST(TestVectorSupport, SetX) {
  poids::Vector<si::Mass, 2> expected{Vector2d{1.0, 2.0} * mega(gram)};

  poids::Vector<si::Mass, 2> actual{Vector2d{0.0, 2.0} * mega(gram)};

  actual.x() = mega(gram);

  EXPECT_TRUE(expected.as(kilogram).isApprox(actual.as(kilogram), 1e-6));
}

TEST(TestVectorSupport, GetY) {
  si::Length expected = 4 * mega(meter);

  poids::Vector<si::Length, 3> quantity{Vector3d{2.0, 4.0, 8.0} * mega(meter)};

  si::Length actual{quantity.y()};

  EXPECT_EQ(expected, actual);
}

TEST(TestVectorSupport, GetYConst) {
  si::Energy expected = 4 * joule;

  const poids::Vector<si::Energy, 2> quantity{Vector2d{2.0, 4.0} * joule};

  si::Energy actual = quantity.y();

  EXPECT_EQ(expected, actual);
}

TEST(TestVectorSupport, SetY) {
  poids::Vector<si::Mass, 4> expected{Vector4d{1.0, 1.0, 1.0, 0.0} * mega(gram)};

  poids::Vector<si::Mass, 4> actual{Vector4d{1.0, 2.0, 1.0, 0.0} * mega(gram)};

  actual.y() = mega(gram);

  EXPECT_TRUE(expected.as(kilogram).isApprox(actual.as(kilogram), 1e-6));
}

TEST(TestVectorSupport, GetZ) {
  si::Mass expected = 1 * mega(gram);

  poids::Vector<si::Mass, 3> quantity{Vector3d{1.5, 2.0, 1.0} * mega(gram)};

  si::Mass actual{quantity.z()};

  EXPECT_EQ(expected, actual);
}

TEST(TestVectorSupport, GetZConst) {
  si::Time expected = 1 * second;

  const poids::Vector<si::Time, 3> quantity{Vector3d{5.0, 2.0, 1.0} * second};

  si::Time actual = quantity.z();

  EXPECT_EQ(expected, actual);
}

TEST(TestVectorSupport, SetZ) {
  poids::Vector<si::Frequency, 4> expected{Vector4d{1.0, 2.0, 12.0, 5.0} * hertz};

  poids::Vector<si::Frequency, 4> actual{Vector4d{1.0, 2.0, 5.0, 5.0} * hertz};

  actual.z() = 12 * hertz;

  EXPECT_TRUE(expected.as(hertz).isApprox(actual.as(hertz), 1e-6));
}

TEST(TestVectorSupport, GetW) {
  si::Mass expected = 1 * mega(gram);

  poids::Vector<si::Mass, 4> quantity{Vector4d{10.0, 2.0, 3.0, 1.0} * mega(gram)};

  si::Mass actual = quantity.w();

  EXPECT_EQ(expected, actual);
}

TEST(TestVectorSupport, GetWConst) {
  si::Force expected = 4 * newton;

  const poids::Vector<si::Force, 5> quantity{Eigen::Vector<double, 5>{1.0, 2.0, 5.0, 4.0, 8.0} * newton};

  si::Force actual = quantity.w();

  EXPECT_EQ(expected, actual);
}

TEST(TestVectorSupport, SetW) {
  poids::Vector<si::Mass, 4> expected{Vector4d{1.0, 2.0, 1.0, 4.5} * mega(gram)};

  poids::Vector<si::Mass, 4> actual{Vector4d{1.0, 2.0, 1.0, 0.0} * mega(gram)};

  actual.w() = 4.5 * mega(gram);

  EXPECT_TRUE(expected.as(kilogram).isApprox(actual.as(kilogram), 1e-6));
}

TEST(TestVectorSupport, IsApprox) {
  poids::Vector<si::Power, 4> quantity1{Vector4d{1.0, 2.0, 3.0, 4.0} * watt};
  poids::Vector<si::Power, 4> quantity2{Vector4d{1.0, 2.1, 3.0, 4.0} * watt};
  poids::Vector<si::Power, 4> quantity3{Vector4d{100.0, -4.5, 6.23, 19.5} * watt};
  poids::Vector<si::Power, 4> quantity4{Vector4d{1.0, 2.0, 2.999'999'98, 4.0} * watt};

  EXPECT_TRUE(quantity1.isApprox(quantity4));
  EXPECT_FALSE(quantity1.isApprox(quantity2));
  EXPECT_FALSE(quantity2.isApprox(quantity1));
  EXPECT_FALSE(quantity1.isApprox(quantity3));
  EXPECT_TRUE(quantity1.isApprox(quantity2, 0.1 * watt));
  EXPECT_FALSE(quantity1.isApprox(quantity4, nano(watt)));
}

TEST(TestVectorSupport, Norm) {
  si::Energy expected = 25'000 * joule;

  poids::Vector<si::Energy, 3> value{Vector3d{12.0, 15.0, 16.0} * kilo(joule)};

  si::Energy actual = value.norm();

  EXPECT_NEAR(expected.as(joule), actual.as(joule), 1e-6);
}

TEST(TestVectorSupport, Normalized) {
  poids::Vector<si::Energy, 3> expected{Vector3d{0.48, 0.6, 0.64} * joule};

  poids::Vector<si::Energy, 3> value{Vector3d{12.0, 15.0, 16.0} * joule};

  poids::Vector<si::Energy, 3> actual = value.normalized();

  EXPECT_TRUE(expected.isApprox(actual, 1e-6 * joule));
}

TEST(TestVectorSupport, Normalize) {
  poids::Vector<si::Energy, 3> expected{Vector3d{0.133'333'333, 0.666'666'667, 0.733'333'333} * joule};

  poids::Vector<si::Energy, 3> actual{Vector3d{2.0, 10.0, 11.0} * joule};

  actual.normalize();

  EXPECT_TRUE(expected.isApprox(actual, 1e-6 * joule));
}

TEST(TestVectorSupport, DotSame) {
  si::SecondMomentOfArea expected = -646.4706 * meter4;

  poids::Vector<si::Area, 6> a{Eigen::Vector<double, 6>{1.5, 6.78, 56.0, -16.5, 6.99, -10.0} * meter2};
  poids::Vector<si::Area, 6> b{Eigen::Vector<double, 6>{0.0, 3.58, -16.5, 16.5, 89.3, 9.87} * meter2};

  si::SecondMomentOfArea actual = a.dot(b);

  EXPECT_NEAR(expected.as(meter4), actual.as(meter4), 1e-6);
}

TEST(TestVectorSupport, DotDifferent) {
  si::Force expected = 1222.754'932 * newton;

  poids::Vector<si::Acceleration, 5> a{Eigen::Vector<double, 5>{8.2, 9.34, 0.654, 10.25, -15.648} * meter / square(second)};
  poids::Vector<si::Mass, 5> b{Eigen::Vector<double, 5>{-12.3, 100, 6.258, 18.3, -12.65} * kilogram};

  si::Force actual = a.dot(b);

  EXPECT_NEAR(expected.as(newton), actual.as(newton), 1e-6);
}

TEST(TestVectorSupport, CrossSame) {
  poids::Vector<si::Area, 3> expected{Vector3d{-267.935'600, -2605.344'400, -1534.918'720} * meter2};

  poids::Vector<si::Length, 3> a{Vector3d{2.5, 27.356, -46.87} * meter};
  poids::Vector<si::Length, 3> b{Vector3d{56.12, 0.12, -10.0} * meter};

  poids::Vector<si::Area, 3> actual{a.cross(b)};

  EXPECT_TRUE(expected.isApprox(actual, micro(meter2)));
}

TEST(TestVectorSupport, CrossDifferent) {
  poids::Vector<si::Acceleration, 3> expected{Vector3d{-99.3043, 295.383'876, -195.276'75} * meter / square(second)};

  poids::Vector<si::Velocity, 3> a{Vector3d{-3.258, 9.35, 15.8} * meter / second};
  poids::Vector<si::Frequency, 3> b{Vector3d{18.237, 7.6, 2.222} * (si::Unitless{1.0} / second)};

  poids::Vector<si::Acceleration, 3> actual{a.cross(b)};

  EXPECT_TRUE(expected.isApprox(actual, micro(meter / square(second))));
}
