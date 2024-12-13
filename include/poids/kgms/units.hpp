#ifndef POIDS_PGMS_UNITS_HPP
#define POIDS_PGMS_UNITS_HPP

#include "poids/kgms/unit.hpp"

namespace kgms::units {
  using UnitlessUnit = UnitType<std::ratio<0>, std::ratio<0>, std::ratio<0>>;

  using MassUnit = UnitType<std::ratio<1>, std::ratio<0>, std::ratio<0>>;
  using LengthUnit = UnitType<std::ratio<0>, std::ratio<1>, std::ratio<0>>;

  using TimeUnit = UnitType<std::ratio<0>, std::ratio<0>, std::ratio<1>>;

  using AreaUnit = UnitType<std::ratio<0>, std::ratio<2>, std::ratio<0>>;
  using VolumeUnit = UnitType<std::ratio<0>, std::ratio<3>, std::ratio<0>>;
  using SecondMomentOfAreaUnit = UnitType<std::ratio<0>, std::ratio<4>, std::ratio<0>>;

  using FrequencyUnit = UnitType<std::ratio<0>, std::ratio<0>, std::ratio<-1>>;

  using VelocityUnit = UnitType<std::ratio<0>, std::ratio<1>, std::ratio<-1>>;
  using AccelerationUnit = UnitType<std::ratio<0>, std::ratio<1>, std::ratio<-2>>;

  using ForceUnit = UnitType<std::ratio<1>, std::ratio<1>, std::ratio<-2>>;
  using EnergyUnit = UnitType<std::ratio<1>, std::ratio<2>, std::ratio<-2>>;

}  // namespace kgms::units

#endif