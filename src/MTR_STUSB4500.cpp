#include "MTR_STUSB4500.h"

// Constructor to initialize the I2C address
MTR_STUSB4500::MTR_STUSB4500(uint8_t i2c_addr) : _i2c_addr(i2c_addr) {}

// Initializes the STUSB4500 device
void MTR_STUSB4500::init() {
    Wire.begin();
}

// Reads a register from the STUSB4500
bool MTR_STUSB4500::readRegister(uint8_t reg_addr, uint8_t &data) {
    Wire.beginTransmission(_i2c_addr);
    Wire.write(reg_addr);
    if (Wire.endTransmission() != 0) {
        return false;
    }

    Wire.requestFrom(_i2c_addr, (uint8_t)1);
    if (Wire.available()) {
        data = Wire.read();
        return true;
    }
    return false;
}

// Writes a value to a register of the STUSB4500
bool MTR_STUSB4500::writeRegister(uint8_t reg_addr, uint8_t data) {
    Wire.beginTransmission(_i2c_addr);
    Wire.write(reg_addr);
    Wire.write(data);
    return (Wire.endTransmission() == 0);
}

// Gets the alert status from the STUSB4500
bool MTR_STUSB4500::getAlertStatus(uint8_t &status) {
    return readRegister(STUSB4500_ALERT_STATUS_REG, status);
}

// Gets the port status from the STUSB4500
bool MTR_STUSB4500::getPortStatus(uint8_t &status) {
    return readRegister(STUSB4500_PORT_STATUS_0_REG, status);
}

// Sends a command to the STUSB4500
bool MTR_STUSB4500::sendCommand(uint8_t command) {
    return writeRegister(STUSB4500_CMD_CTRL_REG, command);
}

// Reads the device ID from the STUSB4500
bool MTR_STUSB4500::getDeviceID(uint8_t &device_id) {
    return readRegister(STUSB4500_DEVICE_ID_REG, device_id);
}

// Sets the number of sink PDOs
bool MTR_STUSB4500::setPdoNumber(uint8_t pdo_number) {
    return writeRegister(STUSB4500_PDO_NUMB_REG, pdo_number);
}

// Sets the voltage value for SNK_PDO2
bool MTR_STUSB4500::setVSinkPdo2(uint16_t voltage) {
    uint8_t data[2];
    data[0] = (voltage >> 8) & 0xFF;
    data[1] = voltage & 0xFF;
    return writeRegister(STUSB4500_V_SNK_PDO2_REG, data[0]) &&
           writeRegister(STUSB4500_V_SNK_PDO2_REG + 1, data[1]);
}

// Sets the voltage value for SNK_PDO3
bool MTR_STUSB4500::setVSinkPdo3(uint16_t voltage) {
    uint8_t data[2];
    data[0] = (voltage >> 8) & 0xFF;
    data[1] = voltage & 0xFF;
    return writeRegister(STUSB4500_V_SNK_PDO3_REG, data[0]) &&
           writeRegister(STUSB4500_V_SNK_PDO3_REG + 1, data[1]);
}

// Sets the current value for SNK_PDO1
bool MTR_STUSB4500::setISinkPdo1(uint16_t current) {
    uint8_t data[2];
    data[0] = (current >> 8) & 0xFF;
    data[1] = current & 0xFF;
    return writeRegister(STUSB4500_I_SNK_PDO1_REG, data[0]) &&
           writeRegister(STUSB4500_I_SNK_PDO1_REG + 1, data[1]);
}

// Sets the current value for SNK_PDO2
bool MTR_STUSB4500::setISinkPdo2(uint16_t current) {
    uint8_t data[2];
    data[0] = (current >> 8) & 0xFF;
    data[1] = current & 0xFF;
    return writeRegister(STUSB4500_I_SNK_PDO2_REG, data[0]) &&
           writeRegister(STUSB4500_I_SNK_PDO2_REG + 1, data[1]);
}

// Sets the current value for SNK_PDO3
bool MTR_STUSB4500::setISinkPdo3(uint16_t current) {
    uint8_t data[2];
    data[0] = (current >> 8) & 0xFF;
    data[1] = current & 0xFF;
    return writeRegister(STUSB4500_I_SNK_PDO3_REG, data[0]) &&
           writeRegister(STUSB4500_I_SNK_PDO3_REG + 1, data[1]);
}
