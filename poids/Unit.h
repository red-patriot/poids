#ifndef POIDS_UNITS_UNIT_H
#define POIDS_UNITS_UNIT_H

#include "Dimension.h"

namespace poids {
  namespace util {
    template <Dimension Dim>
    class UnitBase { };
  }  // namespace util

  template <Dimension Dim>
  class Unit : public util::UnitBase<Dim> {
   public:
    static constexpr Dimension dimension = Dim;

    explicit constexpr Unit(double base = 0.0);

    inline constexpr double base() const noexcept { return base_; }
    inline constexpr double as(Unit a) const noexcept { return base_ / a.base_; }

    inline constexpr auto operator==(const Unit<Dim>& rhs) const noexcept { return base_ == rhs.base_; }
    inline constexpr auto operator<=>(const Unit<Dim>& rhs) const noexcept { return base_ <=> rhs.base_; }

   private:
    double base_;
  };

  template <Dimension Dim>
  constexpr Unit<Dim>::Unit(double base) :
      base_(base) { }

  template <Dimension Dim>
  constexpr Unit<Dim> operator-(Unit<Dim> rhs) {
    return Unit<Dim>{-rhs.base()};
  }

  template <Dimension Dim>
  constexpr Unit<Dim> operator+(Unit<Dim> lhs, Unit<Dim> rhs) {
    return Unit<Dim>(lhs.base() + rhs.base());
  }

  template <Dimension Dim>
  constexpr Unit<Dim> operator-(Unit<Dim> lhs, Unit<Dim> rhs) {
    return Unit<Dim>(lhs.base() - rhs.base());
  }

  template <Dimension DimL, Dimension DimR>
  constexpr auto operator*(Unit<DimL> lhs, Unit<DimR> rhs) {
    return Unit<DimL + DimR>(lhs.base() * rhs.base());
  }

  template <Dimension Dim>
  constexpr Unit<Dim> operator*(Unit<Dim> lhs, double rhs) {
    return Unit<Dim>(lhs.base() * rhs);
  }

  template <Dimension Dim>
  constexpr Unit<Dim> operator*(double lhs, Unit<Dim> rhs) {
    return rhs * lhs;
  }

  template <Dimension DimL, Dimension DimR>
  constexpr auto operator/(Unit<DimL> lhs, Unit<DimR> rhs) {
    return Unit<DimL - DimR>(lhs.base() / rhs.base());
  }

  template <Dimension Dim>
  constexpr Unit<Dim> operator/(Unit<Dim> lhs, double rhs) {
    return Unit<Dim>(lhs.base() / rhs);
  }

  template <Dimension Dim>
  constexpr auto operator/(double lhs, Unit<Dim> rhs) {
    return Unit<TimeD(0) - Dim>(lhs / rhs.base());
  }

  namespace util {
    template <>
        class UnitBase <Dimensionless()> {
     public:
       // Enable dimensionless Units to be implicitly convertable to double
      operator double() const { return static_cast<const Unit<Dimensionless()>*>(this)->base(); }
    };
  }  // namespace util
}  // namespace poids

#endif  // !1
