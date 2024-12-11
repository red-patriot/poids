#ifndef POIDS_ANGLE_UNIT_HPP
#define POIDS_ANGLE_UNIT_HPP

#include "poids/core/traits.hpp"

namespace angle {
  template <typename AngleRatio>
  struct UnitType {
    static_assert(poids::is_std_ratio<AngleRatio>::value,
                  "AngleRatio must be a specialization of std::ratio");

    using unit = AngleRatio;

    template <typename Other>
    using multiply_t = std::ratio_add<unit, typename Other::unit>;
    template <typename Other>
    using divide_t = std::ratio_subtract<unit, typename Other::unit>;

    using unitless_t = void;
  };
}  // namespace angle

#endif