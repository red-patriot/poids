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
    inline constexpr si::Angle::BaseType radian = poids::makeBase<::si::Angle>(1.0);
    inline constexpr si::Time::BaseType second = poids::makeBase<::si::Time>(1.0);
    inline constexpr si::Length::BaseType meter = poids::makeBase<::si::Length>(1.0);
    inline constexpr si::Mass::BaseType kilogram = poids::makeBase<::si::Mass>(1.0);
    inline constexpr si::Current::BaseType ampere = poids::makeBase<::si::Current>(1.0);
    inline constexpr si::Temperature::BaseType kelvin = poids::makeBase<::si::Temperature>(1.0);
    inline constexpr si::Amount::BaseType mole = poids::makeBase<::si::Amount>(1.0);
    inline constexpr si::Luminosity::BaseType candela = poids::makeBase<::si::Luminosity>(1.0);
  }  // namespace base

#define POIDS_SI_DECLARE_DERIVED_UNIT(name, unit_type) \
  using name = poids::Quantity<double,                 \
                               unit_type>

  POIDS_SI_DECLARE_DERIVED_UNIT(SolidAngle,
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

  namespace units {
    // Inject all base units here to make it easier to use units
    using namespace si::base;

    inline constexpr si::SolidAngle::BaseType steradian = si::base::radian * si::base::radian;
    inline constexpr si::Frequency::BaseType hertz = si::Unitless::BaseType{1.0} / si::base::second;
    inline constexpr si::Area::BaseType meter2 = si::base::meter * si::base::meter;
    inline constexpr si::Volume::BaseType meter3 = si::base::meter * si::base::meter * si::base::meter;
    inline constexpr si::Mass::BaseType gram = si::base::kilogram / si::Unitless::BaseType{1000};
    inline constexpr si::Force::BaseType newton = si::base::kilogram * si::base::meter / poids::square(si::base::second);
    inline constexpr si::Energy::BaseType joule = newton * si::base::meter;
    inline constexpr si::Power::BaseType watt = joule / second;
    inline constexpr si::Pressure::BaseType pascal = newton / meter2;
    inline constexpr si::ElectricCharge::BaseType coulomb = si::base::second * si::base::ampere;
    inline constexpr si::Voltage::BaseType volt = joule / coulomb;
    inline constexpr si::Capacitance::BaseType farad = coulomb / volt;
    inline constexpr si::Resistance::BaseType ohm = volt / si::base::ampere;
    inline constexpr si::Conductance::BaseType siemen = si::base::ampere / volt;
    inline constexpr si::MagneticFlux::BaseType weber = si::base::kilogram * meter2 / (poids::square(second) * si::base::ampere);
    inline constexpr si::Inductance::BaseType henry = weber / si::base::ampere;
    inline constexpr si::MagneticFieldStrength::BaseType tesla = weber / meter2;
    inline constexpr si::LuminousFlux::BaseType lumen = si::base::candela / steradian;
    inline constexpr si::Illuminance::BaseType lux = si::base::candela * steradian / meter2;
    inline constexpr si::CatalyticActivity::BaseType katal = si::base::mole / si::base::second;
  }  // namespace units

  namespace detail {
    template <typename Ratio>
    struct Prefix {
      template <typename Scalar, typename Unit>
      constexpr poids::BaseQuantity<Scalar, Unit>
      operator()(const poids::BaseQuantity<Scalar, Unit>& base) const {
        return poids::makeBase<Scalar, Unit>(base.value() / Ratio::den * Ratio::num);
      }
    };
  }  // namespace detail

  namespace prefix {
    /** Implements the metric prefix "nano", e.g. 1nm = nano(meter) */
    inline constexpr detail::Prefix<std::nano> nano{};
    /** Implements the metric prefix "micro", e.g. 1um = micro(meter) */
    inline constexpr detail::Prefix<std::micro> micro{};
    /** Implements the metric prefix "milli", e.g. 1mm = milli(meter) */
    inline constexpr detail::Prefix<std::milli> milli{};
    /** Implements the metric prefix "centi", e.g. 1cm = centi(meter) */
    inline constexpr detail::Prefix<std::centi> centi{};
    /** Implements the metric prefix "kilo", e.g. 1km = kilo(meter) */
    inline constexpr detail::Prefix<std::kilo> kilo{};
    /** Implements the metric prefix "mega", e.g. 1Mm = mega(meter) */
    inline constexpr detail::Prefix<std::mega> mega{};
    /** Implements the metric prefix "giga", e.g. 1Gm = giga(meter) */
    inline constexpr detail::Prefix<std::giga> giga{};
  }  // namespace prefix
}  // namespace si

#endif