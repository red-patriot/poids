#ifndef POIDS_CORE_REFERENCE_HPP
#define POIDS_CORE_REFERENCE_HPP

#include "quantity.hpp"

namespace poids {
  template <typename ScalarType,
            typename UnitType>
  class ReferenceQuantity {
    struct InternalTag { };

    static_assert(!std::is_reference_v<ScalarType>, "Quantity requires a non-reference ScalarType");
    static_assert(IsValidUnit_v<UnitType>, "The given UnitType is not a valid unit");

   public:
    /** The scalar type of this Quantity */
    using Scalar = ScalarOf_t<ReferenceQuantity<ScalarType, UnitType>>;
    using Reference = std::add_lvalue_reference_t<Scalar>;
    using ConstReference = std::add_const_t<Reference>;

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

    ReferenceQuantity(const ReferenceQuantity<Scalar, Unit>& other) :
        reference_{other.reference_} { }

    Type& operator=(const ReferenceQuantity<Scalar, Unit>& other) {
      reference_ = other.reference_;
      return *this;
    }

    // ReferenceQuantity(Type&&) = copy;
    // ReferenceQuantity& operator=(Type&&) = copy;

    ~ReferenceQuantity() = default;

    /*implicit*/ operator Quantity<Scalar, Unit>() const {
      return Quantity<Scalar, Unit>::makeFromBaseUnitValue(reference_);
    }

    Scalar as(const BaseQuantity<Scalar, Unit>& desired) {
      return reference_ / desired.value();
    }

    ConstReference base() const { return reference_; }

    static Type makeReference(Reference baseValue) {
      return ReferenceQuantity(baseValue, InternalTag{});
    }

   private:
    Reference reference_;

    ReferenceQuantity(Reference reference, InternalTag) :
        reference_(reference) { }

    friend bool operator==(Type lhs, Type rhs) { return lhs.base() == rhs.base(); }
    template <bool IsBase>
    friend bool operator==(Type lhs, const Quantity<Scalar, Unit, IsBase>& rhs) { return lhs.base() == rhs.base(); }
    template <bool IsBase>
    friend bool operator==(const Quantity<Scalar, Unit, IsBase>& lhs, Type rhs) { return lhs.base() == rhs.base(); }

    friend bool operator!=(Type lhs, Type rhs) { return !(lhs == rhs); }
    template <bool IsBase>
    friend bool operator!=(Type lhs, const Quantity<Scalar, Unit, IsBase>& rhs) { return !(lhs == rhs); }
    template <bool IsBase>
    friend bool operator!=(const Quantity<Scalar, Unit, IsBase>& lhs, Type rhs) { return !(lhs == rhs); }

    friend bool operator<(Type lhs, Type rhs) { return lhs.base() < rhs.base(); }
    template <bool IsBase>
    friend bool operator<(Type lhs, const Quantity<Scalar, Unit, IsBase>& rhs) { return lhs.base() < rhs.base(); }
    template <bool IsBase>
    friend bool operator<(const Quantity<Scalar, Unit, IsBase>& lhs, Type rhs) { return lhs.base() < rhs.base(); }

    friend bool operator>(Type lhs, Type rhs) { return rhs.base() < lhs.base(); }
    template <bool IsBase>
    friend bool operator>(Type lhs, const Quantity<Scalar, Unit, IsBase>& rhs) { return rhs.base() < lhs.base(); }
    template <bool IsBase>
    friend bool operator>(const Quantity<Scalar, Unit, IsBase>& lhs, Type rhs) { return rhs.base() < lhs.base(); }

    friend bool operator<=(Type lhs, Type rhs) { return lhs < rhs || lhs == rhs; }
    template <bool IsBase>
    friend bool operator<=(Type lhs, const Quantity<Scalar, Unit, IsBase>& rhs) { return lhs < rhs || lhs == rhs; }
    template <bool IsBase>
    friend bool operator<=(const Quantity<Scalar, Unit, IsBase>& lhs, Type rhs) { return lhs < rhs || lhs == rhs; }

    friend bool operator>=(Type lhs, Type rhs) { return rhs < lhs || rhs == lhs; }
    template <bool IsBase>
    friend bool operator>=(Type lhs, const Quantity<Scalar, Unit, IsBase>& rhs) { return rhs < lhs || rhs == lhs; }
    template <bool IsBase>
    friend bool operator>=(const Quantity<Scalar, Unit, IsBase>& lhs, Type rhs) { return rhs < lhs || rhs == lhs; }

    friend Quantity<Scalar, Unit> operator+(Type lhs, Type rhs) {
      return Quantity<Scalar, Unit>::makeFromBaseUnitValue(lhs.base() + rhs.base());
    }
    template <bool IsBase>
    friend Quantity<Scalar, Unit> operator+(Type lhs, const Quantity<Scalar, Unit, IsBase>& rhs) {
      return Quantity<Scalar, Unit>::makeFromBaseUnitValue(lhs.base() + rhs.base());
    }
    template <bool IsBase>
    friend Quantity<Scalar, Unit> operator+(const Quantity<Scalar, Unit, IsBase>& lhs, Type rhs) {
      return Quantity<Scalar, Unit>::makeFromBaseUnitValue(lhs.base() + rhs.base());
    }

    friend Quantity<Scalar, Unit> operator-(Type lhs, Type rhs) {
      return Quantity<Scalar, Unit>::makeFromBaseUnitValue(lhs.base() - rhs.base());
    }
    template <bool IsBase>
    friend Quantity<Scalar, Unit> operator-(Type lhs, const Quantity<Scalar, Unit, IsBase>& rhs) {
      return Quantity<Scalar, Unit>::makeFromBaseUnitValue(lhs.base() - rhs.base());
    }
    template <bool IsBase>
    friend Quantity<Scalar, Unit> operator-(const Quantity<Scalar, Unit, IsBase>& lhs, Type rhs) {
      return Quantity<Scalar, Unit>::makeFromBaseUnitValue(lhs.base() - rhs.base());
    }
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

  template <typename ScalarType, typename UnitType>
  ReferenceQuantity(Quantity<ScalarType, UnitType>) -> ReferenceQuantity<ScalarType, UnitType>;

}  // namespace poids

#endif