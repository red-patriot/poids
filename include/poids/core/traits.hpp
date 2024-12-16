#ifndef POIDS_CORE_TRAITS_HPP
#define POIDS_CORE_TRAITS_HPP

#include <cstdint>
#include <ratio>
#include <type_traits>

namespace poids {
  template <typename T,
            typename = void>
  struct IsValidUnit : public std::false_type { };

  template <typename T>
  struct IsValidUnit<T,
                     std::void_t<typename T::template multiply_t<T>,
                                 typename T::template divide_t<T>,
                                 typename T::template power_t<int{1}, unsigned{1}>>>
      : public std::true_type { };

  /** Indicates if a given type is unitless */
  template <typename UnitType, typename = void>
  struct IsUnitless : public std::false_type { };

  template <typename UnitType>
  struct IsUnitless<UnitType,
                    std::void_t<typename UnitType::unitless_t>>
      : public std::is_same<UnitType, typename UnitType::unitless_t> { };

  template <typename QuantityType>
  struct ScalarOf { };

  template <typename QuantityType>
  struct UnitOf { };

  template <typename T>
  struct IsQuantity : public std::false_type { };

  template <typename QuantityType>
  struct IsBaseUnit : public std::false_type { };

  template <typename UnitType, int N, unsigned D>
  struct PowerOf {
    using type = typename UnitType::template power_t<N, D>;
  };

  /** Indicates if the given type T is a valid unit type */
  template <typename T>
  inline constexpr bool IsValidUnit_v = IsValidUnit<T>::value;

  /** Indicates if the given type T is unitless  */
  template <typename QuantityType>
  inline constexpr bool IsUnitless_v = IsUnitless<QuantityType>::value;

  /** Accesses the Scalar type of the given QuantityType*/
  template <typename QuantityType>
  using ScalarOf_t = typename ScalarOf<QuantityType>::type;

  /** Accesses the Scalar type of the given QuantityType*/
  template <typename QuantityType>
  using UnitOf_t = typename UnitOf<QuantityType>::type;

  /** Indicates if the given type T is a specialization of poids::Quantity*/
  template <typename T>
  inline constexpr bool IsQuantity_v = IsQuantity<T>::value;

  /** Indicates if the given QuantityType is a base unit*/
  template <typename QuantityType>
  inline constexpr bool IsBaseUnit_v = IsBaseUnit<QuantityType>::value;

  template <typename UnitType, int N, unsigned D>
  using PowerOf_t = typename PowerOf<UnitType, N, D>::type;

  /** Convenience function for unit systems, indicates if a given type is a
   * specialization of std::ratio
   */
  template <typename T>
  struct is_std_ratio : public std::false_type { };

  template <intmax_t Num, intmax_t Den>
  struct is_std_ratio<std::ratio<Num, Den>> : public std::true_type { };
}  // namespace poids

#endif