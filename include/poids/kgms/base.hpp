#ifndef POIDS_KGMS_BASE_HPP
#define POIDS_KGMS_BASE_HPP

#include "types.hpp"

namespace kgms {
  namespace base {
    /** The base unit for Mass in KGMS.*/
    inline constexpr auto kilogram = poids::makeBase<::kgms::Mass>(1.0);
    /** Provided for convenience when using prefix functions, to align usage of
     * mass with the usage pattern of other base units.*/
    inline constexpr auto gram = poids::makeBase<::kgms::Mass>(0.001);
    /** The base unit for Length in KGMS.*/
    inline constexpr auto meter = poids::makeBase<::kgms::Length>(1.0);
    /** The base unit for Time in KGMS.*/
    inline constexpr auto second = poids::makeBase<::kgms::Time>(1.0);

    /** The base unit for Angle in KGMS. */
    inline constexpr auto radian = poids::makeBase<::kgms::Angle>(1.0);
    /** A common Angle unit in KGMS. */
    inline constexpr auto degree = poids::makeBase<::kgms::Angle>(0.017'453'292'519'943'295);
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

  /** Implements the metric prefix "nano", e.g. 1nm = nano(meter) */
  inline constexpr detail::PrefixImpl<std::nano> nano{};
  /** Implements the metric prefix "micro", e.g. 1um = micro(meter) */
  inline constexpr detail::PrefixImpl<std::micro> micro{};
  /** Implements the metric prefix "milli", e.g. 1mm = milli(meter) */
  inline constexpr detail::PrefixImpl<std::milli> milli{};
  /** Implements the metric prefix "centi", e.g. 1mm = centi(meter) */
  inline constexpr detail::PrefixImpl<std::centi> centi{};
  /** Implements the metric prefix "kilo", e.g. 1cm = kilo(meter) */
  inline constexpr detail::PrefixImpl<std::kilo> kilo{};
  /** Implements the metric prefix "mega", e.g. 1Mm = mega(meter) */
  inline constexpr detail::PrefixImpl<std::mega> mega{};
  /** Implements the metric prefix "giga", e.g. 1Gm = giga(meter) */
  inline constexpr detail::PrefixImpl<std::giga> giga{};

};  // namespace kgms

#endif