#ifndef POIDS_ANGLE_BASE_HPP
#define POIDS_ANGLE_BASE_HPP

#include "poids/core/quantity.hpp"
#include "unit.hpp"

namespace angle {
  using Angle = poids::Quantity<double,
                                UnitType<std::ratio<1>>>;

  namespace base {
    inline constexpr auto radian = poids::makeBase<::angle::Angle>(1.0);
    inline constexpr auto degree = poids::makeBase<::angle::Angle>(0.017'453'292'519'943'295);
    inline constexpr auto arcminute = poids::makeBase<::angle::Angle>(0.000'290'888'208'665'721'58);
    inline constexpr auto arcsecond = poids::makeBase<::angle::Angle>(4.848'136'811'095'359'8e-06);

    inline constexpr auto turn = poids::makeBase<::angle::Angle>(3.141'592'653'589'793);
    inline constexpr auto rotation = poids::makeBase<::angle::Angle>(6.283'185'307'179'586'2);
  }  // namespace base
}  // namespace angle

#endif