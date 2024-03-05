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

//Usable Commands
#define TEMPERATURE 0x08
#define VOLTAGE 0x09
#define CURRENT 0x0a
#define AVERAGE_CURRENT 0x0b
#define MAX_ERROR 0x0c
#define REL_STATE_OF_CHARGE 0x0d
#define ABS_STATE_OF_CHARGE 0x0e
#define REM_CAPACITY 0x0f
#define FULL_CAPACITY 0x10
#define RUN_TIME_TO_EMPTY 0x11
#define AVG_TIME_TO_EMPTY 0x12
#define AVG_TIME_TO_FULL 0x13
#define BATTERY_STATUS 0x16
#define CHARGING_CURRENT 0x14
#define CHARGING_VOLTAGE 0x15
#define CYCLE_COUNT 0x17
#define DESIGN_CAPACITY 0x18
#define DESIGN_VOLTAGE 0x19
#define MANUFACTURE_DATE 0x1b
#define SERIAL_NUMBER 0x1c
#define MANUFACTURER_NAME 0x20
#define DEVICE_NAME 0x21
#define DEVICE_CHEMISTRY 0x22
#define STATE_OF_HEALTH 0x4f

class ArduinoSMBus {
public:
  ArduinoSMBus(uint8_t batteryAddress);
  void setBatteryAddress(uint8_t batteryAddress);

  uint16_t temperature();
  uint16_t temperatureC();
  uint16_t temperatureF();
  uint16_t voltage();
  uint16_t current();
  uint16_t averageCurrent();
  uint16_t maxError();
  uint16_t relativeStateOfCharge();
  uint16_t absoluteStateOfCharge();
  uint16_t remainingCapacity();
  uint16_t fullCapacity();
  uint16_t runTimeToEmpty();
  uint16_t avgTimeToEmpty();
  uint16_t avgTimeToFull();
  uint16_t batteryStatus();
  uint16_t chargingCurrent();
  uint16_t chargingVoltage();
  bool statusOK();
  bool isCharging();
  bool isFullyCharged();
  uint16_t cycleCount();
  uint16_t designCapacity();
  uint16_t designVoltage();
  uint16_t manufactureDate();
  int manufactureYear();
  uint16_t serialNumber();
  const char* manufacturerName();
  const char* deviceName();
  const char* deviceChemistry();
  uint16_t stateOfHealth();

private:
  uint8_t _batteryAddress;
  uint16_t readRegister(uint8_t reg);
  void readBlock(uint8_t reg, uint8_t* data, uint8_t len);
};

#endif