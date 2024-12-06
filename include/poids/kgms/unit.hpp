#ifndef POIDS_KGMS_UNIT_HPP
#define POIDS_KGMS_UNIT_HPP

namespace kgms {
  template <typename MassRatio,
            typename LengthRatio,
            typename TimeRatio>
  struct UnitType {
    using mass = MassRatio;
    using length = LengthRatio;
    using time = TimeRatio;

   private:
    template <typename Other>
    struct MultiplyImpl {
      using type = UnitType<std::ratio_add<mass,
                                           typename Other::mass>,
                            std::ratio_add<length,
                                           typename Other::length>,
                            std::ratio_add<time,
                                           typename Other::time>>;
    };

   public:
    template <typename Other>
    using multiply_t = typename MultiplyImpl<Other>::type;
  };
}  // namespace kgms

#endif