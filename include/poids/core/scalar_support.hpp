#ifndef POIDS_CORE_SCALAR_SUPPORT_HPP
#define POIDS_CORE_SCALAR_SUPPORT_HPP

namespace poids::scalar {
  /** CRTP mixin to allow different scalars to add custom functionality to
   * Quantities.
   *
   * \tparam Derived the concrete derived type being instantiated
   * \tparam ScalarType the concrete scalar being instantiated
   */
  template <typename Derived,
            typename ScalarType>
  class ScalarMixin { };
}  // namespace poids::scalar

#endif