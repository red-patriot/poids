#ifndef POIDS_CORE_QUANTITY_HPP
#define POIDS_CORE_QUANTITY_HPP

namespace poids {
  template <typename ScalarType,
            typename UnitType>
  class Quantity {
   public:
    using Scalar = ScalarType;
    using Unit = UnitType;

    const Scalar& base() const { return value_; }

    static Quantity<Scalar, Unit> makeBase(const Scalar& baseValue) {
      return Quantity<Scalar, Unit>(baseValue);
    }

   private:
    Scalar value_{};

    Quantity(const Scalar& baseValue) :
        value_{baseValue} { }
  };
}  // namespace poids

#endif