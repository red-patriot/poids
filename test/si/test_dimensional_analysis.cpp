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

TEST(TestSIDimension, EasyTime) {
  using expected = si::UnitType<std::ratio<3, 4>,
                                std::ratio<0>,
                                std::ratio<0>,
                                std::ratio<0>,
                                std::ratio<0>,
                                std::ratio<0>,
                                std::ratio<0>>;

  using actual = si::TimeUnit<3, 4>;

  EXPECT_TYPE_EQ(expected, actual);
}

TEST(TestSIDimension, EasyLength) {
  using expected = si::UnitType<std::ratio<0>,
                                std::ratio<7, 1>,
                                std::ratio<0>,
                                std::ratio<0>,
                                std::ratio<0>,
                                std::ratio<0>,
                                std::ratio<0>>;

  using actual = si::LengthUnit<7>;

  EXPECT_TYPE_EQ(expected, actual);
}

TEST(TestSIDimension, EasyMass) {
  using expected = si::UnitType<std::ratio<0>,
                                std::ratio<0>,
                                std::ratio<2, 3>,
                                std::ratio<0>,
                                std::ratio<0>,
                                std::ratio<0>,
                                std::ratio<0>>;

  using actual = si::MassUnit<2, 3>;

  EXPECT_TYPE_EQ(expected, actual);
}

TEST(TestSIDimension, EasyCurrent) {
  using expected = si::UnitType<std::ratio<0>,
                                std::ratio<0>,
                                std::ratio<0>,
                                std::ratio<1, 5>,
                                std::ratio<0>,
                                std::ratio<0>,
                                std::ratio<0>>;

  using actual = si::CurrentUnit<1, 5>;

  EXPECT_TYPE_EQ(expected, actual);
}

TEST(TestSIDimension, EasyTemperature) {
  using expected = si::UnitType<std::ratio<0>,
                                std::ratio<0>,
                                std::ratio<0>,
                                std::ratio<0>,
                                std::ratio<6>,
                                std::ratio<0>,
                                std::ratio<0>>;

  using actual = si::TemperatureUnit<6, 1>;

  EXPECT_TYPE_EQ(expected, actual);
}

TEST(TestSIDimension, EasyAmount) {
  using expected = si::UnitType<std::ratio<0>,
                                std::ratio<0>,
                                std::ratio<0>,
                                std::ratio<0>,
                                std::ratio<0>,
                                std::ratio<1, 2>,
                                std::ratio<0>>;

  using actual = si::AmountUnit<1, 2>;

  EXPECT_TYPE_EQ(expected, actual);
}

TEST(TestSIDimension, EasyLuminosity) {
  using expected = si::UnitType<std::ratio<0>,
                                std::ratio<0>,
                                std::ratio<0>,
                                std::ratio<0>,
                                std::ratio<0>,
                                std::ratio<0>,
                                std::ratio<5, 6>>;

  using actual = si::LuminosityUnit<5, 6>;

  EXPECT_TYPE_EQ(expected, actual);
}

TEST(TestSIDimension, CombineSingle) {
  using expected = si::UnitType<std::ratio<0>,
                                std::ratio<0>,
                                std::ratio<0>,
                                std::ratio<0>,
                                std::ratio<0>,
                                std::ratio<0>,
                                std::ratio<5, 6>>;

  using actual = si::combine_units_t<si::LuminosityUnit<10, 12>>;

  EXPECT_TYPE_EQ(expected, actual);
}

TEST(TestSIDimension, CombineTwo) {
  using expected = si::UnitType<std::ratio<-1, 2>,
                                std::ratio<0>,
                                std::ratio<2>,
                                std::ratio<0>,
                                std::ratio<0>,
                                std::ratio<0>,
                                std::ratio<0>>;

  using actual = si::combine_units_t<
      si::TimeUnit<-1, 2>,
      si::MassUnit<4, 2>>;

  EXPECT_TYPE_EQ(expected, actual);
}

TEST(TestSIDimension, CombineThree) {
  using expected = si::UnitType<std::ratio<-1, 2>,
                                std::ratio<0>,
                                std::ratio<2>,
                                std::ratio<0>,
                                std::ratio<3>,
                                std::ratio<0>,
                                std::ratio<0>>;

  using actual = si::combine_units_t<
      si::TimeUnit<-2, 4>,
      si::TemperatureUnit<9, 3>,
      si::MassUnit<2>>;

  EXPECT_TYPE_EQ(expected, actual);
}

TEST(TestSIDimension, CombineMultiple) {
  using si::LengthUnit;
  using si::MassUnit;
  using si::TimeUnit;

  using expected = si::UnitType<std::ratio<-3>,
                                std::ratio<2>,
                                std::ratio<3>,
                                std::ratio<0>,
                                std::ratio<0>,
                                std::ratio<0>,
                                std::ratio<0>>;

  using actual = si::combine_units_t<TimeUnit<-1>,
                                     TimeUnit<-1>,
                                     TimeUnit<-2, 2>,
                                     LengthUnit<3>,
                                     LengthUnit<-1>,
                                     MassUnit<3, 4>,
                                     MassUnit<3, 4>,
                                     MassUnit<3, 4>,
                                     MassUnit<3, 4>>;

  EXPECT_TYPE_EQ(expected, actual);
}

#undef EXPECT_TYPE_EQ
