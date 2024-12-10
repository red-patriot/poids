#ifndef POIDS_CORE_QUANTITY_HPP
#define POIDS_CORE_QUANTITY_HPP

#include "traits.hpp"
#include "quantity_base.hpp"
#include "base_quantity.hpp"

namespace poids {
  template <typename ScalarType,
            typename UnitType>
  class Quantity : public detail::QuantityBase<Quantity<ScalarType, UnitType>> {
    friend detail::QuantityBase<Quantity<ScalarType, UnitType>>;
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
                    "Only a unitless poids::Quantity can only be constructed from a Scalar. Use poids::Quantity::makeFromBaseUnitValue instead to explicitly construct this object");
    }

    /*implicit*/ Quantity(const BaseType& baseQuantity) :
        value_(baseQuantity.value()) { }

    /** Gets the value in the desired units. */
    Scalar as(const BaseType& desired) const { return value_ / desired.base(); }

    static Type makeFromBaseUnitValue(const Scalar& baseValue) {
      return Type(baseValue, InternalTag{});
    }

   private:
    Scalar value_{};

    Quantity(const Scalar& baseValue, InternalTag) :
        value_{baseValue} { }
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
}  // namespace poids

#endif