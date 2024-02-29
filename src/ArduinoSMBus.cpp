/**
 * @file ArduinoSMBus.cpp
 * @author Christopher Lee (clee@unitedconsulting.com)
 * @brief Function definitions for the ArduinoSMBus class.
 * @version 1.0
 * @date 2024-02-29
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "ArduinoSMBus.h"

/**
 * @brief Construct a new ArduinoSMBus:: ArduinoSMBus object.
 * 
 * @param batteryAddress 
 */
ArduinoSMBus::ArduinoSMBus(uint8_t batteryAddress) {
  _batteryAddress = batteryAddress;
  Wire.begin();
}

/**
 * @brief Get the battery's voltage.
 * Returns the sum of all cell voltages, in mV.
 * @return uint16_t 
 */
uint16_t ArduinoSMBus::voltage() {
  return readRegister(VOLTAGE);
}

/**
 * @brief Get the battery's temperature.
 * Returns the battery temperature in 0.1 degrees Kelvin.
 * @return uint16_t 
 */
uint16_t ArduinoSMBus::temperature() {
  return readRegister(TEMPERATURE);
}

/**
 * @brief Get the battery's temperature in Celsius.
 * Returns the battery temperature in 0.1 degrees Celsius.
 * @return uint16_t 
 */
uint16_t ArduinoSMBus::temperatureC() {
  uint16_t temperatureKelvin = readRegister(TEMPERATURE);
  uint16_t temperatureCelsius = temperatureKelvin - 2731; // Convert from Kelvin to Celsius
  return temperatureCelsius;
}

/**
 * @brief Get the battery's temperature in Fahrenheit.
 * Returns the battery temperature in 0.1 degrees Fahrenheit.
 * @return uint16_t 
 */
uint16_t ArduinoSMBus::temperatureF() {
  uint16_t temperatureKelvin = readRegister(TEMPERATURE);
  uint16_t temperatureFahrenheit = (temperatureKelvin * 18 - 45967) / 10; // Convert from Kelvin to Fahrenheit
  return temperatureFahrenheit;
}

/**
 * @brief Get the battery's current.
 * Returns the battery measured current (from the coulomb counter) in mA.
 * @return uint16_t 
 */
uint16_t ArduinoSMBus::current() {
  return readRegister(CURRENT);
}

/**
 * @brief Get the battery's capacity.
 * Returns the predicted battery capacity when fully charged, in mAh.
 * For some batteries, this may be in 10 mWh, if the BatteryMode() register (0x03) is set to CAPM 1.
 * See TI protocol documentation for details.
 * @return uint16_t 
 */
uint16_t ArduinoSMBus::capacity() {
  return readRegister(CAPACITY);
}

/**
 * @brief Get the battery's current charge.
 * Returns the predicted remaining battery capacity as a percentage
 * @return uint16_t 
 */
uint16_t ArduinoSMBus::stateofCharge() {
  return readRegister(STATE_OF_CHARGE);
}

/**
 * @brief Get the battery's state of charge error.
 * Returns the battery's margin of error when estimating SOC, in percent
 * @return uint16_t 
 */
uint16_t ArduinoSMBus::SOCError() {
  return readRegister(SOC_ERROR);
}

/**
 * @brief Get the battery's time to full.
 * Returns the predicted time to full charge, in minutes, based on average charge rate.
 * @return uint16_t 
 */
uint16_t ArduinoSMBus::timeToFull() {
  return readRegister(TIME_TO_FULL);
}

/**
 * @brief Get the battery's time to empty.
 * Returns the predicted time to empty, in minutes, based on average discharge rate.
 * @return uint16_t 
 */
uint16_t ArduinoSMBus::timeToEmpty() {
  return readRegister(TIME_TO_EMPTY);
}

/**
 * @brief Get the Status from the battery.
 * Returns the battery status register, which contains various alarm conditions and other status bits.
 * @return uint16_t 
 */
uint16_t ArduinoSMBus::status() {
  uint8_t data[2];
  readBlock(STATUS, data, 2);
  uint16_t status = (data[1] << 8) | data[0];
  return status;
}

/**
 * @brief Check if the battery status is OK.
 * Check for any alarm conditions in the battery status register. These include bits
 * 8, 9, 11, 12, 14, and 15. If any of these bits are set, the battery is not in error
 * @return bool 
 */
bool ArduinoSMBus::statusOK() {
  uint16_t status = this->status();
  uint16_t mask = (1 << 15) | (1 << 14) | (1 << 12) | (1 << 11) | (1 << 9) | (1 << 8);
  return (status & mask) != mask; // Trigger error state if any of the specified bits are set
}

/**
 * @brief Check if the battery is charging.
 * 
 * @return bool 
 */
bool ArduinoSMBus::isCharging() {
  uint16_t status = this->status();
  return ((status & (1 << 6)) == 0);
}

/**
 * @brief Check if the battery is fully charged.
 * 
 * @return bool 
 */
bool ArduinoSMBus::isFullyCharged() {
  uint16_t status = this->status();
  return ((status & (1 << 5)) != 0);
}

/**
 * @brief  Get the battery's cycle count.
 * Returns the number of discharge cycles the battery has experienced.
 * @return uint16_t 
 */
uint16_t ArduinoSMBus::cycleCount() {
  return readRegister(CYCLE_COUNT);
}

/**
 * @brief Get the State of Health from the battery.
 * Returns the estimated health of the battery, as a percentage of design capacity
 * @return uint16_t 
 */
uint16_t ArduinoSMBus::stateOfHealth() {
  uint8_t data[2];
  readBlock(STATE_OF_HEALTH, data, 2);
  uint16_t stateOfHealth = (data[1] << 8) | data[0];
  return stateOfHealth;
}

/**
 * @brief Get the battery's design capacity.
 * Returns the theoretical maximum capacity of the battery, in mAh.
 * For some batteries, this may be in 10 mWh, if the BatteryMode() register (0x03) is set to CAPM 1.
 * See TI protocol documentation for details.
 * @return uint16_t 
 */
uint16_t ArduinoSMBus::designCapacity() {
  return readRegister(DESIGN_CAPACITY);
}

/**
 * @brief Get the battery's design voltage.
 * Returns the nominal voltage of the battery, in mV.
 * @return uint16_t 
 */
uint16_t ArduinoSMBus::designVoltage() {
  return readRegister(DESIGN_VOLTAGE);
}

/**
 * @brief  Get the battery's manufacture date.
 * Returns the date the battery was manufactured, in the following format: 
 * Day + Month*32 + (Year–1980)*512
 * @return uint16_t 
 */
uint16_t ArduinoSMBus::manufactureDate() {
  return readRegister(MANUFACTURE_DATE);
}

/**
 * @brief Get the manufacture year from the manufacture date.
 * This is likely incorrect. The date is stored in a format that is not human-readable.
 * @return int 
 */
int ArduinoSMBus::manufactureYear() {
  uint16_t manufactureDate = this->manufactureDate();
  int year = ((manufactureDate - (manufactureDate % 512)) / 512) + 1980;
  return year;
}

/**
 * @brief Get the Serial Number from the battery.
 * 
 * @return uint16_t 
 */
uint16_t ArduinoSMBus::serialNumber() {
  return readRegister(SERIAL_NUMBER);
}

/**
 * @brief Get the Device Name from the battery.
 * 
 * @return const char* 
 */
const char* ArduinoSMBus::deviceName() {
  static char deviceName[21]; // Assuming the device name is up to 20 characters long
  readBlock(DEVICE_NAME, reinterpret_cast<uint8_t*>(deviceName), 20);
  deviceName[20] = '\0'; // Null-terminate the C-string
  return deviceName;
}

/**
 * @brief Get the Device Chemistry from the battery.
 * 
 * @return const char* 
 */
const char* ArduinoSMBus::deviceChemistry() {
  static char deviceChemistry[5];
  readBlock(DEVICE_CHEMISTRY, reinterpret_cast<uint8_t*>(deviceChemistry), 8);
  deviceChemistry[4] = '\0';
  return deviceChemistry;
}

/**
 * @brief Get the Manufacturer Name from the battery.
 * 
 * @return const char* 
 */
const char* ArduinoSMBus::manufacturerName() {
  static char manufacturerName[21]; // 20 characters plus null terminator
  readBlock(MANUFACTURER_NAME, reinterpret_cast<uint8_t*>(manufacturerName), 20);
  manufacturerName[20] = '\0'; // Null-terminate the C-string
  return manufacturerName;
}

/**
 * @brief Read a register from the battery.
 * Reads a standard 16-bit register from the battery.
 * @param reg 
 * @return uint16_t 
 */
uint16_t ArduinoSMBus::readRegister(uint8_t reg) {
  Wire.beginTransmission(_batteryAddress);
  Wire.write(reg);
  Wire.endTransmission();
  
  delay(10);
  
  Wire.requestFrom(_batteryAddress, 2);
  
  if(Wire.available()) {
    return Wire.read() | Wire.read() << 8;
  } else {
    return 0;
  }
}

/**
 * @brief Reads a block of data from the battery.
 * Length of block is specified by the length parameter.
 * @param reg 
 * @param data 
 * @param length 
 */
void ArduinoSMBus::readBlock(uint8_t reg, uint8_t* data, uint8_t length) {
  Wire.beginTransmission(_batteryAddress);
  Wire.write(reg);
  Wire.endTransmission(false);

  delay(10); // Add a small delay to give the device time to prepare the data

  uint8_t count = Wire.requestFrom(_batteryAddress, length + 1); // Request one extra byte for the length

  if (Wire.available()) {
    count = Wire.read(); // The first byte is the length of the block
  }

  for (uint8_t i = 0; i < count && i < length; i++) {
    if (Wire.available()) {
      data[i] = Wire.read();
    }
  }
}