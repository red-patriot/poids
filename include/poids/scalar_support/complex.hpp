#ifndef POIDS_SCALAR_SUPPORT_COMPLEX_HPP
#define POIDS_SCALAR_SUPPORT_COMPLEX_HPP

#include <complex>

#include "poids/core/quantity.hpp"
#include "poids/core/reference.hpp"
#include "poids/core/scalar_support.hpp"

namespace poids::scalar {
  /** Additional functionality for complex Quantities*/
  template <typename Derived,
            typename T>
  class ScalarMixin<Derived, std::complex<T>> {
   private:
    using RealQuantity = Quantity<T, UnitOf_t<Derived>, IsBaseUnit_v<Derived>>;

   public:
    /**Returns a mutable reference to the real part of this quantity*/
    ReferenceQuantity<T, UnitOf_t<Derived>> realm() {
      return ReferenceQuantity<T, UnitOf_t<Derived>>::makeReference(reinterpret_cast<T(&)[2]>(derived()->data())[0]);
    }

    /**Returns a mutable reference to the imaginary part of this quantity*/
    ReferenceQuantity<T, UnitOf_t<Derived>> imagm() {
      return ReferenceQuantity<T, UnitOf_t<Derived>>::makeReference(reinterpret_cast<T(&)[2]>(derived()->data())[1]);
    }

    /**Returns the real part of this quantity*/
    RealQuantity real() const {
      return RealQuantity::makeFromBaseUnitValue(derived()->base().real());
    }

    /**Returns the imaginary part of this quantity*/
    RealQuantity imag() const {
      return RealQuantity::makeFromBaseUnitValue(derived()->base().imag());
    }

    /** Accesses the real component in base units*/
    T realBase() const {
      return derived()->base().real();
    }

    /** Accesses the imaginary component in base units*/
    T imagBase() const {
      return derived()->base().imag();
    }

   private:
    Derived* derived() { return static_cast<Derived*>(this); }
    const Derived* derived() const { return static_cast<const Derived*>(this); }
  };
}  // namespace poids::scalar

#endif