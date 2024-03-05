/**
 * @file main.cpp
 * @author Christopher Lee (clee@unitedconsulting.com)
 * @brief Example arduino code to read battery data from an SMBus battery and print to serial output.
 * @version 1.0
 * @date 2024-02-29
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <Arduino.h>
#include "ArduinoSMBus.h"

ArduinoSMBus battery(0x0B); // replace with your battery's I2C address

void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.print("Voltage: ");
  Serial.println(battery.voltage());
  
  Serial.print("Temperature: ");
  Serial.println(battery.temperature());

  Serial.print("Temperature in C: ");
  Serial.println(battery.temperatureC());

  Serial.print("Temperature in F: ");
  Serial.println(battery.temperatureF());
  
  Serial.print("Current: ");
  Serial.println(battery.current());
  
  Serial.print("Capacity: ");
  Serial.println(battery.capacity());
  
  Serial.print("Time to Full: ");
  Serial.println(battery.timeToFull());
  
  Serial.print("Charge: ");
  Serial.println(battery.stateOfCharge());

  Serial.print("SOC Error: ");
  Serial.println(battery.SOCError());
  
  Serial.print("Time to Empty: ");
  Serial.println(battery.timeToEmpty());

  Serial.print("Status: ");
  uint16_t status = battery.status();
  for (int i = 0; i < 16; i++) {
    Serial.print((status >> i) & 1);
  }
  Serial.println();

  Serial.print("Status OK: ");
  Serial.println(battery.statusOK() ? "true" : "false");

  Serial.print("Battery Charging: ");
  Serial.println(battery.isCharging() ? "true" : "false");

   Serial.print("Battery Fully Charged: ");
  Serial.println(battery.isFullyCharged() ? "true" : "false");
  
  Serial.print("Cycle Count: ");
  Serial.println(battery.cycleCount());

  Serial.print("State of Health: ");
  Serial.println(battery.stateOfHealth());
  
  Serial.print("Design Capacity: ");
  Serial.println(battery.designCapacity());
  
  Serial.print("Design Voltage: ");
  Serial.println(battery.designVoltage());
  
  Serial.print("Manufacture Date: ");
  Serial.println(battery.manufactureDate());

  Serial.print("Manufacture Year: ");
  Serial.println(battery.manufactureYear());
  
  Serial.print("Serial Number: ");
  Serial.println(battery.serialNumber());
  
  Serial.print("Device Name: ");
  Serial.println(battery.deviceName());
  
  Serial.print("Device Chemistry: ");
  Serial.println(battery.deviceChemistry());
  
  Serial.print("Manufacturer Name: ");
  Serial.println(battery.manufacturerName());
  
  while(1); // Stop the loop after printing once
}