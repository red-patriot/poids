export module poid.unit;

export import poid.dimension;

namespace poid {
  export template <Dimension Dim>
  class Unit {
   public:
    static constexpr Dimension dimension = Dim;

    explicit constexpr Unit(double base = 0.0);

    inline constexpr double base() const noexcept { return base_; }

    inline constexpr auto operator<=>(const Unit<Dim>& rhs) const& noexcept = default;

   private:
    double base_;
  };

  template <Dimension Dim>
  constexpr Unit<Dim>::Unit(double base) :
      base_(base) { }

  export template <Dimension Dim>
  constexpr Unit<Dim> operator-(Unit<Dim> rhs) {
    return Unit<Dim>{-rhs.base()};
  }

  export template <Dimension Dim>
  constexpr Unit<Dim> operator+(Unit<Dim> lhs, Unit<Dim> rhs) {
    return Unit<Dim>(lhs.base() + rhs.base());
  }

  export template <Dimension Dim>
  constexpr Unit<Dim> operator-(Unit<Dim> lhs, Unit<Dim> rhs) {
    return Unit<Dim>(lhs.base() - rhs.base());
  }

  export template <Dimension DimL, Dimension DimR>
  constexpr auto operator*(Unit<DimL> lhs, Unit<DimR> rhs) {
    return Unit<DimL + DimR>(lhs.base() * rhs.base());
  }

  export template <Dimension DimL, Dimension DimR>
  constexpr auto operator/(Unit<DimL> lhs, Unit<DimR> rhs) {
    return Unit<DimL - DimR>(lhs.base() / rhs.base());
  }
}  // namespace poid
