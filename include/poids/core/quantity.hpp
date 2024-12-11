#ifndef POIDS_CORE_QUANTITY_HPP
#define POIDS_CORE_QUANTITY_HPP

#include "traits.hpp"
#include "quantity_base.hpp"
#include "base_quantity.hpp"

namespace poids {
  template <typename ScalarType,
            typename UnitType>
  class Quantity : public detail::QuantityBase<Quantity, ScalarType, UnitType> {
    struct InternalTag { };

   public:
    using Scalar = ScalarOf_t<Quantity<ScalarType, UnitType>>;
    using Unit = UnitOf_t<Quantity<ScalarType, UnitType>>;
    using Type = Quantity<Scalar, Unit>;
    using BaseType = BaseQuantity<Scalar, Unit>;

    Quantity() = default;

    /*implicit*/ Quantity(const Scalar& baseValue) :
        value_(baseValue) {
      static_assert(IsUnitless<Unit>::value,
                    "Only a unitless poids::Quantity can only be constructed "
                    "from a Scalar. Use poids::Quantity::makeFromBaseUnitValue "
                    "instead to explicitly construct this object from the base "
                    "unit quantity");
    }

    /*implicit*/ Quantity(const BaseType& baseQuantity) :
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

    static Type makeFromBaseUnitValue(const Scalar& baseValue) {
      return Type(baseValue, InternalTag{});
    }

    template <typename ScalarTypeRHS, typename UnitTypeRHS>
    auto operator*(const Quantity<ScalarTypeRHS, UnitTypeRHS>& rhs) const {
      using ResultType = Quantity<Scalar,
                                  typename Unit::multiply_t<UnitTypeRHS>>;

      return ResultType{this->base() * rhs.base(), typename ResultType::InternalTag{}};
    }

    template <typename ScalarTypeRHS, typename UnitTypeRHS>
    auto operator*(const BaseQuantity<ScalarTypeRHS, UnitTypeRHS>& rhs) const {
      using ResultType = Quantity<Scalar,
                                  typename Unit::multiply_t<UnitTypeRHS>>;

      return ResultType{this->base() * rhs.base(), typename ResultType::InternalTag{}};
    }

    auto operator*(const Scalar& rhs) const {
      return Type{this->base() * rhs, InternalTag{}};
    }

    friend auto operator*(const Scalar& lhs, const Type& rhs) {
      return rhs.operator*(lhs);
    }

    template <typename ScalarTypeRHS, typename UnitTypeRHS>
    auto operator/(const Quantity<ScalarTypeRHS, UnitTypeRHS>& rhs) const {
      using ResultType = Quantity<ScalarType,
                                  typename Unit::divide_t<UnitTypeRHS>>;

      return ResultType{this->base() / rhs.base(), typename ResultType::InternalTag{}};
    }

    template <typename ScalarTypeRHS, typename UnitTypeRHS>
    auto operator/(const BaseQuantity<ScalarTypeRHS, UnitTypeRHS>& rhs) const {
      using ResultType = Quantity<ScalarType,
                                  typename Unit::divide_t<UnitTypeRHS>>;

      return ResultType{this->base() / rhs.base(), typename ResultType::InternalTag{}};
    }

    auto operator/(const Scalar& rhs) const {
      return Type{this->base() / rhs, InternalTag{}};
    }

    friend auto operator/(const Scalar& lhs, const Type& rhs) {
      using UnitlessQuantity = Quantity<Scalar, typename Unit::unitless_t>;
      return UnitlessQuantity{lhs, typename UnitlessQuantity::InternalTag{}} / rhs;
    }

    using detail::QuantityBase<Quantity, ScalarType, UnitType>::operator==;
    using detail::QuantityBase<Quantity, ScalarType, UnitType>::operator!=;
    using detail::QuantityBase<Quantity, ScalarType, UnitType>::operator<;
    using detail::QuantityBase<Quantity, ScalarType, UnitType>::operator>;
    using detail::QuantityBase<Quantity, ScalarType, UnitType>::operator>=;
    using detail::QuantityBase<Quantity, ScalarType, UnitType>::operator<=;

    bool operator==(const BaseType& rhs) const {
      return this->value_ == rhs.value_;
    }

    bool operator!=(const BaseType& rhs) const {
      return !this->operator==(rhs);
    }

    bool operator<(const BaseType& rhs) const {
      return this->value_ < rhs.value_;
    }

    bool operator>(const BaseType& rhs) const {
      return rhs.operator<(*this);
    }
    bool operator<=(const BaseType& rhs) const {
      return this->operator==(rhs) || this->operator<(rhs);
    }
    bool operator>=(const BaseType& rhs) const {
      return this->operator==(rhs) || this->operator>(rhs);
    }

   private:
    Scalar value_{};

    Quantity(const Scalar& baseValue, InternalTag) :
        value_{baseValue} { }

    template <template <typename, typename> typename, typename, typename>
    friend class detail::QuantityBase;
    template <typename, typename>
    friend class Quantity;
    template <typename, typename>
    friend class BaseQuantity;
  };

  /** If a quantity is tested for being dimensionless, forward the request to its DimensionType*/
  template <typename Scalar, typename UnitType>
  struct IsUnitless<Quantity<Scalar, UnitType>> : public IsUnitless<UnitType> { };

  template <typename ScalarType, typename UnitType>
  struct ScalarOf<Quantity<ScalarType, UnitType>> {
    using type = ScalarType;
  };

  template <typename ScalarType, typename UnitType>
  struct UnitOf<Quantity<ScalarType, UnitType>> {
    using type = UnitType;
  };

  template <typename ScalarType, typename UnitType>
  Quantity(BaseQuantity<ScalarType, UnitType>) -> Quantity<ScalarType, UnitType>;

  template <typename QuantityType>
  inline BaseQuantity<ScalarOf_t<QuantityType>, UnitOf_t<QuantityType>> makeBase(const ScalarOf_t<QuantityType>& scalar) {
    return makeBase<ScalarOf_t<QuantityType>, UnitOf_t<QuantityType>>(scalar);
  }
}  // namespace poids

#endif