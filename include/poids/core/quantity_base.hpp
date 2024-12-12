#ifndef POIDS_CORE_QUANTITY_BASE_HPP
#define POIDS_CORE_QUANTITY_BASE_HPP

#include "traits.hpp"

/** Mixin classes to provide extra functionality to Quantity and BaseQuantity*/
namespace poids::detail {
  template <typename Derived, bool IsBase>
  class QuantityMixin {
   public:
   protected:
    /** Only children can directly access this class*/
    QuantityMixin() = default;
    QuantityMixin(const QuantityMixin&) = default;
    QuantityMixin& operator=(const QuantityMixin&) = default;
    QuantityMixin(QuantityMixin&&) = default;
    QuantityMixin& operator=(QuantityMixin&&) = default;
    ~QuantityMixin() = default;

   private:
    Derived* derived() { return static_cast<Derived*>(this); }
    const Derived* derived() const { return static_cast<const Derived*>(this); }
  };

  template <typename Derived>
  class QuantityMixin<Derived, true> {
   public:
    /** Gets the value in the base units. */
    constexpr ScalarOf_t<Derived> value() const { return derived()->value_; }

   protected:
    /** Only children can directly access this class*/
    QuantityMixin() = default;
    QuantityMixin(const QuantityMixin&) = default;
    QuantityMixin& operator=(const QuantityMixin&) = default;
    QuantityMixin(QuantityMixin&&) = default;
    QuantityMixin& operator=(QuantityMixin&&) = default;
    ~QuantityMixin() = default;

   private:
    constexpr Derived* derived() { return static_cast<Derived*>(this); }
    constexpr const Derived* derived() const { return static_cast<const Derived*>(this); }
  };
}  // namespace poids::detail

#endif