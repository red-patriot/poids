#ifndef POIDS_SCALAR_SUPPORT_EIGEN_VECTOR_HPP
#define POIDS_SCALAR_SUPPORT_EIGEN_VECTOR_HPP

#include <cstddef>
#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Geometry>

#include "poids/core/quantity.hpp"
#include "poids/core/reference.hpp"
#include "poids/core/scalar_support.hpp"

namespace poids::scalar {
  template <typename Derived, int Rows, int Options>
  class ScalarMixin<Derived, typename Eigen::Matrix<double, Rows, 1, Options, Rows, 1>> {
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

    bool isApprox(const Derived& other,
                  const Quantity<double, UnitOf_t<Derived>>& tolerance =
                      poids::makeBase<_Scalar>(1.0e-6)) const {
      return derived()->data().isApprox(other.data(), tolerance.base());
    }

    _Scalar norm() const {
      return _Scalar::makeFromBaseUnitValue(derived()->data().norm());
    }

    Derived normalized() const {
      return Derived::makeFromBaseUnitValue(derived()->data().normalized());
    }

    void normalize() {
      derived()->data().normalize();
    }

    template <typename UnitTypeLHS, bool IsBaseLHS>
    auto dot(
        const Quantity<Eigen::Matrix<double, Rows, 1, Options, Rows, 1>, UnitTypeLHS, IsBaseLHS>& other) const {
      using Result = Quantity<double,
                              typename UnitOf_t<_Scalar>::template multiply_t<UnitTypeLHS>,
                              false>;

      return Result::makeFromBaseUnitValue(derived()->data().dot(other.data()));
    }

    template <typename UnitTypeLHS, bool IsBaseLHS>
    auto cross(const Quantity<Eigen::Matrix<double, Rows, 1, Options, Rows, 1>, UnitTypeLHS, IsBaseLHS>& other) const {
      static_assert(Rows == 3, "Cross-product is only defined on vectors of length 3");
      using MatrixType = Eigen::Matrix<double, Rows, 1, Options, Rows, 1>;
      using Result = Quantity<typename MatrixType::cross_product_return_type<MatrixType>::type,
                              typename UnitOf_t<_Scalar>::template multiply_t<UnitTypeLHS>,
                              false>;
      return Result::makeFromBaseUnitValue(derived()->data().cross(other.data()));
    }

   private:
    Derived* derived() { return static_cast<Derived*>(this); }
    const Derived* derived() const { return static_cast<const Derived*>(this); }
  };
}  // namespace poids::scalar

#endif