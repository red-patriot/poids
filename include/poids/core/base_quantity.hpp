#ifndef POIDS_CORE_BASE_QUANTITY_HPP
#define POIDS_CORE_BASE_QUANTITY_HPP

#include "traits.hpp"
#include "quantity_base.hpp"

namespace poids {
  template <typename ScalarType,
            typename UnitType>
  class BaseQuantity : public detail::QuantityBase<BaseQuantity<ScalarType, UnitType>> {
    friend detail::QuantityBase<BaseQuantity<ScalarType, UnitType>>;
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

    static Type makeBase(const Scalar& baseValue) {
      return Type(baseValue, InternalTag{});
    }

   private:
    Scalar value_{};

    BaseQuantity(const Scalar& baseValue, InternalTag) :
        value_{baseValue} { }
  };

  /** If a quantity is tested for being dimensionless, forward the request to its DimensionType*/
  template <typename Scalar, typename DimensionType>
  struct IsUnitless<BaseQuantity<Scalar, DimensionType>> : public IsUnitless<DimensionType> { };

  template <typename ScalarType, typename DimensionType>
  struct ScalarOf<BaseQuantity<ScalarType, DimensionType>> {
    using type = ScalarType;
  };

  template <typename ScalarType, typename DimensionType>
  struct UnitOf<BaseQuantity<ScalarType, DimensionType>> {
    using type = DimensionType;
  };
}  // namespace poids

#endif