#ifndef POIDS_KGMS_BASE_HPP
#define POIDS_KGMS_BASE_HPP

#include "types.hpp"

namespace kgms {
  namespace base {
    /** The base unit for Mass in KGMS.*/
    inline constexpr auto kilogram = poids::makeBase<::kgms::Mass>(1.0);
    /** Provided for convenience when using prefix functions, to align mass with
     * the usage pattern of other base units.*/
    inline constexpr auto gram = poids::makeBase<::kgms::Mass>(0.001);
    /** The base unit for Length in KGMS.*/
    inline constexpr auto meter = poids::makeBase<::kgms::Length>(1.0);
    /** The base unit for Time in KGMS.*/
    inline constexpr auto second = poids::makeBase<::kgms::Time>(1.0);

    inline constexpr auto radian = poids::makeBase<::kgms::Unitless>(1.0);
    inline constexpr auto degree = poids::makeBase<::kgms::Unitless>(0.017'453'292'519'943'295);
  }  // namespace base

  namespace detail {
    template <typename Ratio>
    struct PrefixImpl {
      template <typename Scalar, typename Unit>
      constexpr poids::BaseQuantity<Scalar, Unit>
      operator()(const poids::BaseQuantity<Scalar, Unit>& base) const {
        return poids::makeBase<Scalar, Unit>(base.value() / Ratio::den * Ratio::num);
      }
    };
  }  // namespace detail

  inline constexpr detail::PrefixImpl<std::nano> nano{};
  inline constexpr detail::PrefixImpl<std::micro> micro{};
  inline constexpr detail::PrefixImpl<std::milli> milli{};
  inline constexpr detail::PrefixImpl<std::centi> centi{};
  inline constexpr detail::PrefixImpl<std::kilo> kilo{};
  inline constexpr detail::PrefixImpl<std::mega> mega{};
  inline constexpr detail::PrefixImpl<std::giga> giga{};

};  // namespace kgms

#endif