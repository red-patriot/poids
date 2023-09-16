#ifndef POIDS_UNITS_METRIC_H
#define POIDS_UNITS_METRIC_H

#include "Unit.h"
#include "UnitTypes.h"

namespace poids::metric {
  static const Time second{1};
  static const Mass kilogram{1};
  static const Length meter{1};
  static const Temperature kelvin{1};
  static const Current ampere{1};
  static const Amount mole{1};
  static const Luminosity candela{1};

  static const Mass gram{0.001};

  static const Unit<TimeD(2)> second2{1};
  static const Unit<TimeD(3)> second3{1};
  static const Frequency hertz{1};

  static const Area meter2{1};
  static const Volume meter3{1};
  static const SecondMomentOfArea meter4{1};

  static const Force newton{1};
  static const Energy joule{1};
  static const Power watt{1};

  static const Charge coulomb{1};
  static const Voltage volt{1};
  static const Resistance ohm{1};
  static const Capacitance farad{1};
  static const Inductance henry{1};

  static const Pressure pascal{1};

  template <Dimension Dim>
  inline Unit<Dim> giga(const Unit<Dim> input) noexcept {
    return input * 1'000'000'000;
  }

  template <Dimension Dim>
  inline Unit<Dim> mega(const Unit<Dim> input) noexcept {
    return input * 1'000'000;
  }

  template <Dimension Dim>
  inline Unit<Dim> kilo(const Unit<Dim> input) noexcept {
    return input * 1'000;
  }

  template <Dimension Dim>
  inline Unit<Dim> milli(const Unit<Dim> input) noexcept {
    return input * 0.001;
  }

  template <Dimension Dim>
  inline Unit<Dim> micro(const Unit<Dim> input) noexcept {
    return input * 0.000'001;
  }

  template <Dimension Dim>
  inline Unit<Dim> nano(const Unit<Dim> input) noexcept {
    return input * 0.000'000'001;
  }

}  // namespace poids::metric

#endif
