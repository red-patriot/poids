#ifndef POIDS_CORE_BASE_QUANTITY_HPP
#define POIDS_CORE_BASE_QUANTITY_HPP

#include "traits.hpp"
#include "quantity_base.hpp"

namespace poids {
  template <typename ScalarType,
            typename UnitType>
  class BaseQuantity;

  template <typename ScalarType, typename UnitType>
  BaseQuantity<ScalarType, UnitType> makeBase(const ScalarType& scalar);

  template <typename ScalarType,
            typename UnitType>
  class BaseQuantity : public detail::QuantityBase<BaseQuantity<ScalarType, UnitType>> {
    friend detail::QuantityBase<BaseQuantity<ScalarType, UnitType>>;
    friend BaseQuantity<ScalarType, UnitType> makeBase<ScalarType, UnitType>(const ScalarType& scalar);
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

   private:
    Scalar value_{};

    BaseQuantity(const Scalar& baseValue, InternalTag) :
        value_{baseValue} { }
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