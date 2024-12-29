#ifndef POIDS_SI_CONSTANTS_HPP
#define POIDS_SI_CONSTANTS_HPP

#include "poids/core/quantity.hpp"
#include "poids/si/unit.hpp"

namespace si {
  using Unitless = poids::Quantity<double, si::UnitType<>>;
  using Angle = poids::Quantity<double, si::UnitType<>>;
  using Time = poids::Quantity<double, si::TimeUnit<1>>;
  using Length = poids::Quantity<double, si::LengthUnit<1>>;
  using Mass = poids::Quantity<double, si::MassUnit<1>>;
  using Current = poids::Quantity<double, si::CurrentUnit<1>>;
  using Temperature = poids::Quantity<double, si::TemperatureUnit<1>>;
  using Amount = poids::Quantity<double, si::AmountUnit<1>>;
  using Luminosity = poids::Quantity<double, si::LuminosityUnit<1>>;

  namespace base {
    inline constexpr auto radian = poids::makeBase<::si::Angle>(1.0); 
    inline constexpr auto second = poids::makeBase<::si::Time>(1.0);
    inline constexpr auto meter = poids::makeBase<::si::Length>(1.0);
    inline constexpr auto kilogram = poids::makeBase<::si::Mass>(1.0);
    inline constexpr auto ampere = poids::makeBase<::si::Current>(1.0);
    inline constexpr auto kelvin = poids::makeBase<::si::Temperature>(1.0);
    inline constexpr auto mole = poids::makeBase<::si::Amount>(1.0);
    inline constexpr auto candela = poids::makeBase<::si::Luminosity>(1.0);
  }
}  // namespace si

#endif