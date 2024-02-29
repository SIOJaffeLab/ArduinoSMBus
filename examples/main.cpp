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
  
  Serial.print("Current: ");
  Serial.println(battery.current());
  
  Serial.print("Capacity: ");
  Serial.println(battery.capacity());
  
  Serial.print("Time to Full: ");
  Serial.println(battery.timeToFull());
  
  Serial.print("Charge: ");
  Serial.println(battery.charge());
  
  Serial.print("Time to Empty: ");
  Serial.println(battery.timeToEmpty());
  
  Serial.print("Status: ");
  Serial.println(battery.status());
  
  Serial.print("Cycle Count: ");
  Serial.println(battery.cycleCount());
  
  Serial.print("Design Capacity: ");
  Serial.println(battery.designCapacity());
  
  Serial.print("Design Voltage: ");
  Serial.println(battery.designVoltage());
  
  Serial.print("Manufacture Date: ");
  Serial.println(battery.manufactureDate());
  
  Serial.print("Serial Number: ");
  Serial.println(battery.serialNumber());
  
  Serial.print("Device Name: ");
  Serial.println(battery.deviceName());
  
  Serial.print("Device Chemistry: ");
  Serial.println(battery.deviceChemistry());
  
  Serial.print("Manufacturer Name: ");
  Serial.println(battery.manufacturerName());
  
  Serial.print("Manufacturer Data: ");
  Serial.println(battery.manufacturerData());
  
  Serial.print("Manufacturer Info: ");
  Serial.println(battery.manufacturerInfo());

  while(1); // Stop the loop after printing once
}