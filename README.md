# Poids

Poids is a header-only library to manage physical units written in C++ 20. It performs all unit management 
at compile time, so the runtime cost is no more than using doubles. The library is designed to be 
extensible and allows users to implement custom unit types to fit their individual needs.

## Getting Started
All of poids can be accessed using a single header: `Poids.h`. Any units which can be created in the 
SI(metric) system are supported out of the box, and easy to use literals are provided for convenience.
Literals can be combined using normal arithmetic to create new unit types.

```
#include "Poids.h"

// Do this to simplify the example below
using poids::metric::second;
using poids::metric::meter;

poids::metric::Time time = 3 * second;
poids::metric::Length distance = 4.75 * meter;

auto velocity = distance / time;    // Automatically has the correct units of meters/second
```

Additionally, the compiler will prevent the user from accidentally combining the wrong types.

```

poids::metric::Time time = 3 * second;
poids::metric::Length distance = 4.75 * meter;

auto bad_value = time + distance;   // Compile error: units don't match
```

To get the value of any unit, the `as` member function performs calculations and conversions between
compatible values.
```
poids::metric::Length distance = 300 * meter;

distance.as(poids::metric::kilo(meter));    // returns 0.3
distance.as(poids::metric::milli(meter));   // returns 300,000

```


