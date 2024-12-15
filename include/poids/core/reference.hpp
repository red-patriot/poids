#ifndef POIDS_CORE_REFERENCE_HPP
#define POIDS_CORE_REFERENCE_HPP

#include "quantity.hpp"

namespace poids {
  template <typename ScalarType,
            typename UnitType>
  class ReferenceQuantity {
    struct InternalTag { };

   public:
    /** The scalar type of this Quantity */
    using Scalar = ScalarOf_t<ReferenceQuantity<ScalarType, UnitType>>;
    using Reference = std::add_lvalue_reference_t<Scalar>;
    /** The unit type of this Quantity */
    using Unit = UnitOf_t<ReferenceQuantity<ScalarType, UnitType>>;
    /** Identity of this ReferenceQuantity */
    using Type = ReferenceQuantity<Scalar, Unit>;

    /*implicit*/ ReferenceQuantity(Quantity<Scalar, Unit>& quantity) :
        reference_(quantity.value_) { }

    template <bool IsBase>
    Type& operator=(const Quantity<Scalar, Unit, IsBase>& quantity) {
      reference_ = quantity.value_;
      return *this;
    }

    explicit operator Quantity<Scalar, Unit>() const {
      return Quantity<Scalar, Unit>::makeFromBaseUnitValue(reference_);
    }

    Scalar as(const BaseQuantity<Scalar, Unit>& desired) {
      return reference_ / desired.value();
    }

    const Reference base() const { return reference_; }

    static Type makeReference(Reference baseValue) {
      return ReferenceQuantity(baseValue, InternalTag{});
    }

   private:
    Reference reference_;

    ReferenceQuantity(Reference reference, InternalTag) :
        reference_(reference) { }
  };

  template <typename ScalarType, typename UnitType>
  struct ScalarOf<ReferenceQuantity<ScalarType, UnitType>> {
    using type = ScalarType;
  };

  template <typename ScalarType, typename UnitType>
  struct UnitOf<ReferenceQuantity<ScalarType, UnitType>> {
    using type = UnitType;
  };

  template <typename ScalarType, typename UnitType>
  struct IsQuantity<ReferenceQuantity<ScalarType, UnitType>> : public std::true_type { };

}  // namespace poids

#endif