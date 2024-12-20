#ifndef POIDS_KGMS_TYPES_HPP
#define POIDS_KGMS_TYPES_HPP

#include "poids/core/quantity.hpp"
#include "poids/kgms/units.hpp"

namespace kgms {
  /****************************************************************************/

  using Unitless = templates::Unitless<double>;
  using Angle = templates::Angle<double>;

  using Mass = templates::Mass<double>;
  using Length = templates::Length<double>;

  using Time = templates::Time<double>;

  using Area = templates::Area<double>;
  using Volume = templates::Volume<double>;
  using SecondMomentOfArea = templates::SecondMomentOfArea<double>;

  using Frequency = templates::Frequency<double>;

  using Velocity = templates::Velocity<double>;
  using Acceleration = templates::Acceleration<double>;

  using Force = templates::Force<double>;
  using Energy = templates::Energy<double>;
  using Power = templates::Power<double>;

  /****************************************************************************/

  using Unitless_l = templates::Unitless<long double>;
  using Angle_l = templates::Angle<long double>;

  using Mass_l = templates::Mass<long double>;
  using Length_l = templates::Length<long double>;

  using Time_l = templates::Time<long double>;

  using Area_l = templates::Area<long double>;
  using Volume_l = templates::Volume<long double>;
  using SecondMomentOfArea_l = templates::SecondMomentOfArea<long double>;

  using Frequency_l = templates::Frequency<long double>;

  using Velocity_l = templates::Velocity<long double>;
  using Acceleration_l = templates::Acceleration<long double>;

  using Force_l = templates::Force<long double>;
  using Energy_l = templates::Energy<long double>;
  using Power_l = templates::Power<long double>;
}  // namespace kgms

#endif