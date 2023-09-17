#ifndef POIDS_UNITS_UNIT_TYPES_H
#define POIDS_UNITS_UNIT_TYPES_H

#include "Unit.h"

namespace poids::metric {
  using Time = Unit<TimeD(1)>;
  using Mass = Unit<MassD(1)>;
  using Length = Unit<LengthD(1)>;
  using Temperature = Unit<TemperatureD(1)>;
  using Current = Unit<CurrentD(1)>;
  using Amount = Unit<AmountD(1)>;
  using Luminosity = Unit<LuminosityD(1)>;

  using Frequency = Unit<TimeD(-1)>;

  using Area = Unit<LengthD(2)>;
  using Volume = Unit<LengthD(3)>;
  using SecondMomentOfArea = Unit<LengthD(4)>;

  using Velocity = Unit<LengthD(1) - TimeD(1)>;
  using Acceleration = Unit<LengthD(1) - TimeD(2)>;
  using Jerk = Unit<LengthD(1) - TimeD(3)>;

  using Momentum = Unit<MassD(1) + LengthD(1) - TimeD(1)>;
  using Force = Unit<MassD(1) + LengthD(1) - TimeD(2)>;
  using Energy = Unit<MassD(1) + LengthD(2) - TimeD(2)>;
  using Power = Unit<MassD(1) + LengthD(2) - TimeD(3)>;

  using Charge = Unit<CurrentD(1) + TimeD(1)>;
  using Voltage = Unit<MassD(1) + LengthD(2) - TimeD(3) - CurrentD(1)>;
  using Resistance = Unit<MassD(1) + LengthD(2) - TimeD(3) - CurrentD(2)>;
  using Capacitance = Unit<TimeD(4) + CurrentD(2) - MassD(1) - LengthD(2)>;
  using Inductance = Unit<MassD(1) + LengthD(2) - TimeD(2) - CurrentD(2)>;

  using Density = Unit<MassD(1) - LengthD(3)>;
  using Pressure = Unit<MassD(1) - LengthD(1) - TimeD(2)>;
  using MolarMass = Unit<MassD(1) - AmountD(1)>;
  using DynamicViscosity = Unit<MassD(1) - LengthD(1) - TimeD(1)>;
  using KinematicViscosity = Unit<LengthD(2) - TimeD(1)>;
}  // namespace poids

#endif
