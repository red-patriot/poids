#include <gtest/gtest.h>

#include "poids/angle/base.hpp"

TEST(TestAngleBase, Radians) {
  auto expected = poids::makeBase<angle::Angle>(1.0);

  angle::Angle actual = angle::base::radian;

  EXPECT_EQ(expected, actual);
}

TEST(TestAngleBase, Degree) {
  auto expected = poids::makeBase<angle::Angle>(0.017'453'292'519'943'295);

  angle::Angle actual = angle::base::degree;

  EXPECT_EQ(expected, actual);
}

TEST(TestAngleBase, Arcminute) {
  auto expected = poids::makeBase<angle::Angle>(0.000'290'888'208'665'721'58);

  angle::Angle actual = angle::base::arcminute;

  EXPECT_EQ(expected, actual);
}

TEST(TestAngleBase, Arcsecond) {
  auto expected = poids::makeBase<angle::Angle>(4.848'136'811'095'359'8e-06);

  angle::Angle actual = angle::base::arcsecond;

  EXPECT_EQ(expected, actual);
}

TEST(TestAngleBase, Rotation) {
  auto expected = poids::makeBase<angle::Angle>(6.283'185'307'179'586'2);

  angle::Angle actual = angle::base::rotation;

  EXPECT_EQ(expected, actual);
}

TEST(TestAngleBase, Turn) {
  auto expected = poids::makeBase<angle::Angle>(3.141'592'653'589'793);

  angle::Angle actual = angle::base::turn;

  EXPECT_EQ(expected, actual);
}

TEST(TestAngle, NoUnitless) {
    EXPECT_FALSE(poids::IsUnitless_v<angle::Angle>);
}