#ifndef POIDS_CORE_QUANTITY_HPP
#define POIDS_CORE_QUANTITY_HPP

#include "quantity_base.hpp"
#include "traits.hpp"

namespace poids {
  template <typename ScalarType,
            typename UnitType,
            bool IsBase = false>
  class Quantity;

  template <typename ScalarType, typename UnitType>
  using BaseQuantity = Quantity<ScalarType, UnitType, true>;

  template <typename ScalarType, typename UnitType>
  constexpr BaseQuantity<ScalarType, UnitType> makeBase(const ScalarType& scalar);

  template <typename ScalarType, typename UnitType, bool IsBase>
  auto operator/(const ScalarType& lhs, const Quantity<ScalarType, UnitType, IsBase>& rhs);

  template <typename ScalarType,
            typename UnitType,
            bool IsBase>
  class Quantity : public detail::QuantityBase<Quantity<ScalarType, UnitType, IsBase>, IsBase> {
    struct InternalTag { };

   public:
    using Scalar = ScalarOf_t<Quantity<ScalarType, UnitType>>;
    using Unit = UnitOf_t<Quantity<ScalarType, UnitType>>;
    using Type = Quantity<Scalar, Unit, IsBase>;
    using BaseType = Quantity<Scalar, Unit, true>;

    Quantity() = default;

    explicit Quantity(const Scalar& baseValue) :
        value_(baseValue) {
      static_assert(IsUnitless<Unit>::value,
                    "Only a unitless poids::Quantity can only be constructed "
                    "from a Scalar. Use poids::Quantity::makeFromBaseUnitValue "
                    "instead to explicitly construct this object from the base "
                    "unit quantity");
    }

    constexpr /*implicit*/ Quantity(const BaseType& baseQuantity) :
        value_(baseQuantity.value()) { }

    explicit operator Scalar() const {
      static_assert(IsUnitless<Unit>::value,
                    "Only a unitless poids::Quantity is convertible to Scalar. "
                    "Use poids::Quantity::base instead to explicitly get the "
                    "value in base units as a Scalar.");
      return this->base();
    }

    /** Gets the value in the desired units. */
    Scalar as(const BaseType& desired) const { return value_ / desired.base(); }

    Scalar base() { return this->value_; }
    const Scalar& base() const { return this->value_; }

    static Type makeFromBaseUnitValue(const Scalar& baseValue) {
      return Type(baseValue, InternalTag{});
    }

    template <bool IsBaseRHS>
    auto operator+(const Quantity<Scalar, Unit, IsBaseRHS>& rhs) const {
      using Result = Quantity<Scalar, Unit, IsBase && IsBaseRHS>;
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
    Scalar value_{};

    constexpr Quantity(const Scalar& baseValue, InternalTag) :
        value_{baseValue} { }

    template <typename, typename, bool>
    friend class Quantity;
    friend class detail::QuantityBase<Quantity<ScalarType, UnitType, IsBase>, IsBase>;
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