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

ArduinoSMBus battery(0x0B); // Replace with your battery's address

void setup() {
  Serial.begin(9600);

  Serial.print("Remaining Capacity Alarm: ");
  Serial.println(battery.remainingCapacityAlarm());

  Serial.print("Remaining Time Alarm: ");
  Serial.println(battery.remainingTimeAlarm());

  Serial.print("Battery Modes:");
  BatteryMode mode = battery.batteryMode();

  Serial.print("\tInternal Charge Controller: ");
  Serial.println(mode.internal_charge_controller ? "Enabled" : "Disabled");

  Serial.print("\tPrimary Battery Support: ");
  Serial.println(mode.primary_battery_support ? "Enabled" : "Disabled");

  Serial.print("\tCondition Flag: ");
  Serial.println(mode.condition_flag ? "Set" : "Not Set");

  Serial.print("\tCharge Controller Enabled: ");
  Serial.println(mode.charge_controller_enabled ? "Enabled" : "Disabled");

  Serial.print("\tPrimary Battery: ");
  Serial.println(mode.primary_battery ? "Enabled" : "Disabled");

  Serial.print("\tAlarm Mode: ");
  Serial.println(mode.alarm_mode ? "Set" : "Not Set");

  Serial.print("\tCharger Mode: ");
  Serial.println(mode.charger_mode ? "Set" : "Not Set");

  Serial.print("\tCapacity Mode: ");
  Serial.println(mode.capacity_mode ? "Set" : "Not Set");

  Serial.print("Temperature: ");
  Serial.println(battery.temperature());

  Serial.print("Temperature in Celsius: ");
  Serial.println(battery.temperatureC());

  Serial.print("Temperature in Fahrenheit: ");
  Serial.println(battery.temperatureF());

  Serial.print("Voltage: ");
  Serial.println(battery.voltage());

  Serial.print("Current: ");
  Serial.println(battery.current());

  Serial.print("Average Current: ");
  Serial.println(battery.averageCurrent());

  Serial.print("Max Error: ");
  Serial.println(battery.maxError());

  Serial.print("Relative State Of Charge: ");
  Serial.println(battery.relativeStateOfCharge());

  Serial.print("Absolute State Of Charge: ");
  Serial.println(battery.absoluteStateOfCharge());

  Serial.print("Remaining Capacity: ");
  Serial.println(battery.remainingCapacity());

  Serial.print("Full Capacity: ");
  Serial.println(battery.fullCapacity());

  Serial.print("Run Time To Empty: ");
  Serial.println(battery.runTimeToEmpty());

  Serial.print("Average Time To Empty: ");
  Serial.println(battery.avgTimeToEmpty());

  Serial.print("Average Time To Full: ");
  Serial.println(battery.avgTimeToFull());

  Serial.print("Battery Status: ");
  Serial.println(battery.batteryStatus());

  Serial.print("Charging Current: ");
  Serial.println(battery.chargingCurrent());

  Serial.print("Charging Voltage: ");
  Serial.println(battery.chargingVoltage());

  Serial.print("Status OK: ");
  Serial.println(battery.statusOK());

  Serial.print("Is Charging: ");
  Serial.println(battery.isCharging());

  Serial.print("Is Fully Charged: ");
  Serial.println(battery.isFullyCharged());

  Serial.print("Cycle Count: ");
  Serial.println(battery.cycleCount());

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

  Serial.print("Manufacturer Name: ");
  Serial.println(battery.manufacturerName());

  Serial.print("Device Name: ");
  Serial.println(battery.deviceName());

  Serial.print("Device Chemistry: ");
  Serial.println(battery.deviceChemistry());

  Serial.print("State Of Health: ");
  Serial.println(battery.stateOfHealth());
}

void loop() {
  delay(10);
}