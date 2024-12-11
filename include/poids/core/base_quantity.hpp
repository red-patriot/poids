#ifndef POIDS_CORE_BASE_QUANTITY_HPP
#define POIDS_CORE_BASE_QUANTITY_HPP

#include "traits.hpp"
#include "quantity_base.hpp"

namespace poids {
  template <typename ScalarType,
            typename UnitType>
  class BaseQuantity;
  template <typename ScalarType,
            typename UnitType>
  class Quantity;

  template <typename ScalarType, typename UnitType>
  BaseQuantity<ScalarType, UnitType> makeBase(const ScalarType& scalar);

  template <typename ScalarType,
            typename UnitType>
  class BaseQuantity : public detail::QuantityBase<BaseQuantity, ScalarType, UnitType> {
    struct InternalTag { };

   public:
    using Scalar = ScalarOf_t<BaseQuantity<ScalarType, UnitType>>;
    using Unit = UnitOf_t<BaseQuantity<ScalarType, UnitType>>;
    using Type = BaseQuantity<Scalar, Unit>;

    explicit BaseQuantity(const Scalar& baseValue) :
        value_(baseValue) {
      static_assert(IsUnitless<Unit>::value,
                    "Only a unitless poids::BaseQuantity can only be constructed from a Scalar. Use poids::BaseQuantity::makeBase instead to explicitly construct this object");
    }

    /** Gets the value in the base\ units. */
    Scalar value() const { return value_; }

    using detail::QuantityBase<BaseQuantity, ScalarType, UnitType>::operator+;

    Quantity<Scalar, Unit> operator+(const Quantity<Scalar, Unit>& rhs) const {
      return Quantity<Scalar, Unit>{this->value_ + rhs.value_,
                                    typename Quantity<Scalar, Unit>::InternalTag{}};
    }

    template <typename ScalarTypeRHS, typename UnitTypeRHS>
    auto operator*(const BaseQuantity<ScalarTypeRHS, UnitTypeRHS>& rhs) const {
      using ResultType = BaseQuantity<Scalar,
                                      typename Unit::multiply_t<UnitTypeRHS>>;

      return ResultType{this->base() * rhs.base(), typename ResultType::InternalTag{}};
    }

    template <typename ScalarTypeRHS, typename UnitTypeRHS>
    auto operator*(const Quantity<ScalarTypeRHS, UnitTypeRHS>& rhs) const {
      using ResultType = Quantity<Scalar,
                                  typename Unit::multiply_t<UnitTypeRHS>>;

      return ResultType{this->base() * rhs.base(), typename ResultType::InternalTag{}};
    }

    auto operator*(const Scalar& rhs) const {
      using ResultType = Quantity<Scalar, Unit>;
      return ResultType{this->base() * rhs, typename ResultType::InternalTag{}};
    }

    friend auto operator*(const Scalar& lhs, const Type& rhs) {
      return rhs.operator*(lhs);
    }

    template <typename ScalarTypeRHS, typename UnitTypeRHS>
    auto operator/(const BaseQuantity<ScalarTypeRHS, UnitTypeRHS>& rhs) const {
      using ResultType = BaseQuantity<ScalarType,
                                      typename Unit::divide_t<UnitTypeRHS>>;

      return ResultType{this->base() / rhs.base(), typename ResultType::InternalTag{}};
    }

    template <typename ScalarTypeRHS, typename UnitTypeRHS>
    auto operator/(const Quantity<ScalarTypeRHS, UnitTypeRHS>& rhs) const {
      using ResultType = Quantity<ScalarType,
                                  typename Unit::divide_t<UnitTypeRHS>>;

      return ResultType{this->base() / rhs.base(), typename ResultType::InternalTag{}};
    }

    auto operator/(const Scalar& rhs) const {
      using ResultType = Quantity<Scalar, Unit>;
      return ResultType{this->base() / rhs, typename ResultType::InternalTag{}};
    }

    friend auto operator/(const Scalar& lhs, const Type& rhs) {
      using UnitlessQuantity = Quantity<Scalar, typename Unit::unitless_t>;
      return UnitlessQuantity{lhs, typename UnitlessQuantity::InternalTag{}} / rhs;
    }

    using detail::QuantityBase<BaseQuantity, ScalarType, UnitType>::operator==;
    using detail::QuantityBase<BaseQuantity, ScalarType, UnitType>::operator!=;
    using detail::QuantityBase<BaseQuantity, ScalarType, UnitType>::operator<;
    using detail::QuantityBase<BaseQuantity, ScalarType, UnitType>::operator>;
    using detail::QuantityBase<BaseQuantity, ScalarType, UnitType>::operator>=;
    using detail::QuantityBase<BaseQuantity, ScalarType, UnitType>::operator<=;

    bool operator==(const Quantity<Scalar, Unit>& rhs) const {
      return this->value_ == rhs.value_;
    }

    bool operator!=(const Quantity<Scalar, Unit>& rhs) const {
      return !this->operator==(rhs);
    }

    bool operator<(const Quantity<Scalar, Unit>& rhs) const {
      return this->value_ < rhs.value_;
    }

    bool operator>(const Quantity<Scalar, Unit>& rhs) const {
      return rhs.operator<(*this);
    }
    bool operator<=(const Quantity<Scalar, Unit>& rhs) const {
      return this->operator==(rhs) || this->operator<(rhs);
    }
    bool operator>=(const Quantity<Scalar, Unit>& rhs) const {
      return this->operator==(rhs) || this->operator>(rhs);
    }

   private:
    Scalar value_{};

    BaseQuantity(const Scalar& baseValue, InternalTag) :
        value_{baseValue} { }

    template <template <typename, typename> typename, typename, typename>
    friend class detail::QuantityBase;
    template <typename, typename>
    friend class BaseQuantity;

    friend BaseQuantity<ScalarType, UnitType> makeBase<ScalarType, UnitType>(const ScalarType& scalar);
  };

  template <typename ScalarType, typename UnitType>
  inline BaseQuantity<ScalarType, UnitType> makeBase(const ScalarType& scalar) {
    return BaseQuantity<ScalarType, UnitType>{scalar,
                                              typename BaseQuantity<ScalarType, UnitType>::InternalTag{}};
  };

  /** If a quantity is tested for being dimensionless, forward the request to its DimensionType*/
  template <typename Scalar, typename UnitType>
  struct IsUnitless<BaseQuantity<Scalar, UnitType>> : public IsUnitless<UnitType> { };

  template <typename ScalarType, typename UnitType>
  struct ScalarOf<BaseQuantity<ScalarType, UnitType>> {
    using type = ScalarType;
  };

  template <typename ScalarType, typename UnitType>
  struct UnitOf<BaseQuantity<ScalarType, UnitType>> {
    using type = UnitType;
  };
}  // namespace poids

#endif