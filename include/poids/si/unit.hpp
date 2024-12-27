#ifndef POIDS_SI_UNIT_HPP
#define POIDS_SI_UNIT_HPP

#include <ratio>

namespace si {
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

    using unitless_t = si::UnitType<std::ratio<0>, std::ratio<0>, std::ratio<0>, std::ratio<0>, std::ratio<0>, std::ratio<0>, std::ratio<0>>;
  };
}  // namespace si

#endif