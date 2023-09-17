#ifndef POIDS_UTIL_DIMENSION_H
#define POIDS_UTIL_DIMENSION_H

#include <type_traits>

// TODO: Define generic Dimension concept here
namespace poids {
  template <typename Dim>
  concept Dimension = requires(Dim d) {
    { std::is_nothrow_constructible_v<Dim> };
    { std::is_nothrow_destructible_v<Dim> };
  };
}

#endif
