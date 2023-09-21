/*
 * Copyright (c) 2023 Vadym Zakovinko
 *
 * SPDX-License-Identifier: MIT
 */

#include "hp206_interface.h"


int8_t hp206_cmd(uint8_t cmd) {
  return i2c1_write(HP206_I2C_ADDR, &cmd, 1);
}

int8_t hp206_read8(uint8_t reg, uint8_t *value) {
  i2c1_write(HP206_I2C_ADDR, &reg, 1);
  return i2c1_read(HP206_I2C_ADDR, value, 1);
}

int8_t hp206_read(uint8_t reg, uint8_t *buf, uint8_t len) {
  i2c1_write(HP206_I2C_ADDR, &reg, 1);
  return i2c1_read(HP206_I2C_ADDR, buf, len);

}

int8_t hp206_read_reg(uint8_t reg, uint8_t *buf, uint8_t len) {
  reg |= HP206_CMD_READ_REG;
  i2c1_write(HP206_I2C_ADDR, &reg, 1);
  return i2c1_read(HP206_I2C_ADDR, buf, len);
}

int8_t hp206_write_reg(uint8_t reg, uint8_t value) {
  uint8_t buf[] = {HP206_CMD_WRITE_REG | reg, value};
  return i2c1_write(HP206_I2C_ADDR, buf, 2);
}
