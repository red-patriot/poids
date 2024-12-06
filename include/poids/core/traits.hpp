#ifndef POIDS_CORE_TRAITS_HPP
#define POIDS_CORE_TRAITS_HPP

#include <type_traits>

namespace poids {
  template <typename T>
  struct IsUnitless : public std::false_type { };
}  // namespace poids

#endif