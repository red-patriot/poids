export module poid.unit;

export import poid.dimension;

namespace poid {
  export template <Dimension Dim>
  class Unit {
   public:
    explicit constexpr Unit(double base = 0.0);

    constexpr double base() const noexcept { return base_; }

    inline constexpr auto operator<=>(const Unit<Dim>& rhs) const& noexcept = default;

   private:
    double base_;
  };

  template <Dimension Dim>
  constexpr Unit<Dim>::Unit(double base) :
      base_(base) { }
}  // namespace poid
