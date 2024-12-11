#ifndef POIDS_CORE_TRAITS_HPP
#define POIDS_CORE_TRAITS_HPP

#include <type_traits>

namespace poids {
  template <typename T, typename = void>
  struct IsUnitless : public std::false_type { };

  template <typename T>
  struct IsUnitless<T, std::void_t<typename T::unitless_t>> : public std::is_same<T, typename T::unitless_t> { };

  template <typename T>
  struct ScalarOf { };

  template <typename T>
  struct UnitOf { };

  template <typename T>
  constexpr bool IsUnitless_v = IsUnitless<T>::value;

  template <typename T>
  using ScalarOf_t = typename ScalarOf<T>::type;

  template <typename T>
  using UnitOf_t = typename UnitOf<T>::type;

}  // namespace poids

#endif