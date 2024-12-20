# POIDS

Poids is a physical quantities and units library for C++17.

## Usage

### Getting Started

Basic functionality from poids can be accessed with a single header. This header provides units in mass, length, and time. The library provides convenient types to create physical quantites with units, which looks similar to how the quantities would be written out by hand. The library checks and enforces units at compile-time.

``` C++
#include <iostream>

#include "poids/kgms.hpp"

using namespace kgms::base; // For base units

int main() {
    kgms::Velocity speed = 3 * meter / second;
    kgms::Time duration = 4 * second;

    kgms::Length distance = speed * duration;   // Units are checked at compile-time

    std::cout << "Traveled " << distance.as(milli(meter)) << " mm"; // "Travelled 12000.000 mm 

    return 0;
}

```

Quantities internally know their units and can perform unit conversions with the `as` member function, which returns a double of the quantity in the given units. 

### Concepts

Poids is built on top of the `Quantity`, which is a combination of a `Scalar` and `Unit`. The `Scalar` is the underlying value type, such as `double`. The `Unit` is a compile-time value carrying unit information, and units are not carried over to runtime, giving quantities very little overhead compared to just using the `Scalar` directly, while providing the benefit of checking units automatically. 

Quantities are extensible in both `Scalar` and `Unit`, and it is possible to write a custom version of each if those provided in the library are not sufficient. 

### Other Scalars

Out-of-the-box, poids supports scalar types `double`, `std::complex<double>` and `Eigen::Vector<double, N>`. 

### Custom Unit Systems
