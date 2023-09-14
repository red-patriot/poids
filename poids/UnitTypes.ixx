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
}  // namespace poids
