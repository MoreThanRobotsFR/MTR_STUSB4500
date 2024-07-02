#include <Wire.h>
#include "MTR_STUSB4500.h"

// Create an instance of the STUSB4500 class
MTR_STUSB4500 stusb4500;

void setup() {
  // Initialize the STUSB4500 device
  stusb4500.init();

  // Set the number of sink PDOs to 3
  stusb4500.setPdoNumber(3);

  // Set the voltage value for SNK_PDO2 to 9V
  stusb4500.setVSinkPdo2(9000);

  // Set the voltage value for SNK_PDO3 to 12V
  stusb4500.setVSinkPdo3(12000);

  // Set the current value for SNK_PDO1 to 1A
  stusb4500.setISinkPdo1(1000);

  // Set the current value for SNK_PDO2 to 1.5A
  stusb4500.setISinkPdo2(1500);

  // Set the current value for SNK_PDO3 to 2A
  stusb4500.setISinkPdo3(2000);
}

void loop() {
  // Get the alert status from the STUSB4500
  uint8_t alertStatus;
  if (stusb4500.getAlertStatus(alertStatus)) {
    Serial.print("Alert status: 0x");
    Serial.println(alertStatus, HEX);
  }

  // Get the port status from the STUSB4500
  uint8_t portStatus;
  if (stusb4500.getPortStatus(portStatus)) {
    Serial.print("Port status: 0x");
    Serial.println(portStatus, HEX);
  }

  // Get the device ID from the STUSB4500
  uint8_t deviceID;
  if (stusb4500.getDeviceID(deviceID)) {
    Serial.print("Device ID: 0x");
    Serial.println(deviceID, HEX);
  }

  delay(1000); // Wait for 1 second
}