#ifndef POIDS_KGMS_TYPES_HPP
#define POIDS_KGMS_TYPES_HPP

#include <poids/core/quantity.hpp>
#include <poids/kgms/unit.hpp>

namespace kgms {
  using Mass = poids::Quantity<double,
                               UnitType<std::ratio<1>, std::ratio<0>, std::ratio<0>>>;

  using Length = poids::Quantity<double,
                                 UnitType<std::ratio<0>, std::ratio<1>, std::ratio<0>>>;

  using Time = poids::Quantity<double,
                               UnitType<std::ratio<0>, std::ratio<0>, std::ratio<1>>>;
}  // namespace kgms

#endif