#ifndef POIDS_SCALAR_SUPPORT_COMPLEX_HPP
#define POIDS_SCALAR_SUPPORT_COMPLEX_HPP

#include <complex>

#include "poids/core/scalar_support.hpp"

namespace poids::scalar {
  /** Additional functionality for complex Quantities*/
  template <typename Derived,
            typename T>
  class ScalarMixin<Derived, std::complex<T>> {
   public:
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