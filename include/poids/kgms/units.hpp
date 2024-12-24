#ifndef POIDS_PGMS_UNITS_HPP
#define POIDS_PGMS_UNITS_HPP

#include "poids/core/quantity.hpp"
#include "poids/kgms/unit.hpp"

namespace kgms {
#define POIDS_KGMS_DECLARE_QUANTITY_TEMPLATE(name, UnitType) \
  namespace templates {                                      \
    template <typename Scalar>                               \
    using name = ::poids::Quantity<Scalar,                   \
                                   ::kgms::units::UnitType>; \
  }

#define POIDS_KGMS_DECLARE_UNIT_TYPE(name, MassRatio, LengthRatio, TimeRatio) \
  namespace units {                                                           \
    using name##Unit = UnitType<MassRatio, LengthRatio, TimeRatio>;           \
  }                                                                           \
  POIDS_KGMS_DECLARE_QUANTITY_TEMPLATE(name, name##Unit)

  POIDS_KGMS_DECLARE_UNIT_TYPE(Unitless, std::ratio<0>, std::ratio<0>, std::ratio<0>);
  POIDS_KGMS_DECLARE_QUANTITY_TEMPLATE(Angle, UnitlessUnit);

  POIDS_KGMS_DECLARE_UNIT_TYPE(Mass, std::ratio<1>, std::ratio<0>, std::ratio<0>);
  POIDS_KGMS_DECLARE_UNIT_TYPE(Length, std::ratio<0>, std::ratio<1>, std::ratio<0>);
  POIDS_KGMS_DECLARE_UNIT_TYPE(Time, std::ratio<0>, std::ratio<0>, std::ratio<1>);

  POIDS_KGMS_DECLARE_UNIT_TYPE(Area, std::ratio<0>, std::ratio<2>, std::ratio<0>);
  POIDS_KGMS_DECLARE_UNIT_TYPE(Volume, std::ratio<0>, std::ratio<3>, std::ratio<0>);
  POIDS_KGMS_DECLARE_UNIT_TYPE(SecondMomentOfArea, std::ratio<0>, std::ratio<4>, std::ratio<0>);
  POIDS_KGMS_DECLARE_UNIT_TYPE(Density, std::ratio<1>, std::ratio<-3>, std::ratio<0>);

  POIDS_KGMS_DECLARE_UNIT_TYPE(Frequency, std::ratio<0>, std::ratio<0>, std::ratio<-1>);

  POIDS_KGMS_DECLARE_UNIT_TYPE(Velocity, std::ratio<0>, std::ratio<1>, std::ratio<-1>);
  POIDS_KGMS_DECLARE_UNIT_TYPE(Acceleration, std::ratio<0>, std::ratio<1>, std::ratio<-2>);

  POIDS_KGMS_DECLARE_UNIT_TYPE(Force, std::ratio<1>, std::ratio<1>, std::ratio<-2>);
  POIDS_KGMS_DECLARE_UNIT_TYPE(Energy, std::ratio<1>, std::ratio<2>, std::ratio<-2>);
  POIDS_KGMS_DECLARE_UNIT_TYPE(Power, std::ratio<1>, std::ratio<2>, std::ratio<-3>);
  POIDS_KGMS_DECLARE_UNIT_TYPE(Pressure, std::ratio<1>, std::ratio<-1>, std::ratio<-2>);

#undef POIDS_KGMS_DECLARE_QUANTITY_TEMPLATE
#undef POIDS_KGMS_DECLARE_UNIT_TYPE
}  // namespace kgms

#endif