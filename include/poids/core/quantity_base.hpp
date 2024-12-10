#ifndef POIDS_CORE_QUANTITY_BASE_HPP
#define POIDS_CORE_QUANTITY_BASE_HPP

#include "traits.hpp"

namespace poids::detail {
  template <template <typename, typename> typename DerivedTemplate,
            typename ScalarType,
            typename UnitType>
  class QuantityBase {
    using Derived = DerivedTemplate<ScalarType, UnitType>;

   public:
    ScalarOf_t<Derived> base() { return derived()->value_; }
    const ScalarOf_t<Derived>& base() const { return derived()->value_; }

    bool operator==(const Derived& rhs) const {
      return derived()->value_ == rhs.value_;
    }

    bool operator!=(const Derived& rhs) const {
      return !derived()->operator==(rhs);
    }

    bool operator<(const Derived& rhs) const {
      return derived()->value_ < rhs.value_;
    }

    bool operator>(const Derived& rhs) const {
      return rhs.operator<(*derived());
    }
    bool operator<=(const Derived& rhs) const {
      return this->operator==(rhs) || this->operator<(rhs);
    }
    bool operator>=(const Derived& rhs) const {
      return this->operator==(rhs) || this->operator>(rhs);
    }

    Derived operator+(const Derived& rhs) const {
      return Derived{derived()->value_ + rhs.value_, typename Derived::InternalTag{}};
    }

    Derived operator-(const Derived& rhs) const {
      return Derived{derived()->value_ - rhs.value_, typename Derived::InternalTag{}};
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