#ifndef POIDS_KGMS_UNIT_HPP
#define POIDS_KGMS_UNIT_HPP

namespace kgms {
  /**
   * A Unit in the KGMS system
   *
   * \tparam MassRatio The quantity of the kilograms unit dimension
   * \tparam LengthRatio The quantity of the meters unit dimension
   * \tparam TimeRatio The quantity of the seconds unit dimension
   */
  template <typename MassRatio,
            typename LengthRatio,
            typename TimeRatio>
  struct UnitType {
    using mass = MassRatio;     /**< The quantity of mass units*/
    using length = LengthRatio; /**< The quantity of length units*/
    using time = TimeRatio;     /**< The quantity of time units*/

   private:
    /** Implements multiplying this UnitType with another*/
    template <typename Other>
    struct MultiplyImpl {
      using type = UnitType<std::ratio_add<mass,
                                           typename Other::mass>,
                            std::ratio_add<length,
                                           typename Other::length>,
                            std::ratio_add<time,
                                           typename Other::time>>;
    };

    /** Implements dividing this UnitType with another*/
    template <typename Other>
    struct DivideImpl {
      using type = UnitType<std::ratio_subtract<mass,
                                                typename Other::mass>,
                            std::ratio_subtract<length,
                                                typename Other::length>,
                            std::ratio_subtract<time,
                                                typename Other::time>>;
    };

   public:
    template <typename Other>
    using multiply_t = typename MultiplyImpl<Other>::type;
    template <typename Other>
    using divide_t = typename DivideImpl<Other>::type;
  };
}  // namespace kgms

#endif