#include <ratio>
#include <type_traits>

#include <gtest/gtest.h>

#include "poids/kgms/unit.hpp"

TEST(TestKgmsDimension, CorrectMass) {
  using expected = std::ratio<2, 3>;
  using actual = kgms::UnitType<std::ratio<2, 3>,
                                std::ratio<0>,
                                std::ratio<0>>;

  EXPECT_TRUE((std::is_same_v<expected, actual::mass>));
}

TEST(TestKgmsDimension, CorrectLength) {
  using expected = std::ratio<-7>;
  using actual = kgms::UnitType<std::ratio<0>,
                                std::ratio<-7>,
                                std::ratio<0>>;

  EXPECT_TRUE((std::is_same_v<expected, actual::length>));
}

TEST(TestKgmsDimension, CorrectTime) {
  using expected = std::ratio<3>;
  using actual = kgms::UnitType<std::ratio<0>,
                                std::ratio<0>,
                                std::ratio<3>>;

  EXPECT_TRUE((std::is_same_v<expected, actual::time>));
}

TEST(TestKgmsDimension, MultiplyMassUnits) {
  using Expected = kgms::UnitType<std::ratio<3>,
                                  std::ratio<0>,
                                  std::ratio<0>>;

  using First = kgms::UnitType<std::ratio<1>,
                               std::ratio<0>,
                               std::ratio<0>>;
  using Second = kgms::UnitType<std::ratio<2>,
                                std::ratio<0>,
                                std::ratio<0>>;

  EXPECT_TRUE((std::is_same_v<Expected, First::multiply_t<Second>>));
}

TEST(TestKgmsDimension, MultiplyLengthUnits) {
  using Expected = kgms::UnitType<std::ratio<0>,
                                  std::ratio<5, 2>,
                                  std::ratio<0>>;

  using First = kgms::UnitType<std::ratio<0>,
                               std::ratio<3, 2>,
                               std::ratio<0>>;
  using Second = kgms::UnitType<std::ratio<0>,
                                std::ratio<1>,
                                std::ratio<0>>;

  EXPECT_TRUE((std::is_same_v<Expected, First::multiply_t<Second>>));
}

TEST(TestKgmsDimension, MultiplyTimeUnits) {
  using Expected = kgms::UnitType<std::ratio<0>,
                                  std::ratio<0>,
                                  std::ratio<4>>;

  using First = kgms::UnitType<std::ratio<0>,
                               std::ratio<0>,
                               std::ratio<3, 2>>;
  using Second = kgms::UnitType<std::ratio<0>,
                                std::ratio<0>,
                                std::ratio<5, 2>>;

  EXPECT_TRUE((std::is_same_v<Expected, First::multiply_t<Second>>));
}

TEST(TestKgmsDimension, DivideMassUnits) {
  using Expected = kgms::UnitType<std::ratio<-1>,
                                  std::ratio<0>,
                                  std::ratio<0>>;

  using First = kgms::UnitType<std::ratio<1>,
                               std::ratio<0>,
                               std::ratio<0>>;
  using Second = kgms::UnitType<std::ratio<2>,
                                std::ratio<0>,
                                std::ratio<0>>;

  EXPECT_TRUE((std::is_same_v<Expected, First::divide_t<Second>>));
}

TEST(TestKgmsDimension, DivideLengthUnits) {
  using Expected = kgms::UnitType<std::ratio<0>,
                                  std::ratio<1, 2>,
                                  std::ratio<0>>;

  using First = kgms::UnitType<std::ratio<0>,
                               std::ratio<3, 2>,
                               std::ratio<0>>;
  using Second = kgms::UnitType<std::ratio<0>,
                                std::ratio<1>,
                                std::ratio<0>>;

  EXPECT_TRUE((std::is_same_v<Expected, First::divide_t<Second>>));
}

TEST(TestKgmsDimension, DivideTimeUnits) {
  using Expected = kgms::UnitType<std::ratio<0>,
                                  std::ratio<0>,
                                  std::ratio<2>>;

  using First = kgms::UnitType<std::ratio<0>,
                               std::ratio<0>,
                               std::ratio<7, 2>>;
  using Second = kgms::UnitType<std::ratio<0>,
                                std::ratio<0>,
                                std::ratio<3, 2>>;

  EXPECT_TRUE((std::is_same_v<Expected, First::divide_t<Second>>));
}
