/**
 * @file ArduinoSMBus.h
 * @author Christopher Lee (clee@unitedconsulting.com)
 * @brief Function declarations for the ArduinoSMBus class.
 * @version 1.0
 * @date 2024-02-29
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef ArduinoSMBus_h
#define ArduinoSMBus_h

#include <Arduino.h>
#include <Wire.h>

#define VOLTAGE 0x09
#define TEMPERATURE 0x08
#define CURRENT 0x0a
#define CAPACITY 0x10
#define TIME_TO_FULL 0x13
#define STATE_OF_CHARGE 0x0d
#define SOC_ERROR 0x0c
#define TIME_TO_EMPTY 0x12
#define STATUS 0x16
#define CYCLE_COUNT 0x17
#define STATE_OF_HEALTH 0x4f
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
  uint16_t temperatureC();
  uint16_t temperatureF();
  uint16_t current();
  uint16_t capacity();
  uint16_t timeToFull();
  uint16_t stateofCharge();
  uint16_t SOCError();
  uint16_t timeToEmpty();
  uint16_t status();
  bool statusOK();
  bool isCharging();
  bool isFullyCharged();
  uint16_t cycleCount();
  uint16_t stateOfHealth();
  uint16_t designCapacity();
  uint16_t designVoltage();
  uint16_t manufactureDate();
  int manufactureYear();
  uint16_t serialNumber();
  const char* deviceName();
  const char* deviceChemistry();
  const char* manufacturerName();


private:
  uint8_t _batteryAddress;
  uint16_t readRegister(uint8_t reg);
  void readBlock(uint8_t reg, uint8_t* data, uint8_t len);
};

#endif