#include <gtest/gtest.h>

#include "poids/kgms/base.hpp"

TEST(TestKGMSBase, Mass) {
  auto expected = poids::makeBase<kgms::Mass>(1.0);

  kgms::Mass actual = kgms::base::kilogram;

  EXPECT_EQ(expected, actual);
}

TEST(TestKGMSBase, ExtraMass) {
  auto expected = poids::makeBase<kgms::Mass>(0.001);

  kgms::Mass actual = kgms::base::gram;

  EXPECT_EQ(expected, actual);
}

TEST(TestKGMSBase, Length) {
  auto expected = poids::makeBase<kgms::Length>(1.0);

  kgms::Length actual = kgms::base::meter;

  EXPECT_EQ(expected, actual);
}

TEST(TestKGMSBase, Time) {
  auto expected = poids::makeBase<kgms::Time>(1.0);

  kgms::Time actual = kgms::base::second;

  EXPECT_EQ(expected, actual);
}

TEST(TestKGMSBase, Radian) {
  auto expected = poids::makeBase<kgms::Angle>(1.0);

  kgms::Angle actual = kgms::base::radian;

  EXPECT_EQ(expected, actual);
}

TEST(TestKGMSBase, Degree) {
  auto expected = poids::makeBase<kgms::Angle>(0.017'453'292'519'943'295);

  kgms::Angle actual = kgms::base::degree;

  EXPECT_EQ(expected, actual);
}

TEST(TestKGMSBase, MeterSquared) {
  auto expected = kgms::base::meter * kgms::base::meter;

  kgms::Area actual = kgms::base::meter2;

  EXPECT_EQ(expected, actual);
}

TEST(TestKGMSBase, MeterCubed) {
  auto expected = kgms::base::meter * kgms::base::meter * kgms::base::meter;

  kgms::Volume actual = kgms::base::meter3;

  EXPECT_EQ(expected, actual);
}

TEST(TestKGMSBase, MeterToTheFourth) {
  auto expected = kgms::base::meter * kgms::base::meter * kgms::base::meter * kgms::base::meter;

  kgms::SecondMomentOfArea actual = kgms::base::meter4;

  EXPECT_EQ(expected, actual);
}

TEST(TestKGMSBase, Newton) {
  auto expected = kgms::base::kilogram * kgms::base::meter / (kgms::base::second * kgms::base::second);

  kgms::Force actual = kgms::base::newton;

  EXPECT_EQ(expected, actual);
}

TEST(TestKGMSBase, Joule) {
  auto expected = kgms::base::kilogram * kgms::base::meter * kgms::base::meter / (kgms::base::second * kgms::base::second);

  kgms::Energy actual = kgms::base::joule;

  EXPECT_EQ(expected, actual);
}

TEST(TestKGMSBase, Watt) {
  auto expected = kgms::base::kilogram * kgms::base::meter * kgms::base::meter / (kgms::base::second * kgms::base::second * kgms::base::second);

  kgms::Power actual = kgms::base::watt;

  EXPECT_EQ(expected, actual);
}

TEST(TestKGMSBase, Minute) {
  auto expected = poids::makeBase<kgms::Time>(60.0);

  kgms::Time actual = kgms::base::minute;

  EXPECT_EQ(expected, actual);
}

TEST(TestKGMSBase, Hour) {
  auto expected = poids::makeBase<kgms::Time>(3600.0);

  kgms::Time actual = kgms::base::hour;

  EXPECT_EQ(expected, actual);
}
