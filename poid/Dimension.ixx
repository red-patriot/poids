export module poid.util.dimension;

import poid.util.rational;

namespace poid::util {
  export class Dimension {
   public:
    const util::Rational time;
    const util::Rational mass;
    const util::Rational length;
    const util::Rational temperature;
    const util::Rational current;
    const util::Rational amount;
    const util::Rational luminosity;

    constexpr ~Dimension() = default;

    friend consteval Dimension TimeD(const Rational& time);
    friend consteval Dimension MassD(const Rational& mass);
    friend consteval Dimension LengthD(const Rational& length);
    friend consteval Dimension TemperatureD(const Rational& temperature);
    friend consteval Dimension CurrentD(const Rational& current);
    friend consteval Dimension AmountD(const Rational& amount);
    friend consteval Dimension LuminosityD(const Rational& luminosity);

   private:
    constexpr Dimension(Rational timeD = Rational(0),
                        Rational massD = Rational(0),
                        Rational lengthD = Rational(0),
                        Rational temperatureD = Rational(0),
                        Rational currentD = Rational(0),
                        Rational amountD = Rational(0),
                        Rational luminosityD = Rational(0));
  };

  constexpr Dimension::Dimension(Rational timeD,
                                 Rational massD,
                                 Rational lengthD,
                                 Rational temperatureD,
                                 Rational currentD,
                                 Rational amountD,
                                 Rational luminosityD) :
      time(timeD),
      mass(massD),
      length(lengthD),
      temperature(temperatureD),
      current(currentD),
      amount(amountD),
      luminosity(luminosityD) { }

  export consteval Dimension TimeD(const Rational& time) {
    return Dimension(time);
  }
  export consteval Dimension MassD(const Rational& mass) {
    return Dimension({0}, mass);
  }
  export consteval Dimension LengthD(const Rational& length) {
    return Dimension({0}, {0}, length);
  }
  export consteval Dimension TemperatureD(const Rational& temperature) {
    return Dimension({0}, {0}, {0}, temperature);
  }
  export consteval Dimension CurrentD(const Rational& current) {
    return Dimension({0}, {0}, {0}, {0}, current);
  }
  export consteval Dimension AmountD(const Rational& amount) {
    return Dimension({0}, {0}, {0}, {0}, {0}, amount);
  }
  export consteval Dimension LuminosityD(const Rational& luminosity) {
    return Dimension({0}, {0}, {0}, {0}, {0}, {0}, luminosity);
  }
}  // namespace poid::util
