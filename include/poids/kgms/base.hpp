#ifndef POIDS_KGMS_BASE_HPP
#define POIDS_KGMS_BASE_HPP

#include "types.hpp"

namespace kgms::base {
  inline const auto kilogram = poids::makeBase<::kgms::Mass>(1.0);
  inline const auto gram = poids::makeBase<::kgms::Mass>(0.001);
  inline const auto meter = poids::makeBase<::kgms::Length>(1.0);
  inline const auto second = poids::makeBase<::kgms::Time>(1.0);
};  // namespace kgms::base

#endif