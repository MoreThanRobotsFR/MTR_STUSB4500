#ifndef MTR_STUSB4500_H
#define MTR_STUSB4500_H

#include <Arduino.h>
#include <Wire.h>

/**
 * @brief I2C Address of the STUSB4500
 */
#define STUSB4500_I2C_ADDR 0x28

/**
 * @brief STUSB4500 Register Addresses
 */
#define STUSB4500_DEVICE_ID_REG        0x2F
#define STUSB4500_ALERT_STATUS_REG     0x0B
#define STUSB4500_PORT_STATUS_0_REG    0x0C
#define STUSB4500_PORT_STATUS_1_REG    0x0D
#define STUSB4500_CMD_CTRL_REG         0x1A
#define STUSB4500_PDO_NUMB_REG         0x70
// #define STUSB4500_V_SNK_PDO1_REG    Cant be set by user as it is hardcoded to 5V
#define STUSB4500_V_SNK_PDO2_REG       0x85
#define STUSB4500_V_SNK_PDO3_REG       0x87
#define STUSB4500_I_SNK_PDO1_REG       0x83
#define STUSB4500_I_SNK_PDO2_REG       0x86
#define STUSB4500_I_SNK_PDO3_REG       0x88

class MTR_STUSB4500 {
public:
    /**
     * @brief Constructor to initialize the MTR_STUSB4500 object.
     * @param i2c_addr The I2C address of the STUSB4500.
     */
    MTR_STUSB4500(uint8_t i2c_addr = STUSB4500_I2C_ADDR);

    /**
     * @brief Initializes the STUSB4500 device.
     */
    void init();

    /**
     * @brief Reads a register from the STUSB4500.
     * @param reg_addr The address of the register to read.
     * @param data The variable to store the register value.
     * @return True if successful, false otherwise.
     */
    bool readRegister(uint8_t reg_addr, uint8_t &data);

    /**
     * @brief Writes a value to a register of the STUSB4500.
     * @param reg_addr The address of the register to write.
     * @param data The value to write to the register.
     * @return True if successful, false otherwise.
     */
    bool writeRegister(uint8_t reg_addr, uint8_t data);

    /**
     * @brief Gets the alert status from the STUSB4500.
     * @param status The variable to store the alert status.
     * @return True if successful, false otherwise.
     */
    bool getAlertStatus(uint8_t &status);

    /**
     * @brief Gets the port status from the STUSB4500.
     * @param status The variable to store the port status.
     * @return True if successful, false otherwise.
     */
    bool getPortStatus(uint8_t &status);

    /**
     * @brief Sends a command to the STUSB4500.
     * @param command The command to send.
     * @return True if successful, false otherwise.
     */
    bool sendCommand(uint8_t command);

    /**
     * @brief Reads the device ID from the STUSB4500.
     * @param device_id The variable to store the device ID.
     * @return True if successful, false otherwise.
     */
    bool getDeviceID(uint8_t &device_id);

    /**
     * @brief Sets the number of sink PDOs.
     * @param pdo_number The number of sink PDOs.
     * @return True if successful, false otherwise.
     */
    bool setPdoNumber(uint8_t pdo_number);

    /**
     * @brief Sets the voltage value for SNK_PDO2.
     * @param voltage The voltage value for SNK_PDO2.
     * @return True if successful, false otherwise.
     */
    bool setVSinkPdo2(uint16_t voltage);

    /**
     * @brief Sets the voltage value for SNK_PDO3.
     * @param voltage The voltage value for SNK_PDO3.
     * @return True if successful, false otherwise.
     */
    bool setVSinkPdo3(uint16_t voltage);

    /**
     * @brief Sets the current value for SNK_PDO1.
     * @param current The current value for SNK_PDO1.
     * @return True if successful, false otherwise.
     */
    bool setISinkPdo1(uint16_t current);

    /**
     * @brief Sets the current value for SNK_PDO2.
     * @param current The current value for SNK_PDO2.
     * @return True if successful, false otherwise.
     */
    bool setISinkPdo2(uint16_t current);

    /**
     * @brief Sets the current value for SNK_PDO3.
     * @param current The current value for SNK_PDO3.
     * @return True if successful, false otherwise.
     */
    bool setISinkPdo3(uint16_t current);

private:
    uint8_t _i2c_addr;
};

#endif // MTR_STUSB4500_H