#ifndef POIDS_KGMS_EIGEN_SUPPORT_HPP
#define POIDS_KGMS_EIGEN_SUPPORT_HPP

#include <Eigen/Core>

#include "units.hpp"
#include "types.hpp"

#include "poids/scalar_support/eigen_vector.hpp"

namespace kgms {
#define POIDS_KGMS_DECLARE_VECTOR_UNIT(UnitType) \
  template <int N>                               \
  using UnitType##Vector = poids::Vector<UnitType, N>;

  POIDS_KGMS_DECLARE_VECTOR_UNIT(Unitless);
  template <int N>
  using AngleVector = UnitlessVector<N>;

  POIDS_KGMS_DECLARE_VECTOR_UNIT(Mass);
  POIDS_KGMS_DECLARE_VECTOR_UNIT(Length);
  POIDS_KGMS_DECLARE_VECTOR_UNIT(Time);

  POIDS_KGMS_DECLARE_VECTOR_UNIT(Area);
  POIDS_KGMS_DECLARE_VECTOR_UNIT(Volume);
  POIDS_KGMS_DECLARE_VECTOR_UNIT(SecondMomentOfArea);

  POIDS_KGMS_DECLARE_VECTOR_UNIT(Frequency);

  POIDS_KGMS_DECLARE_VECTOR_UNIT(Velocity);
  POIDS_KGMS_DECLARE_VECTOR_UNIT(Acceleration);

  POIDS_KGMS_DECLARE_VECTOR_UNIT(Force);
  POIDS_KGMS_DECLARE_VECTOR_UNIT(Energy);
  POIDS_KGMS_DECLARE_VECTOR_UNIT(Power);

#undef POIDS_KGMS_DECLARE_VECTOR_UNIT
}  // namespace kgms

#endif
