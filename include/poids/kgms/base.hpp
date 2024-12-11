#ifndef POIDS_KGMS_BASE_HPP
#define POIDS_KGMS_BASE_HPP

#include "types.hpp"

namespace kgms::base {
  /** The base unit for Mass in KGMS.*/
  inline constexpr auto kilogram = poids::makeBase<::kgms::Mass>(1.0);
  /** Provided for convenience when using prefix functions, to align mass with
   * the usage pattern of other base units.*/
  inline constexpr auto gram = poids::makeBase<::kgms::Mass>(0.001);
  /** The base unit for Length in KGMS.*/
  inline constexpr auto meter = poids::makeBase<::kgms::Length>(1.0);
  /** The base unit for Time in KGMS.*/
  inline constexpr auto second = poids::makeBase<::kgms::Time>(1.0);
};  // namespace kgms::base

#endif