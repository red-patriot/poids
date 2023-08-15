export module poid.util.rational;

import <numeric>;
import <stdexcept>;

namespace poid::util {
  export class Rational {
   public:
    constexpr Rational(std::intmax_t num) :
        numerator_(num),
        denominator_(1) { }
    constexpr Rational(std::intmax_t num, std::intmax_t denom) :
        numerator_(sign(denom) * num / std::gcd(num, denom)),
        denominator_(absConstexpr(denom) / std::gcd(num, denom)) {
      if (denom == 0) {
        throw std::exception("denom of eng::Rational cannot be zero");
      }
    }

    constexpr ~Rational() noexcept = default;

    const std::intmax_t numerator_;
    const std::intmax_t denominator_;

    friend bool operator==(const Rational&, const Rational&) = default;

   private:
    static constexpr std::intmax_t sign(std::intmax_t a) {
      return a < 0 ? -1 : 1;
    }
    static constexpr std::intmax_t absConstexpr(std::intmax_t a) {
      return a < 0 ? -a : a;
    }
  };
}  // namespace poid
