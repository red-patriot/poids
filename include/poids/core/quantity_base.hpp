#ifndef POIDS_CORE_QUANTITY_BASE_HPP
#define POIDS_CORE_QUANTITY_BASE_HPP

#include "traits.hpp"

namespace poids::detail {
  template <typename Derived, bool IsBase>
  class QuantityBase {
   public:
   protected:
    /** Only children can directly access this class*/
    QuantityBase() = default;
    QuantityBase(const QuantityBase&) = default;
    QuantityBase& operator=(const QuantityBase&) = default;
    QuantityBase(QuantityBase&&) = default;
    QuantityBase& operator=(QuantityBase&&) = default;
    ~QuantityBase() = default;

   private:
    Derived* derived() { return static_cast<Derived*>(this); }
    const Derived* derived() const { return static_cast<const Derived*>(this); }
  };

  template <typename Derived>
  class QuantityBase<Derived, true> {
   public:
    /** Gets the value in the base units. */
    constexpr ScalarOf_t<Derived> value() const { return derived()->value_; }

   protected:
    /** Only children can directly access this class*/
    QuantityBase() = default;
    QuantityBase(const QuantityBase&) = default;
    QuantityBase& operator=(const QuantityBase&) = default;
    QuantityBase(QuantityBase&&) = default;
    QuantityBase& operator=(QuantityBase&&) = default;
    ~QuantityBase() = default;

   private:
    constexpr Derived* derived() { return static_cast<Derived*>(this); }
    constexpr const Derived* derived() const { return static_cast<const Derived*>(this); }
  };
}  // namespace poids::detail

#endif