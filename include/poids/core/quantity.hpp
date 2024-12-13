#ifndef POIDS_CORE_QUANTITY_HPP
#define POIDS_CORE_QUANTITY_HPP

#include "quantity_base.hpp"
#include "scalar_support.hpp"
#include "traits.hpp"

namespace poids {
  /** A quantity with a value and units.
   *
   * \tparam ScalarType The type of the scalar of the quantity
   * \tparam UnitType The unit type of the quantity
   * \tparam IsBase indicates if this type can be used for value extraction with Quantity::as
   */
  template <typename ScalarType,
            typename UnitType,
            bool IsBase = false>
  class Quantity;

  /** A base quantity that can be used for value extraction with Quantity::as */
  template <typename ScalarType, typename UnitType>
  using BaseQuantity = Quantity<ScalarType, UnitType, true>;

  /** Constructs a base quantity with the given Scalar and Unit types. */
  template <typename ScalarType, typename UnitType>
  constexpr BaseQuantity<ScalarType, UnitType> makeBase(const ScalarType& scalar);

  template <typename ScalarType, typename UnitType, bool IsBase>
  auto operator/(const ScalarType& lhs, const Quantity<ScalarType, UnitType, IsBase>& rhs);

  template <typename ScalarType,
            typename UnitType,
            bool IsBase>
  class Quantity : public detail::QuantityMixin<Quantity<ScalarType, UnitType, IsBase>, IsBase>,
                   public scalar::ScalarMixin<Quantity<ScalarType, UnitType, IsBase>, ScalarType> {
    struct InternalTag { };

   public:
    /** The scalar type of this Quantity */
    using Scalar = ScalarOf_t<Quantity<ScalarType, UnitType>>;
    /** The unit type of this Quantity */
    using Unit = UnitOf_t<Quantity<ScalarType, UnitType>>;
    /** Identity of this Quantity */
    using Type = Quantity<Scalar, Unit, IsBase>;
    /** The base type of this Quantity */
    using BaseType = Quantity<Scalar, Unit, true>;

    Quantity() = default;

    constexpr explicit Quantity(const Scalar& baseValue) :
        value_(baseValue) {
      static_assert(IsUnitless<Unit>::value,
                    "Only a unitless poids::Quantity can only be constructed "
                    "from a Scalar. Use poids::Quantity::makeFromBaseUnitValue "
                    "instead to explicitly construct this object from the base "
                    "unit quantity");
    }

    /** Implicitly converts from a BaseQuantity to its corresponding Quantity */
    constexpr /*implicit*/ Quantity(const BaseType& baseQuantity) :
        value_(baseQuantity.value()) { }

    /** Retrieves the scalar value of this quantity.
     * \note It is only valid to call this on a quantity where poids::IsUnitless_v<Unit> is true
     */
    constexpr explicit operator Scalar() const {
      static_assert(IsUnitless<Unit>::value,
                    "Only a unitless poids::Quantity is convertible to Scalar. "
                    "Use poids::Quantity::base instead to explicitly get the "
                    "value in base units as a Scalar.");
      return this->base();
    }

    /** Gets the value in the desired units. */
    constexpr Scalar as(const BaseType& desired) const { return value_ / desired.value(); }

    /** Gets the value of this quantity in base units.
     * \warning Quantity::as should be preferred over this function to get the quantity value
     * because it is more explicit
     */
    Scalar base() { return this->value_; }
    /** Gets the value of this quantity in base units.
     * \warning Quantity::as should be preferred over this function to get the quantity value
     * because it is more explicit
     */
    const Scalar& base() const { return this->value_; }

    /** Constructs a Quantity with the given baseValue in base units. */
    static Type makeFromBaseUnitValue(const Scalar& baseValue) {
      return Type(baseValue, InternalTag{});
    }

    template <typename ScalarTypeRHS, bool IsBaseRHS>
    auto operator+(const Quantity<ScalarTypeRHS, Unit, IsBaseRHS>& rhs) const {
      using Result = Quantity<scalar::ArithmeticResult_t<Scalar, ScalarTypeRHS>,
                              Unit,
                              IsBase && IsBaseRHS>;
      return Result{this->value_ + rhs.value_,
                    typename Result::InternalTag{}};
    }

    template <bool IsBaseRHS>
    auto operator-(const Quantity<Scalar, Unit, IsBaseRHS>& rhs) const {
      using Result = Quantity<Scalar, Unit, IsBase && IsBaseRHS>;
      return Result{this->value_ - rhs.value_,
                    typename Result::InternalTag{}};
    }

    template <typename ScalarTypeRHS, typename UnitTypeRHS, bool IsBaseRHS>
    auto operator*(const Quantity<ScalarTypeRHS, UnitTypeRHS, IsBaseRHS>& rhs) const {
      using Result = Quantity<Scalar,
                              typename Unit::multiply_t<UnitTypeRHS>,
                              IsBase && IsBaseRHS>;

      return Result{this->base() * rhs.base(), typename Result::InternalTag{}};
    }

    auto operator*(const Scalar& rhs) const {
      using Result = Quantity<Scalar, Unit, false>;
      return Result{this->base() * rhs,
                    typename Result::InternalTag{}};
    }

    template <typename ScalarTypeRHS, typename UnitTypeRHS, bool IsBaseRHS>
    auto operator/(const Quantity<ScalarTypeRHS, UnitTypeRHS, IsBaseRHS>& rhs) const {
      using Result = Quantity<ScalarType,
                              typename Unit::divide_t<UnitTypeRHS>,
                              IsBase && IsBaseRHS>;

      return Result{this->base() / rhs.base(), typename Result::InternalTag{}};
    }

    auto operator/(const Scalar& rhs) const {
      using Result = Quantity<Scalar, Unit, false>;
      return Result{this->base() / rhs,
                    typename Result::InternalTag{}};
    }

    template <bool OtherBase>
    bool operator==(const Quantity<Scalar, Unit, OtherBase>& rhs) const {
      return this->value_ == rhs.value_;
    }

    template <bool OtherBase>
    bool operator!=(const Quantity<Scalar, Unit, OtherBase>& rhs) const {
      return !this->operator==(rhs);
    }

    template <bool OtherBase>
    bool operator<(const Quantity<Scalar, Unit, OtherBase>& rhs) const {
      return this->value_ < rhs.value_;
    }

    template <bool OtherBase>
    bool operator>(const Quantity<Scalar, Unit, OtherBase>& rhs) const {
      return rhs.operator<(*this);
    }

    template <bool OtherBase>
    bool operator<=(const Quantity<Scalar, Unit, OtherBase>& rhs) const {
      return this->operator==(rhs) || this->operator<(rhs);
    }

    template <bool OtherBase>
    bool operator>=(const Quantity<Scalar, Unit, OtherBase>& rhs) const {
      return this->operator==(rhs) || this->operator>(rhs);
    }

   private:
    Scalar value_{}; /**< The Scalar value of this quantity in base units. */

    constexpr Quantity(const Scalar& baseValue, InternalTag) :
        value_{baseValue} { }

    template <typename, typename, bool>
    friend class Quantity;
    friend class detail::QuantityMixin<Quantity<ScalarType, UnitType, IsBase>, IsBase>;
    friend constexpr BaseQuantity<ScalarType, UnitType> makeBase<ScalarType, UnitType>(const ScalarType& scalar);
  };

  template <typename ScalarType, typename UnitType, bool IsBase>
  auto operator*(const ScalarType& lhs, const Quantity<ScalarType, UnitType, IsBase>& rhs) {
    return rhs.operator*(lhs);
  }

  template <typename ScalarType, typename UnitType, bool IsBase>
  auto operator/(const ScalarType& lhs, const Quantity<ScalarType, UnitType, IsBase>& rhs) {
    using UnitlessQuantity = Quantity<ScalarType, typename UnitType::unitless_t, false>;
    return UnitlessQuantity{lhs} / rhs;
  }

  /** If a quantity is tested for being dimensionless, forward the request to its DimensionType*/
  template <typename Scalar, typename UnitType, bool IsBase>
  struct IsUnitless<Quantity<Scalar, UnitType, IsBase>> : public IsUnitless<UnitType> { };

  template <typename ScalarType, typename UnitType, bool IsBase>
  struct ScalarOf<Quantity<ScalarType, UnitType, IsBase>> {
    using type = ScalarType;
  };

  template <typename ScalarType, typename UnitType, bool IsBase>
  struct UnitOf<Quantity<ScalarType, UnitType, IsBase>> {
    using type = UnitType;
  };

  template <typename ScalarType, typename UnitType>
  Quantity(BaseQuantity<ScalarType, UnitType>) -> Quantity<ScalarType, UnitType>;

  template <typename ScalarType, typename UnitType>
  inline constexpr BaseQuantity<ScalarType, UnitType> makeBase(const ScalarType& scalar) {
    return BaseQuantity<ScalarType, UnitType>{scalar,
                                              typename BaseQuantity<ScalarType, UnitType>::InternalTag{}};
  };

  template <typename QuantityType>
  inline constexpr BaseQuantity<ScalarOf_t<QuantityType>, UnitOf_t<QuantityType>> makeBase(const ScalarOf_t<QuantityType>& scalar) {
    return makeBase<ScalarOf_t<QuantityType>, UnitOf_t<QuantityType>>(scalar);
  }
}  // namespace poids

#endif