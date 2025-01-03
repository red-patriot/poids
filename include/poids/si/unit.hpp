#ifndef POIDS_SI_UNIT_HPP
#define POIDS_SI_UNIT_HPP

#include <numeric>
#include <ratio>

namespace si {
  namespace detail {
    template <typename Ratio>
    using simplify = std::ratio<Ratio::num, Ratio::den>;
  }  // namespace detail

  template <typename TimeRatio = std::ratio<0, 1>,
            typename LengthRatio = std::ratio<0, 1>,
            typename MassRatio = std::ratio<0, 1>,
            typename CurrentRatio = std::ratio<0, 1>,
            typename TemperatureRatio = std::ratio<0, 1>,
            typename AmountRatio = std::ratio<0, 1>,
            typename LuminosityRatio = std::ratio<0, 1>>
  struct UnitType {
    using time = TimeRatio;
    using length = LengthRatio;
    using mass = MassRatio;
    using current = CurrentRatio;
    using temperature = TemperatureRatio;
    using amount = AmountRatio;
    using luminosity = LuminosityRatio;

    template <typename Other>
    using multiply_t = UnitType<detail::simplify<std::ratio_add<time, typename Other::time>>,
                                detail::simplify<std::ratio_add<length, typename Other::length>>,
                                detail::simplify<std::ratio_add<mass, typename Other::mass>>,
                                detail::simplify<std::ratio_add<current, typename Other::current>>,
                                detail::simplify<std::ratio_add<temperature, typename Other::temperature>>,
                                detail::simplify<std::ratio_add<amount, typename Other::amount>>,
                                detail::simplify<std::ratio_add<luminosity, typename Other::luminosity>>>;

    template <typename Other>
    using divide_t = UnitType<detail::simplify<std::ratio_subtract<time, typename Other::time>>,
                              detail::simplify<std::ratio_subtract<length, typename Other::length>>,
                              detail::simplify<std::ratio_subtract<mass, typename Other::mass>>,
                              detail::simplify<std::ratio_subtract<current, typename Other::current>>,
                              detail::simplify<std::ratio_subtract<temperature, typename Other::temperature>>,
                              detail::simplify<std::ratio_subtract<amount, typename Other::amount>>,
                              detail::simplify<std::ratio_subtract<luminosity, typename Other::luminosity>>>;

    template <intmax_t N, unsigned D = 1>
    using power_t = UnitType<detail::simplify<std::ratio_multiply<time, std::ratio<N, D>>>,
                             detail::simplify<std::ratio_multiply<length, std::ratio<N, D>>>,
                             detail::simplify<std::ratio_multiply<mass, std::ratio<N, D>>>,
                             detail::simplify<std::ratio_multiply<current, std::ratio<N, D>>>,
                             detail::simplify<std::ratio_multiply<temperature, std::ratio<N, D>>>,
                             detail::simplify<std::ratio_multiply<amount, std::ratio<N, D>>>,
                             detail::simplify<std::ratio_multiply<luminosity, std::ratio<N, D>>>>;

    using unitless_t = si::UnitType<std::ratio<0>, std::ratio<0>, std::ratio<0>, std::ratio<0>, std::ratio<0>, std::ratio<0>, std::ratio<0>>;
  };

  using UnitlessUnit = UnitType<>;
  template <intmax_t N, intmax_t D = 1>
  using AngleUnit = UnitType<>;
  template <intmax_t N, intmax_t D = 1>
  using TimeUnit = UnitType<std::ratio<N, D>>;
  template <intmax_t N, intmax_t D = 1>
  using LengthUnit = UnitType<std::ratio<0>, std::ratio<N, D>>;
  template <intmax_t N, intmax_t D = 1>
  using MassUnit = UnitType<std::ratio<0>, std::ratio<0>, std::ratio<N, D>>;
  template <intmax_t N, intmax_t D = 1>
  using CurrentUnit = UnitType<std::ratio<0>, std::ratio<0>, std::ratio<0>, std::ratio<N, D>>;
  template <intmax_t N, intmax_t D = 1>
  using TemperatureUnit = UnitType<std::ratio<0>, std::ratio<0>, std::ratio<0>, std::ratio<0>, std::ratio<N, D>>;
  template <intmax_t N, intmax_t D = 1>
  using AmountUnit = UnitType<std::ratio<0>, std::ratio<0>, std::ratio<0>, std::ratio<0>, std::ratio<0>, std::ratio<N, D>>;
  template <intmax_t N, intmax_t D = 1>
  using LuminosityUnit = UnitType<std::ratio<0>, std::ratio<0>, std::ratio<0>, std::ratio<0>, std::ratio<0>, std::ratio<0>, std::ratio<N, D>>;

  namespace detail {
    template <typename First, typename Second = void, typename... Others>
    struct combine {
      using type = typename combine<typename combine<First, Second>::type, Others...>::type;
    };

    template <typename Unit>
    struct combine<Unit> {
      using type = UnitType<simplify<typename Unit::time>,
                            simplify<typename Unit::length>,
                            simplify<typename Unit::mass>,
                            simplify<typename Unit::current>,
                            simplify<typename Unit::temperature>,
                            simplify<typename Unit::amount>,
                            simplify<typename Unit::luminosity>>;
    };

    template <typename First, typename Second>
    struct combine<First, Second> {
      using type = UnitType<simplify<std::ratio_add<typename First::time, typename Second::time>>,
                            simplify<std::ratio_add<typename First::length, typename Second::length>>,
                            simplify<std::ratio_add<typename First::mass, typename Second::mass>>,
                            simplify<std::ratio_add<typename First::current, typename Second::current>>,
                            simplify<std::ratio_add<typename First::temperature, typename Second::temperature>>,
                            simplify<std::ratio_add<typename First::amount, typename Second::amount>>,
                            simplify<std::ratio_add<typename First::luminosity, typename Second::luminosity>>>;
    };

    template <typename... Units>
    using combine_t = typename combine<Units...>::type;
  }  // namespace detail

  template <typename... UnitTypes>
  using combine_units_t = detail::combine_t<UnitTypes...>;
}  // namespace si

#endif