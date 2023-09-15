export module poids.unit_types;

export import poids.unit;

namespace poids {
  export using Time = Unit<TimeD(1)>;
  export using Mass = Unit<MassD(1)>;
  export using Length = Unit<LengthD(1)>;
  export using Temperature = Unit<TemperatureD(1)>;
  export using Current = Unit<CurrentD(1)>;
  export using Amount = Unit<AmountD(1)>;
  export using Luminosity = Unit<LuminosityD(1)>;

  export using Frequency = Unit<TimeD(-1)>;

  export using Area = Unit<LengthD(2)>;
  export using Volume = Unit<LengthD(3)>;
  export using SecondMomentOfArea = Unit<LengthD(4)>;

  export using Velocity = Unit<LengthD(1) - TimeD(1)>;
  export using Acceleration = Unit<LengthD(1) - TimeD(2)>;
  export using Jerk = Unit<LengthD(1) - TimeD(3)>;

  export using Momentum = Unit<MassD(1) + LengthD(1) - TimeD(1)>;
  export using Force = Unit<MassD(1) + LengthD(1) - TimeD(2)>;
  export using Energy = Unit<MassD(1) + LengthD(2) - TimeD(2)>;
  export using Power = Unit<MassD(1) + LengthD(2) - TimeD(3)>;

  export using Charge = Unit<CurrentD(1) + TimeD(1)>;
  export using Voltage = Unit<MassD(1) + LengthD(2) - TimeD(3) - CurrentD(1)>;
  export using Resistance = Unit<MassD(1) + LengthD(2) - TimeD(3) - CurrentD(2)>;
  export using Capacitance = Unit<TimeD(4) + CurrentD(2) - MassD(1) - LengthD(2)>;
  export using Inductance = Unit<MassD(1) + LengthD(2) - TimeD(2) - CurrentD(2)>;

  export using Density = Unit<MassD(1) - LengthD(3)>;
  export using Pressure = Unit<MassD(1) - LengthD(1) - TimeD(2)>;
  export using MolarMass = Unit<MassD(1) - AmountD(1)>;
  export using DynamicViscosity = Unit<MassD(1) - LengthD(1) - TimeD(1)>;
  export using KinematicViscosity = Unit<LengthD(2) - TimeD(1)>;
}  // namespace poids
