#ifndef POIDS_SCALAR_SUPPORT_EIGEN_VECTOR_HPP
#define POIDS_SCALAR_SUPPORT_EIGEN_VECTOR_HPP

#include <eigen3/Eigen/Core>

#include "poids/core/quantity.hpp"
#include "poids/core/reference.hpp"
#include "poids/core/scalar_support.hpp"

namespace poids::scalar {
  template <typename Derived,
            int N>
  class ScalarMixin<Derived, Eigen::Vector<double, N>> {
  };
}  // namespace poids::scalar

#endif