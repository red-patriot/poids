#ifndef POIDS_SCALAR_SUPPORT_EIGEN_VECTOR_HPP
#define POIDS_SCALAR_SUPPORT_EIGEN_VECTOR_HPP

#include <cstddef>
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
    /** Accesses an element in-place */
    _Reference operator[](int i) {
      return _Reference::makeReference(derived()->data()[i]);
    }

    /** Accesses the value of an element */
    _Scalar operator[](int i) const {
      return _Scalar::makeFromBaseUnitValue(derived()->data()[i]);
    }

    /** Returns the number of elements in the Vector*/
    Eigen::Index size() const {
      return derived()->data().size();
    }

    _Scalar x() const { return _Scalar::makeFromBaseUnitValue(derived()->data().x()); }
    _Reference x() { return _Reference::makeReference(derived()->data().x()); }

    _Scalar y() const { return _Scalar::makeFromBaseUnitValue(derived()->data().y()); }
    _Reference y() { return _Reference::makeReference(derived()->data().y()); }

    _Scalar z() const { return _Scalar::makeFromBaseUnitValue(derived()->data().z()); }
    _Reference z() { return _Reference::makeReference(derived()->data().z()); }

    _Scalar w() const { return _Scalar::makeFromBaseUnitValue(derived()->data().w()); }
    _Reference w() { return _Reference::makeReference(derived()->data().w()); }

   private:
    Derived* derived() { return static_cast<Derived*>(this); }
    const Derived* derived() const { return static_cast<const Derived*>(this); }
  };
}  // namespace poids::scalar

#endif