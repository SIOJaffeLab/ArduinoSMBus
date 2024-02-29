#ifndef ArduinoSMBus_h
#define ArduinoSMBus_h

#include <Arduino.h>
#include <Wire.h>

#define VOLTAGE 0x09
#define TEMPERATURE 0x08
#define CURRENT 0x0a
#define CAPACITY 0x10
#define TIME_TO_FULL 0x13
#define CHARGE 0x0d
#define TIME_TO_EMPTY 0x12
#define STATUS 0x16
#define CYCLE_COUNT 0x17
#define DESIGN_CAPACITY 0x18
#define DESIGN_VOLTAGE 0x19
#define MANUFACTURE_DATE 0x1b
#define SERIAL_NUMBER 0x1c
#define DEVICE_NAME 0x21
#define DEVICE_CHEMISTRY 0x22
#define MANUFACTURER_NAME 0x20
#define MANUFACTURER_DATA 0x23
#define MANUFACTURER_INFO 0x25

class ArduinoSMBus {
public:
  ArduinoSMBus(uint8_t batteryAddress);
  uint16_t voltage();
  uint16_t temperature();
  uint16_t current();
  uint16_t capacity();
  uint16_t timeToFull();
  uint16_t charge();
  uint16_t timeToEmpty();
  uint16_t status();
  uint16_t cycleCount();
  uint16_t designCapacity();
  uint16_t designVoltage();
  uint16_t manufactureDate();
  uint16_t serialNumber();
  uint16_t deviceName();
  uint16_t deviceChemistry();
  uint16_t manufacturerName();
  uint16_t manufacturerData();
  uint16_t manufacturerInfo();

private:
  uint8_t _batteryAddress;
  uint16_t readRegister(uint8_t reg);
};

#endif