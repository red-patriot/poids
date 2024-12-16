#include <gtest/gtest.h>

#include "poids/core/traits.hpp"
#include "poids/kgms/unit.hpp"

template <size_t I>
struct ValidUnit {
  static constexpr size_t i = I;

  template <typename Other>
  using multiply_t = ValidUnit<i + Other::i>;

  template <typename Other>
  using divide_t = ValidUnit<i - Other::i>;

  template <int N, unsigned D>
  using power_t = ValidUnit<i * N / D>;
  using unitless_t = ValidUnit<0>;
};
template <size_t I>
struct ValidWithoutUnitless {
  static constexpr size_t i = I;

  template <typename Other>
  using multiply_t = ValidUnit<i + Other::i>;

  template <typename Other>
  using divide_t = ValidUnit<i - Other::i>;

  template <int N, unsigned D>
  using power_t = ValidUnit<i * N / D>;
};

TEST(TestTraits, DetectValidUnit) {
  EXPECT_TRUE(poids::IsValidUnit_v<ValidUnit<1>>);
  EXPECT_TRUE(poids::IsValidUnit_v<ValidWithoutUnitless<1>>);
  EXPECT_TRUE((poids::IsValidUnit_v<kgms::UnitType<std::ratio<1>, std::ratio<1>, std::ratio<1>>>));
}

template <size_t I>
struct MissingMultiply {
  static constexpr size_t i = I;

  template <typename Other>
  using divide_t = ValidUnit<i - Other::i>;

  template <int N, unsigned D>
  using power_t = ValidUnit<i * N / D>;
  using unitless_t = ValidUnit<0>;
};

template <size_t I>
struct MissingDivide {
  static constexpr size_t i = I;

  template <typename Other>
  using multiply_t = ValidUnit<i + Other::i>;

  template <int N, unsigned D>
  using power_t = ValidUnit<i * N / D>;
  using unitless_t = ValidUnit<0>;
};

template <size_t I>
struct MissingPower {
  static constexpr size_t i = I;

  template <typename Other>
  using multiply_t = ValidUnit<i + Other::i>;

  template <typename Other>
  using divide_t = ValidUnit<i - Other::i>;

  using unitless_t = ValidUnit<0>;
};

template <size_t I>
struct WrongPower {
  static constexpr size_t i = I;

  template <typename Other>
  using multiply_t = ValidUnit<i + Other::i>;

  template <typename Other>
  using divide_t = ValidUnit<i - Other::i>;

  template <int N>
  using power_t = ValidUnit<i * N>;
  using unitless_t = ValidUnit<0>;
};

TEST(TestTraits, DetectInvalidUnit) {
  EXPECT_FALSE(poids::IsValidUnit_v<MissingMultiply<2>>);
  EXPECT_FALSE(poids::IsValidUnit_v<MissingDivide<2>>);
  EXPECT_FALSE(poids::IsValidUnit_v<MissingPower<2>>);
  EXPECT_FALSE(poids::IsValidUnit_v<WrongPower<2>>);
}

TEST(TestTraits, DetermineUnitlessUnit) {
  EXPECT_TRUE((std::is_same_v<ValidUnit<0>, poids::UnitlessOf_t<ValidUnit<1>>>));
  EXPECT_TRUE((std::is_same_v<void, poids::UnitlessOf_t<ValidWithoutUnitless<1>>>));
}