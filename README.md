# Explanation of the Functions

1. **Constructor:**
   - `MTR_STUSB4500(uint8_t i2c_addr = STUSB4500_I2C_ADDR)`: Initializes the I2C address with a default value of `0x28`.

2. **Initialization:**
   - `void init()`: Initializes the I2C communication using the `Wire` library.

3. **Read Register:**
   - `bool readRegister(uint8_t reg_addr, uint8_t &data)`: Reads a byte from the specified register address and stores it in the provided `data` variable. Returns `true` if the read operation is successful.

4. **Write Register:**
   - `bool writeRegister(uint8_t reg_addr, uint8_t data)`: Writes a byte to the specified register address. Returns `true` if the write operation is successful.

5. **Get Alert Status:**
   - `bool getAlertStatus(uint8_t &status)`: Reads the alert status register and stores the value in the `status` variable. Returns `true` if the read operation is successful.

6. **Get Port Status:**
   - `bool getPortStatus(uint8_t &status)`: Reads the port status register and stores the value in the `status` variable. Returns `true` if the read operation is successful.

7. **Send Command:**
   - `bool sendCommand(uint8_t command)`: Writes a command to the command control register. Returns `true` if the write operation is successful.

8. **Get Device ID:**
   - `bool getDeviceID(uint8_t &device_id)`: Reads the device ID register and stores the value in the `device_id` variable. Returns `true` if the read operation is successful.

9. **Set PDO Number:**
   - `bool setPdoNumber(uint8_t pdo_number)`: Writes the number of sink PDOs to the corresponding register. Returns `true` if the write operation is successful.

10. **Set Voltage and Current for Sink PDOs:**
    - `bool setVSinkPdo2(uint16_t voltage)`, `bool setVSinkPdo3(uint16_t voltage)`: Write the voltage (in mV) values for SNK_PDO2 and SNK_PDO3 registers (PDO1 is fixed at 5V). The voltage is split into two bytes and written to consecutive register addresses. Returns `true` if both write operations are successful.
    - `bool setISinkPdo1(uint16_t current)`, `bool setISinkPdo2(uint16_t current)`, `bool setISinkPdo3(uint16_t current)`: Write the current (in mA) values for SNK_PDO1, SNK_PDO2, and SNK_PDO3 registers. The current is split into two bytes and written to consecutive register addresses. Returns `true` if both write operations are successful.

This implementation makes the library compatible with the Arduino platform and encapsulates the functionality in a clean, object-oriented interface, including the necessary register addresses and detailed function explanations.

# Example Use Case

The example sketch provided demonstrates how to initialize the STUSB4500 device, set the number of sink PDOs, configure the voltage and current values for the sink PDOs, and read the alert status, port status, and device ID periodically. The sketch uses the `MTR_STUSB4500` library to interact with the STUSB4500 device over I2C.

```cpp
#include <Wire.h>
#include <MTR_STUSB4500.h>

// Create an instance of the STUSB4500 class
MTR_STUSB4500 stusb4500;

void setup() {
  // Initialize the STUSB4500 device
  stusb4500.init();

  // Set the number of sink PDOs to 1
  stusb4500.setPdoNumber(1);

  // Set the voltage value for SNK_PDO1 to 5V
  // can't be set, because is hardcoded to 5V

  // Set the current value for SNK_PDO1 to 1A
  stusb4500.setISinkPdo1(1000);

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
```