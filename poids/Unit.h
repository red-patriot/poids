#ifndef POIDS_UNITS_UNIT_H
#define POIDS_UNITS_UNIT_H

#include "Dimension.h"
// TODO: Remove this inclusion
#include "metric/SIDimension.h"

namespace poids {
  namespace util {
    template <auto Dim>
    class UnitBase { };
  }  // namespace util

  template <auto Dim>
  class Unit : public util::UnitBase<Dim> {
   public:
    using DimensionType = decltype(Dim);
    static constexpr auto dimension = Dim;

    explicit constexpr Unit(double base = 0.0);

    inline constexpr double base() const noexcept { return base_; }
    inline constexpr double as(Unit a) const noexcept { return base_ / a.base_; }

    inline constexpr auto operator==(const Unit<Dim>& rhs) const noexcept { return base_ == rhs.base_; }
    inline constexpr auto operator<=>(const Unit<Dim>& rhs) const noexcept { return base_ <=> rhs.base_; }

   private:
    double base_;
  };

  template <auto Dim>
  constexpr Unit<Dim>::Unit(double base) :
      base_(base) { }

  template <auto Dim>
  constexpr Unit<Dim> operator-(Unit<Dim> rhs) {
    return Unit<Dim>{-rhs.base()};
  }

  template <auto Dim>
  constexpr Unit<Dim> operator+(Unit<Dim> lhs, Unit<Dim> rhs) {
    return Unit<Dim>(lhs.base() + rhs.base());
  }

  template <auto Dim>
  constexpr Unit<Dim> operator-(Unit<Dim> lhs, Unit<Dim> rhs) {
    return Unit<Dim>(lhs.base() - rhs.base());
  }

  template <auto DimL, auto DimR>
  constexpr auto operator*(Unit<DimL> lhs, Unit<DimR> rhs) {
    return Unit<DimL + DimR>(lhs.base() * rhs.base());
  }

  template <auto Dim>
  constexpr Unit<Dim> operator*(Unit<Dim> lhs, double rhs) {
    return Unit<Dim>(lhs.base() * rhs);
  }

  template <auto Dim>
  constexpr Unit<Dim> operator*(double lhs, Unit<Dim> rhs) {
    return rhs * lhs;
  }

  template <auto DimL, auto DimR>
  constexpr auto operator/(Unit<DimL> lhs, Unit<DimR> rhs) {
    return Unit<DimL - DimR>(lhs.base() / rhs.base());
  }

  template <auto Dim>
  constexpr Unit<Dim> operator/(Unit<Dim> lhs, double rhs) {
    return Unit<Dim>(lhs.base() / rhs);
  }

  template <auto Dim>
  constexpr auto operator/(double lhs, Unit<Dim> rhs) {
    return Unit<-Dim>(lhs / rhs.base());
  }
}  // namespace poids

#endif
