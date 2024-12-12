#ifndef POIDS_KGMS_TYPES_HPP
#define POIDS_KGMS_TYPES_HPP

#include "poids/core/quantity.hpp"
#include "poids/kgms/unit.hpp"

namespace kgms {
  namespace templates {
    template <typename Scalar>
    using Unitless = poids::Quantity<Scalar,
                                     UnitType<std::ratio<0>, std::ratio<0>, std::ratio<0>>>;
    template <typename Scalar>
    using Angle = Unitless<Scalar>;

    template <typename Scalar>
    using Mass = poids::Quantity<Scalar,
                                 UnitType<std::ratio<1>, std::ratio<0>, std::ratio<0>>>;
    template <typename Scalar>
    using Length = poids::Quantity<Scalar,
                                   UnitType<std::ratio<0>, std::ratio<1>, std::ratio<0>>>;

    template <typename Scalar>
    using Time = poids::Quantity<Scalar,
                                 UnitType<std::ratio<0>, std::ratio<0>, std::ratio<1>>>;

    template <typename Scalar>
    using Area = poids::Quantity<Scalar,
                                 UnitType<std::ratio<0>, std::ratio<2>, std::ratio<0>>>;
    template <typename Scalar>
    using Volume = poids::Quantity<Scalar,
                                   UnitType<std::ratio<0>, std::ratio<3>, std::ratio<0>>>;
    template <typename Scalar>
    using SecondMomentOfArea = poids::Quantity<Scalar,
                                               UnitType<std::ratio<0>, std::ratio<4>, std::ratio<0>>>;

    template <typename Scalar>
    using Frequency = poids::Quantity<Scalar,
                                      UnitType<std::ratio<0>, std::ratio<0>, std::ratio<-1>>>;

    template <typename Scalar>
    using Velocity = poids::Quantity<Scalar,
                                     UnitType<std::ratio<0>, std::ratio<1>, std::ratio<-1>>>;
    template <typename Scalar>
    using Acceleration = poids::Quantity<Scalar,
                                         UnitType<std::ratio<0>, std::ratio<1>, std::ratio<-2>>>;

    template <typename Scalar>
    using Force = poids::Quantity<Scalar,
                                  UnitType<std::ratio<1>, std::ratio<1>, std::ratio<-2>>>;
    template <typename Scalar>
    using Energy = poids::Quantity<Scalar,
                                   UnitType<std::ratio<1>, std::ratio<2>, std::ratio<-2>>>;
  }  // namespace templates

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
}  // namespace kgms

#endif