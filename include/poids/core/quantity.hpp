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
  template <typename Scalar, typename DimensionType>
  struct IsUnitless<Quantity<Scalar, DimensionType>> : public IsUnitless<DimensionType> { };

  template <typename ScalarType, typename DimensionType>
  struct ScalarOf<Quantity<ScalarType, DimensionType>> {
    using type = ScalarType;
  };

  template <typename ScalarType, typename DimensionType>
  struct UnitOf<Quantity<ScalarType, DimensionType>> {
    using type = DimensionType;
  };
}  // namespace poids

#endif