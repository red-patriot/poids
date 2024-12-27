#include <ratio>
#include <type_traits>

#include <gtest/gtest.h>

#include "poids/core/traits.hpp"
#include "poids/si/unit.hpp"

#define EXPECT_TYPE_EQ(expected, actual) EXPECT_TRUE((std::is_same_v<expected, actual>))

TEST(TestSIDimension, TimeUnit) {
  using expected = std::ratio<1, 3>;
  using actual = si::UnitType<std::ratio<1, 3>,
                              std::ratio<2, 7>,
                              std::ratio<3, 5>,
                              std::ratio<7, 6>,
                              std::ratio<6, 1>,
                              std::ratio<8, 3>,
                              std::ratio<12, 13>>;

  EXPECT_TYPE_EQ(expected, actual::time);
}

TEST(TestSIDimension, LengthUnit) {
  using expected = std::ratio<2, 7>;
  using actual = si::UnitType<std::ratio<1, 3>,
                              std::ratio<2, 7>,
                              std::ratio<3, 5>,
                              std::ratio<7, 6>,
                              std::ratio<6, 1>,
                              std::ratio<8, 3>,
                              std::ratio<12, 13>>;

  EXPECT_TYPE_EQ(expected, actual::length);
}

TEST(TestSIDimension, MassUnit) {
  using expected = std::ratio<3, 5>;
  using actual = si::UnitType<std::ratio<1, 3>,
                              std::ratio<2, 7>,
                              std::ratio<3, 5>,
                              std::ratio<7, 6>,
                              std::ratio<6, 1>,
                              std::ratio<8, 3>,
                              std::ratio<12, 13>>;

  EXPECT_TYPE_EQ(expected, actual::mass);
}

TEST(TestSIDimension, CurrentUnit) {
  using expected = std::ratio<7, 6>;
  using actual = si::UnitType<std::ratio<1, 3>,
                              std::ratio<2, 7>,
                              std::ratio<3, 5>,
                              std::ratio<7, 6>,
                              std::ratio<6, 1>,
                              std::ratio<8, 3>,
                              std::ratio<12, 13>>;

  EXPECT_TYPE_EQ(expected, actual::current);
}

TEST(TestSIDimension, TemperatureUnit) {
  using expected = std::ratio<6>;
  using actual = si::UnitType<std::ratio<1, 3>,
                              std::ratio<2, 7>,
                              std::ratio<3, 5>,
                              std::ratio<7, 6>,
                              std::ratio<6, 1>,
                              std::ratio<8, 3>,
                              std::ratio<12, 13>>;

  EXPECT_TYPE_EQ(expected, actual::temperature);
}

TEST(TestSIDimension, AmountUnit) {
  using expected = std::ratio<8, 3>;
  using actual = si::UnitType<std::ratio<1, 3>,
                              std::ratio<2, 7>,
                              std::ratio<3, 5>,
                              std::ratio<7, 6>,
                              std::ratio<6, 1>,
                              std::ratio<8, 3>,
                              std::ratio<12, 13>>;

  EXPECT_TYPE_EQ(expected, actual::amount);
}

TEST(TestSIDimension, LuminosityUnit) {
  using expected = std::ratio<12, 13>;
  using actual = si::UnitType<std::ratio<1, 3>,
                              std::ratio<2, 7>,
                              std::ratio<3, 5>,
                              std::ratio<7, 6>,
                              std::ratio<6, 1>,
                              std::ratio<8, 3>,
                              std::ratio<12, 13>>;

  EXPECT_TYPE_EQ(expected, actual::luminosity);
}

TEST(TestSIDimension, UnitlessIsDefault) {
  using expected = poids::UnitlessOf_t<si::UnitType<std::ratio<1>,
                                                    std::ratio<1>,
                                                    std::ratio<1>,
                                                    std::ratio<1>,
                                                    std::ratio<1>,
                                                    std::ratio<1>,
                                                    std::ratio<1>>>;

  using actual = si::UnitType<>;

  EXPECT_TYPE_EQ(expected, actual);
}

#undef EXPECT_TYPE_EQ
