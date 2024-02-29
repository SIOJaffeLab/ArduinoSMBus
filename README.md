# ArduinoSMBus Library

The ArduinoSMBus library is a simple and easy-to-use Arduino library for accessing and reading data from Smart Battery devices over the SMBus (System Management Bus). It provides a set of functions to read various registers from a Smart Battery, including voltage, temperature, current, capacity, and manufacturer information.

## Usage

To use the library, include the `ArduinoSMBus.h` file in your sketch and create an instance of the `ArduinoSMBus` class with the I2C address of your battery as an argument. You can then call the various methods of the class to read data from the battery.

```cpp
#include "ArduinoSMBus.h"

ArduinoSMBus battery(0x0B); // replace with your battery's I2C address

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print("Voltage: ");
  Serial.println(battery.voltage());
  // ... and so on for the other methods
}
```

## Prior Art
This library is based on the work done by Ri5ux in the [Smart-Battery-SMBUS-Analyzer](https://github.com/Ri5ux/Smart-Battery-SMBUS-Analyzer) project. The ArduinoSMBus library simplifies the code and makes it easier to use in your own Arduino projects.

## License
This project is licensed under the MIT License - see the LICENSE file for details.