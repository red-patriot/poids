#ifndef POIDS_SCALAR_SUPPORT_EIGEN_VECTOR_HPP
#define POIDS_SCALAR_SUPPORT_EIGEN_VECTOR_HPP

#include <eigen3/Eigen/Core>

#include "poids/core/quantity.hpp"
#include "poids/core/reference.hpp"
#include "poids/core/scalar_support.hpp"

namespace poids::scalar {
  template <typename Derived, int N>
  class ScalarMixin<Derived, typename Eigen::Matrix<double, N, 1, 0, N, 1>> {
    // TODO: Support other Eigen scalars than double^

    using _Scalar = Quantity<double, UnitOf_t<Derived>, IsBaseUnit_v<Derived>>;
    using _Reference = ReferenceQuantity<double, UnitOf_t<Derived>>;
    using _ConstReference = const _Reference;

   public:
    _Reference operator[](int i) {
      return _Reference::makeReference(derived()->data()[i]);
    }

    _Scalar operator[](int i) const {
      return _Scalar::makeFromBaseUnitValue(derived()->data()[i]);
    }

   private:
    Derived* derived() { return static_cast<Derived*>(this); }
    const Derived* derived() const { return static_cast<const Derived*>(this); }
  };
}  // namespace poids::scalar

#endif