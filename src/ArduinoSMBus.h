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
#define MANUFACTURER_ACCESS 0x00
#define REMAINING_CAPACITY_ALARM 0x01
#define REMAINING_TIME_ALARM 0x02
#define BATTERY_MODE 0x03
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

 /**
 * @struct BatteryMode
 * @brief A struct to hold various battery mode flags.
 * 
 * This struct holds various flags that represent the battery mode.
 */
struct BatteryMode {
  /**
   * @brief Indicates if the internal charge controller is supported.
   * 
   * This flag is true if the internal charge controller is supported, and false otherwise.
   */
  bool internal_charge_controller;

  /**
   * @brief Indicates if the primary battery support is supported.
   * 
   * This flag is true if the primary battery support is supported, and false otherwise.
   */
  bool primary_battery_support;

  /**
   * @brief Indicates the condition flag.
   * 
   * False if condition is ok, true if battery conditioning cycle is needed
   */
  bool condition_flag;

  /**
   * @brief Indicates if the charge controller is enabled.
   * 
   * This flag is true if the charge controller is enabled, and false otherwise.
   */
  bool charge_controller_enabled;

  /**
   * @brief Indicates if the primary battery is enabled.
   * 
   * This flag is true if the primary battery is enabled, and false otherwise.
   */
  bool primary_battery;

  /**
   * @brief Indicates the alarm mode.
   * 
   * True - enable alarmWarning broadcasts to host.
   * False - disable alarmWarning broadcasts to host.
   */
  bool alarm_mode;

  /**
   * @brief Indicates the charger mode.
   * 
   * True - enable chargingCurrent and chargingVoltage broadcasts to host.
   * False - disable chargingCurrent and chargingVoltage broadcasts to host.
   */
  bool charger_mode;

  /**
   * @brief Indicates the capacity mode.
   * 
   * True - report in mA or mAh.
   * False - report in 10mW or 10mWh.
   */
  bool capacity_mode;
};

class ArduinoSMBus {
public:
 

  BatteryMode battery_mode;

  ArduinoSMBus(uint8_t batteryAddress);
  void setBatteryAddress(uint8_t batteryAddress);

  uint16_t remainingCapacityAlarm();
  uint16_t remainingTimeAlarm();
  BatteryMode batteryMode();
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