#include "ArduinoSMBus.h"

/**
 * @brief Construct a new ArduinoSMBus:: ArduinoSMBus object
 * 
 * @param batteryAddress 
 */
ArduinoSMBus::ArduinoSMBus(uint8_t batteryAddress) {
  _batteryAddress = batteryAddress;
  Wire.begin();
}

/**
 * @brief Get the battery's voltage
 * 
 * @return uint16_t 
 */
uint16_t ArduinoSMBus::voltage() {
  return readRegister(VOLTAGE);
}

/**
 * @brief Get the battery's temperature
 * 
 * @return uint16_t 
 */
uint16_t ArduinoSMBus::temperature() {
  return readRegister(TEMPERATURE);
}

/**
 * @brief Get the battery's current
 * 
 * @return uint16_t 
 */
uint16_t ArduinoSMBus::current() {
  return readRegister(CURRENT);
}

/**
 * @brief Get the battery's state of charge
 * 
 * @return uint16_t 
 */
uint16_t ArduinoSMBus::capacity() {
  return readRegister(CAPACITY);
}

/**
 * @brief Get the battery's time to full
 * 
 * @return uint16_t 
 */
uint16_t ArduinoSMBus::timeToFull() {
  return readRegister(TIME_TO_FULL);
}

/**
 * @brief Get the battery's current charge
 * 
 * @return uint16_t 
 */
uint16_t ArduinoSMBus::charge() {
  return readRegister(CHARGE);
}

/**
 * @brief Get the battery's time to empty
 * 
 * @return uint16_t 
 */
uint16_t ArduinoSMBus::timeToEmpty() {
  return readRegister(TIME_TO_EMPTY);
}

/**
 * @brief Get the battery's current status
 * 
 * @return uint16_t 
 */
uint16_t ArduinoSMBus::status() {
  return readRegister(STATUS);
}

/**
 * @brief  Get the battery's cycle count
 * 
 * @return uint16_t 
 */
uint16_t ArduinoSMBus::cycleCount() {
  return readRegister(CYCLE_COUNT);
}

/**
 * @brief Get the battery's design capacity
 * 
 * @return uint16_t 
 */
uint16_t ArduinoSMBus::designCapacity() {
  return readRegister(DESIGN_CAPACITY);
}

/**
 * @brief Get the battery's design voltage
 * 
 * @return uint16_t 
 */
uint16_t ArduinoSMBus::designVoltage() {
  return readRegister(DESIGN_VOLTAGE);
}

/**
 * @brief  Get the battery's manufacture date
 * 
 * @return uint16_t 
 */
uint16_t ArduinoSMBus::manufactureDate() {
  return readRegister(MANUFACTURE_DATE);
}

/**
 * @brief Get the Serial Number from the battery
 * 
 * @return uint16_t 
 */
uint16_t ArduinoSMBus::serialNumber() {
  return readRegister(SERIAL_NUMBER);
}

/**
 * @brief Get the Device Name from the battery
 * 
 * @return uint16_t 
 */
uint16_t ArduinoSMBus::deviceName() {
  return readRegister(DEVICE_NAME);
}

/**
 * @brief Get the Device Chemistry from the battery
 * 
 * @return uint16_t 
 */
uint16_t ArduinoSMBus::deviceChemistry() {
  return readRegister(DEVICE_CHEMISTRY);
}

/**
 * @brief Get the Manufacturer Name from the battery
 * 
 * @return uint16_t 
 */
uint16_t ArduinoSMBus::manufacturerName() {
  return readRegister(MANUFACTURER_NAME);
}

/**
 * @brief Get the Manufacturer Data from the battery
 * 
 * @return uint16_t 
 */
uint16_t ArduinoSMBus::manufacturerData() {
  return readRegister(MANUFACTURER_DATA);
}

/**
 * @brief Get the Manufacturer Info from the battery
 * 
 * @return uint16_t 
 */
uint16_t ArduinoSMBus::manufacturerInfo() {
  return readRegister(MANUFACTURER_INFO);
}

/**
 * @brief Read a register from the battery
 * 
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