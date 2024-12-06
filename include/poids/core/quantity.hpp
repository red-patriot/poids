#ifndef POIDS_CORE_QUANTITY_HPP
#define POIDS_CORE_QUANTITY_HPP

#include "traits.hpp"

namespace poids {
  template <typename ScalarType,
            typename UnitType>
  class Quantity {
   public:
    using Scalar = ScalarType;
    using Unit = UnitType;
    using ThisType = Quantity<Scalar, Unit>;

    const Scalar& base() const { return value_; }

    static ThisType makeBase(const Scalar& baseValue) {
      return ThisType(baseValue);
    }

    bool operator==(const ThisType& other) const {
      return this->value_ == other.value_;
    }

    bool operator!=(const ThisType& other) const {
      return !this->operator==(other);
    }

    bool operator<(const ThisType& other) const {
      return this->value_ < other.value_;
    }

    bool operator>(const ThisType& other) const {
      return other.operator<(*this);
    }
    bool operator<=(const ThisType& other) const {
      return this->operator==(other) || this->operator<(other);
    }
    bool operator>=(const ThisType& other) const {
      return this->operator==(other) || this->operator>(other);
    }

   private:
    Scalar value_{};

    Quantity(const Scalar& baseValue) :
        value_{baseValue} { }
  };

  /** If a quantity is tested for being dimensionless, forward the request to its DimensionType*/
  template <typename Scalar, typename DimensionType>
  struct IsUnitless<Quantity<Scalar, DimensionType>> : public IsUnitless<DimensionType> { };
}  // namespace poids

#endif