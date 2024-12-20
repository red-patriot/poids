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

    using SingleQuantity = Quantity<double, UnitOf_t<Derived>, IsBaseUnit_v<Derived>>;
    using SingleReference = ReferenceQuantity<double, UnitOf_t<Derived>>;

   public:
    /** Accesses an element in-place */
    SingleReference operator[](int i) {
      return SingleReference::makeReference(derived()->data()[i]);
    }

    /** Accesses the value of an element */
    SingleQuantity operator[](int i) const {
      return SingleQuantity::makeFromBaseUnitValue(derived()->data()[i]);
    }

    /** Returns the number of elements in the Vector*/
    Eigen::Index size() const {
      return derived()->data().size();
    }

    SingleQuantity x() const { return SingleQuantity::makeFromBaseUnitValue(derived()->data().x()); }
    SingleReference x() { return SingleReference::makeReference(derived()->data().x()); }

    SingleQuantity y() const { return SingleQuantity::makeFromBaseUnitValue(derived()->data().y()); }
    SingleReference y() { return SingleReference::makeReference(derived()->data().y()); }

    SingleQuantity z() const { return SingleQuantity::makeFromBaseUnitValue(derived()->data().z()); }
    SingleReference z() { return SingleReference::makeReference(derived()->data().z()); }

    SingleQuantity w() const { return SingleQuantity::makeFromBaseUnitValue(derived()->data().w()); }
    SingleReference w() { return SingleReference::makeReference(derived()->data().w()); }

    bool isApprox(const Derived& other,
                  const Quantity<double, UnitOf_t<Derived>>& tolerance =
                      poids::makeBase<SingleQuantity>(1.0e-6)) const {
      return derived()->data().isApprox(other.data(), tolerance.base());
    }

    SingleQuantity norm() const {
      return SingleQuantity::makeFromBaseUnitValue(derived()->data().norm());
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
                              typename UnitOf_t<SingleQuantity>::template multiply_t<UnitTypeLHS>,
                              false>;

      return Result::makeFromBaseUnitValue(derived()->data().dot(other.data()));
    }

    template <typename UnitTypeLHS, bool IsBaseLHS>
    auto cross(const Quantity<Eigen::Matrix<double, Rows, 1, Options, Rows, 1>, UnitTypeLHS, IsBaseLHS>& other) const {
      static_assert(Rows == 3, "Cross-product is only defined on vectors of length 3");
      using MatrixType = Eigen::Matrix<double, Rows, 1, Options, Rows, 1>;
      using Result = Quantity<typename MatrixType::cross_product_return_type<MatrixType>::type,
                              typename UnitOf_t<SingleQuantity>::template multiply_t<UnitTypeLHS>,
                              false>;
      return Result::makeFromBaseUnitValue(derived()->data().cross(other.data()));
    }

   private:
    Derived* derived() { return static_cast<Derived*>(this); }
    const Derived* derived() const { return static_cast<const Derived*>(this); }
  };
}  // namespace poids::scalar

#endif