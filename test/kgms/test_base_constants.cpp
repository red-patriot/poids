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