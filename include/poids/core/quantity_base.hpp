#ifndef POIDS_CORE_QUANTITY_BASE_HPP
#define POIDS_CORE_QUANTITY_BASE_HPP

#include "traits.hpp"

namespace poids::detail {
  template <typename Derived>
  class QuantityBase {
   public:
    ScalarOf_t<Derived> base() { return derived()->value_; }
    const ScalarOf_t<Derived>& base() const { return derived()->value_; }

    bool operator==(const Derived& other) const {
      return derived()->value_ == other.value_;
    }

    bool operator!=(const Derived& other) const {
      return !derived()->operator==(other);
    }

    bool operator<(const Derived& other) const {
      return derived()->value_ < other.value_;
    }

    bool operator>(const Derived& other) const {
      return other.operator<(*derived());
    }
    bool operator<=(const Derived& other) const {
      return this->operator==(other) || this->operator<(other);
    }
    bool operator>=(const Derived& other) const {
      return this->operator==(other) || this->operator>(other);
    }

    Derived operator+(const Derived& other) const {
      return Derived{derived()->value_ + other.value_, typename Derived::InternalTag{}};
    }

    Derived operator-(const Derived& other) const {
      return Derived{derived()->value_ - other.value_, typename Derived::InternalTag{}};
    }

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
}  // namespace poids::detail

#endif