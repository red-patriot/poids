#ifndef POIDS_SCALAR_SUPPORT_COMPLEX_HPP
#define POIDS_SCALAR_SUPPORT_COMPLEX_HPP

#include <complex>

#include "poids/core/scalar_support.hpp"

namespace poids::scalar {
  template <typename Derived,
            typename T>
  class ScalarMixin<Derived, std::complex<T>> {
   public:
    T real() const {
      return derived()->base().real();
    }

    T imag() const {
      return derived()->base().imag();
    }

   private:
    Derived* derived() { return static_cast<Derived*>(this); }
    const Derived* derived() const { return static_cast<const Derived*>(this); }
  };
}  // namespace poids::scalar

#endif