#ifndef POIDS_UTIL_DIMENSION_H
#define POIDS_UTIL_DIMENSION_H

#include <type_traits>
#include <concepts>

// TODO: Define generic Dimension concept here
namespace poids {
  template <typename Dim>
  concept Dimension = requires(Dim a) {
    { std::is_nothrow_constructible_v<Dim> };
    { std::is_nothrow_destructible_v<Dim> };
    { -a } -> std::same_as<Dim>;
    { a + a } -> std::same_as<Dim>;
    { a - a } -> std::same_as<Dim>;
  } && std::equality_comparable<Dim>;
}

#endif
