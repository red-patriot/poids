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
  }  // namespace base

#define POIDS_SI_DECLARE_DERIVED_UNIT(name, unit_type) \
  using name = poids::Quantity<double,                 \
                               unit_type>

  POIDS_SI_DECLARE_DERIVED_UNIT(Steradian,
                                poids::UnitOf_t<si::Angle>::multiply_t<poids::UnitOf_t<si::Angle>>);
  POIDS_SI_DECLARE_DERIVED_UNIT(Frequency,
                                si::TimeUnit<-1>);
  POIDS_SI_DECLARE_DERIVED_UNIT(Area,
                                si::LengthUnit<2>);
  POIDS_SI_DECLARE_DERIVED_UNIT(Volume,
                                si::LengthUnit<3>);
  POIDS_SI_DECLARE_DERIVED_UNIT(SecondMomentOfArea,
                                si::LengthUnit<4>);
  POIDS_SI_DECLARE_DERIVED_UNIT(Velocity,
                                si::LengthUnit<1>::divide_t<si::TimeUnit<1>>);
  POIDS_SI_DECLARE_DERIVED_UNIT(Acceleration,
                                si::LengthUnit<1>::divide_t<si::TimeUnit<2>>);
  POIDS_SI_DECLARE_DERIVED_UNIT(Jerk,
                                si::LengthUnit<1>::divide_t<si::TimeUnit<3>>);
  POIDS_SI_DECLARE_DERIVED_UNIT(Momentum,
                                si::MassUnit<1>::multiply_t<poids::UnitOf_t<Velocity>>);
  POIDS_SI_DECLARE_DERIVED_UNIT(Density,
                                si::MassUnit<1>::divide_t<poids::UnitOf_t<si::Volume>>);
  POIDS_SI_DECLARE_DERIVED_UNIT(Force,
                                si::MassUnit<1>::multiply_t<si::LengthUnit<1>>::divide_t<si::TimeUnit<2>>);
  POIDS_SI_DECLARE_DERIVED_UNIT(SpecificWeight,
                                poids::UnitOf_t<Force>::divide_t<poids::UnitOf_t<Volume>>);
  POIDS_SI_DECLARE_DERIVED_UNIT(MomentOfInertia,
                                si::MassUnit<1>::multiply_t<poids::UnitOf_t<Area>>);
  POIDS_SI_DECLARE_DERIVED_UNIT(Energy,
                                poids::UnitOf_t<Force>::multiply_t<si::LengthUnit<1>>);
  POIDS_SI_DECLARE_DERIVED_UNIT(Power,
                                poids::UnitOf_t<Energy>::divide_t<si::TimeUnit<1>>);
  POIDS_SI_DECLARE_DERIVED_UNIT(Pressure,
                                poids::UnitOf_t<Force>::divide_t<poids::UnitOf_t<Area>>);
  POIDS_SI_DECLARE_DERIVED_UNIT(DynamicViscosity,
                                poids::UnitOf_t<si::Force>::multiply_t<si::TimeUnit<1>>::divide_t<si::LengthUnit<2>>);
  POIDS_SI_DECLARE_DERIVED_UNIT(KinematicViscosity,
                                poids::UnitOf_t<DynamicViscosity>::divide_t<poids::UnitOf_t<Density>>);
  POIDS_SI_DECLARE_DERIVED_UNIT(ElectricCharge,
                                si::TimeUnit<1>::multiply_t<si::CurrentUnit<1>>);
  POIDS_SI_DECLARE_DERIVED_UNIT(Voltage,
                                poids::UnitOf_t<Power>::divide_t<si::CurrentUnit<1>>);
  POIDS_SI_DECLARE_DERIVED_UNIT(Resistance,
                                poids::UnitOf_t<Voltage>::divide_t<si::CurrentUnit<1>>);
  POIDS_SI_DECLARE_DERIVED_UNIT(Capacitance,
                                poids::UnitOf_t<ElectricCharge>::divide_t<poids::UnitOf_t<Voltage>>);
  POIDS_SI_DECLARE_DERIVED_UNIT(Conductance,
                                si::CurrentUnit<1>::divide_t<poids::UnitOf_t<Voltage>>);
  POIDS_SI_DECLARE_DERIVED_UNIT(MagneticFlux,
                                poids::UnitOf_t<Voltage>::multiply_t<si::TimeUnit<1>>);
  POIDS_SI_DECLARE_DERIVED_UNIT(MagneticFieldStrength,
                                poids::UnitOf_t<MagneticFlux>::divide_t<poids::UnitOf_t<Area>>);
  POIDS_SI_DECLARE_DERIVED_UNIT(Inductance,
                                poids::UnitOf_t<MagneticFlux>::divide_t<si::CurrentUnit<1>>);
  POIDS_SI_DECLARE_DERIVED_UNIT(LuminousFlux,
                                si::LuminosityUnit<1>::divide_t<si::AngleUnit<2>>);
  POIDS_SI_DECLARE_DERIVED_UNIT(Illuminance,
                                si::LuminosityUnit<1>::multiply_t<si::AngleUnit<2>>::divide_t<poids::UnitOf_t<si::Area>>);
  POIDS_SI_DECLARE_DERIVED_UNIT(CatalyticActivity,
                                si::AmountUnit<1>::divide_t<si::TimeUnit<1>>);

#undef POIDS_SI_DECLARE_DERIVED_UNIT

}  // namespace si

#endif