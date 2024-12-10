#ifndef POIDS_KGMS_TYPES_HPP
#define POIDS_KGMS_TYPES_HPP

#include <poids/core/quantity.hpp>
#include <poids/kgms/unit.hpp>

namespace kgms {
  using Mass = poids::Quantity<double,
                               UnitType<std::ratio<1>, std::ratio<0>, std::ratio<0>>>;

  using Length = poids::Quantity<double,
                                 UnitType<std::ratio<0>, std::ratio<1>, std::ratio<0>>>;

  using Time = poids::Quantity<double,
                               UnitType<std::ratio<0>, std::ratio<0>, std::ratio<1>>>;

  using Area = poids::Quantity<double,
                               UnitType<std::ratio<0>, std::ratio<2>, std::ratio<0>>>;
  using Volume = poids::Quantity<double,
                                 UnitType<std::ratio<0>, std::ratio<3>, std::ratio<0>>>;
  using SecondMomentOfArea = poids::Quantity<double,
                                             UnitType<std::ratio<0>, std::ratio<4>, std::ratio<0>>>;

  using Velocity = poids::Quantity<double,
                                   UnitType<std::ratio<0>, std::ratio<1>, std::ratio<-1>>>;
  using Acceleration = poids::Quantity<double,
                                       UnitType<std::ratio<0>, std::ratio<1>, std::ratio<-2>>>;

  using Force = poids::Quantity<double,
                                UnitType<std::ratio<1>, std::ratio<1>, std::ratio<-2>>>;
}  // namespace kgms

#endif