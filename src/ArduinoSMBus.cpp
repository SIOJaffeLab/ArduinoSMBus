#include "ArduinoSMBus.h"

ArduinoSMBus::ArduinoSMBus(uint8_t batteryAddress) {
  _batteryAddress = batteryAddress;
  Wire.begin();
}

uint16_t ArduinoSMBus::voltage() {
  return readRegister(VOLTAGE);
}

uint16_t ArduinoSMBus::temperature() {
  return readRegister(TEMPERATURE);
}

uint16_t ArduinoSMBus::current() {
  return readRegister(CURRENT);
}

uint16_t ArduinoSMBus::capacity() {
  return readRegister(CAPACITY);
}

uint16_t ArduinoSMBus::timeToFull() {
  return readRegister(TIME_TO_FULL);
}

uint16_t ArduinoSMBus::charge() {
  return readRegister(CHARGE);
}

uint16_t ArduinoSMBus::timeToEmpty() {
  return readRegister(TIME_TO_EMPTY);
}

uint16_t ArduinoSMBus::status() {
  return readRegister(STATUS);
}

uint16_t ArduinoSMBus::cycleCount() {
  return readRegister(CYCLE_COUNT);
}

uint16_t ArduinoSMBus::designCapacity() {
  return readRegister(DESIGN_CAPACITY);
}

uint16_t ArduinoSMBus::designVoltage() {
  return readRegister(DESIGN_VOLTAGE);
}

uint16_t ArduinoSMBus::manufactureDate() {
  return readRegister(MANUFACTURE_DATE);
}

uint16_t ArduinoSMBus::serialNumber() {
  return readRegister(SERIAL_NUMBER);
}

uint16_t ArduinoSMBus::deviceName() {
  return readRegister(DEVICE_NAME);
}

uint16_t ArduinoSMBus::deviceChemistry() {
  return readRegister(DEVICE_CHEMISTRY);
}

uint16_t ArduinoSMBus::manufacturerName() {
  return readRegister(MANUFACTURER_NAME);
}

uint16_t ArduinoSMBus::manufacturerData() {
  return readRegister(MANUFACTURER_DATA);
}

uint16_t ArduinoSMBus::manufacturerInfo() {
  return readRegister(MANUFACTURER_INFO);
}

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