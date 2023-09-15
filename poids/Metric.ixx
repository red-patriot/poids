export module poids.metric;

export import poids.unit;
export import poids.unit_types;

namespace poids::metric {
  export const Time second{1};
  export const Mass kilogram{1};
  export const Length meter{1};
  export const Temperature kelvin{1};
  export const Current ampere{1};
  export const Amount mole{1};
  export const Luminosity candela{1};

  export const Mass gram{0.001};

  export const Unit<TimeD(2)> second2{1};
  export const Unit<TimeD(3)> second3{1};
  export const Frequency hertz{1};

  export const Area meter2{1};
  export const Volume meter3{1};
  export const SecondMomentOfArea meter4{1};

  export const Force newton{1};
  export const Energy joule{1};
  export const Power watt{1};

  export const Charge coulomb{1};
  export const Voltage volt{1};
  export const Resistance ohm{1};
  export const Capacitance farad{1};
  export const Inductance henry{1};

  export const Pressure pascal{1};

}  // namespace poids::metric
