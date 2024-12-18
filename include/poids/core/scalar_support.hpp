#ifndef POIDS_CORE_MIXIN_HPP
#define POIDS_CORE_MIXIN_HPP

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

  template <typename ScalarTypeLHS, typename ScalarTypeRHS>
  struct ArithmeticResult {
    using type = decltype(std::declval<ScalarTypeLHS>() * std::declval<ScalarTypeRHS>());
  };

  template <typename ScalarTypeLHS, typename ScalarTypeRHS>
  using ArithmeticResult_t = typename ArithmeticResult<ScalarTypeLHS, ScalarTypeRHS>::type;
}  // namespace poids::scalar

#endif