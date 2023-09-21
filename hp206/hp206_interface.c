/*
 * Copyright (c) 2023 Vadym Zakovinko
 *
 * SPDX-License-Identifier: MIT
 */

#include "hp206_interface.h"


int8_t hp206_cmd(uint8_t cmd) {
  // write command to the sensor
}

int8_t hp206_read8(uint8_t reg, uint8_t *value) {
  // read 1 byte from the sensor
}

int8_t hp206_read(uint8_t reg, uint8_t *buf, uint8_t len) {
  // read from the sensor
}

int8_t hp206_read_reg(uint8_t reg, uint8_t *buf, uint8_t len) {
  reg |= HP206_CMD_READ_REG;
  // read the `reg` sensor register
}

int8_t hp206_write_reg(uint8_t reg, uint8_t value) {
  reg |= HP206_CMD_WRITE_REG;
  // write to the `reg` sensor register
}
