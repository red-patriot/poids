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
  };
}  // namespace poids::scalar

#endif