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

  /** Indicates if the given type T is a valid unit type */
  template <typename T>
  inline constexpr bool IsValidUnit_v = IsValidUnit<T>::value;

  template <typename T,
            typename = void>
  struct UnitlessOf {
    using type = void;
  };

  template <typename T>
  struct UnitlessOf<T,
                    std::void_t<typename T::unitless_t>> {
    using type = typename T::unitless_t;
  };

  /** Indicates what the unitless type is of the given type T */
  template <typename T>
  using UnitlessOf_t = typename UnitlessOf<T>::type;

  template <typename UnitType>
  struct IsUnitless : public std::is_same<UnitType,
                                          UnitlessOf_t<UnitType>> {
  };

  /** Indicates if the given type T is unitless  */
  template <typename QuantityType>
  inline constexpr bool IsUnitless_v = IsUnitless<QuantityType>::value;

  template <typename QuantityType>
  struct ScalarOf { };

  /** Accesses the Scalar type of the given QuantityType*/
  template <typename QuantityType>
  using ScalarOf_t = typename ScalarOf<QuantityType>::type;

  template <typename QuantityType>
  struct UnitOf { };

  /** Accesses the Scalar type of the given QuantityType*/
  template <typename QuantityType>
  using UnitOf_t = typename UnitOf<QuantityType>::type;

  template <typename T>
  struct IsQuantity : public std::false_type { };

  /** Indicates if the given type T is a specialization of poids::Quantity*/
  template <typename T>
  inline constexpr bool IsQuantity_v = IsQuantity<T>::value;

  template <typename QuantityType>
  struct IsBaseUnit : public std::false_type { };

  /** Indicates if the given QuantityType is a base unit*/
  template <typename QuantityType>
  inline constexpr bool IsBaseUnit_v = IsBaseUnit<QuantityType>::value;

  template <typename UnitType, int N, unsigned D>
  struct PowerOf {
    using type = typename UnitType::template power_t<N, D>;
  };

  template <typename UnitType, int N, unsigned D>
  using PowerOf_t = typename PowerOf<UnitType, N, D>::type;

  /** Convenience function for unit systems, indicates if a given type is a
   * specialization of std::ratio
   */
  template <typename T>
  struct is_std_ratio : public std::false_type { };

  template <intmax_t Num, intmax_t Den>
  struct is_std_ratio<std::ratio<Num, Den>> : public std::true_type { };

  namespace detail {
#define POIDS_BINARY_ARITHMETIC_RESULT_TYPE(name, op)                                      \
  template <typename ScalarTypeLHS, typename ScalarTypeRHS>                                \
  struct name##Result {                                                                    \
    using type = decltype(std::declval<ScalarTypeLHS>() op std::declval<ScalarTypeRHS>()); \
  };                                                                                       \
  template <typename ScalarTypeLHS, typename ScalarTypeRHS>                                \
  using name##Result_t = typename name##Result<ScalarTypeLHS, ScalarTypeRHS>::type

    /** The resultant type of the operation LHS + RHS*/
    POIDS_BINARY_ARITHMETIC_RESULT_TYPE(Add, +);
    /** The resultant type of the operation LHS - RHS*/
    POIDS_BINARY_ARITHMETIC_RESULT_TYPE(Subtract, -);
    /** The resultant type of the operation LHS * RHS*/
    POIDS_BINARY_ARITHMETIC_RESULT_TYPE(Multiply, *);
    /** The resultant type of the operation LHS / RHS*/
    POIDS_BINARY_ARITHMETIC_RESULT_TYPE(Divide, /);

#undef POIDS_BINARY_ARITHMETIC_RESULT_TYPE
  }  // namespace detail
}  // namespace poids

#endif