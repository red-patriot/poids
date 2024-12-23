#ifndef POIDS_KGMS_UNIT_HPP
#define POIDS_KGMS_UNIT_HPP

#include <cstdint>
#include <type_traits>

#include "poids/core/traits.hpp"

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
    static_assert(poids::is_std_ratio<MassRatio>::value,
                  "MassRatio must be a specialization of std::ratio");
    static_assert(poids::is_std_ratio<LengthRatio>::value,
                  "LengthRatio must be a specialization of std::ratio");
    static_assert(poids::is_std_ratio<TimeRatio>::value,
                  "TimeRatio must be a specialization of std::ratio");

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
    /** The resultant units of the operation
     * kgms::UnitType * kgms::UnitType
     */
    template <typename Other>
    using multiply_t = typename MultiplyImpl<Other>::type;
    /** The resultant units of the operation
     * kgms::UnitType / kgms::UnitType
     */
    template <typename Other>
    using divide_t = typename DivideImpl<Other>::type;

    /** The resultant units of the operation
     * kgms::UnitType ** (N/D)
     */
    template <int N, unsigned D>
    using power_t = UnitType<std::ratio_multiply<mass, std::ratio<N, D>>,
                             std::ratio_multiply<length, std::ratio<N, D>>,
                             std::ratio_multiply<time, std::ratio<N, D>>>;

    /** The unitless units */
    using unitless_t = kgms::UnitType<std::ratio<0>, std::ratio<0>, std::ratio<0>>;
  };
}  // namespace kgms

#endif