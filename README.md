# ArduinoSMBus Library

The ArduinoSMBus library is a simple and easy-to-use Arduino library for accessing and reading data from Smart Battery devices over the SMBus (System Management Bus). It provides a set of functions to read various registers from a Smart Battery, including voltage, temperature, current, capacity, and manufacturer information.

## Documentation
In general, this library works by creating an ArduinoSMBus class, which then has various public methods to read status information from the smart battery. These methods utilize two private methods, readRegister() and readBlock() which communicate with the smart battery BMS via I2C/SMBus and return the appropriate data. The following parameters (with their SMBus commands in parentheses) are accessible via this library:

- VOLTAGE 0x09
- TEMPERATURE 0x08
- CURRENT 0x0a
- CAPACITY 0x10
- TIME_TO_FULL 0x13
- STATE_OF_CHARGE 0x0d
- SOC_ERROR 0x0c
- TIME_TO_EMPTY 0x12
- STATUS 0x16
- CYCLE_COUNT 0x17
- STATE_OF_HEALTH 0x4f
- DESIGN_CAPACITY 0x18
- DESIGN_VOLTAGE 0x19
- MANUFACTURE_DATE 0x1b
- SERIAL_NUMBER 0x1c
- DEVICE_NAME 0x21
- DEVICE_CHEMISTRY 0x22
- MANUFACTURER_NAME 0x20
- MANUFACTURER_DATA 0x23
- MANUFACTURER_INFO 0x25

A detailed description of all of these parameters/commands can be found in the [Smart Battery Data Specification](https://duluthmachineworks.github.io/ArduinoSMBus/docs/datasheets/sbdat110.pdf).
At this time, this library is only capable of reading registers from the BMS, and not capable of writing them. With some additional work, writing to the BMS should be possible.
Full documentation of this library can be found via doxygen [here.](https://duluthmachineworks.github.io/ArduinoSMBus/docs/)

## Usage

To use the library, include the `ArduinoSMBus.h` file in your sketch and create an instance of the `ArduinoSMBus` class with the I2C address of your battery as an argument. You can then call the various methods of the class to read data from the battery. An example which prints all available parameters to serial is included in the examples directory.

The default I2C addresses for most SMBus-compatible BMS is 0x16, which is what is used in the examples. If this doesn't work for your battery, run a I2C scanner sketch to identify the BMS address before attempting to use the library.

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
