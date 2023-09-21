/*
 * Copyright (c) 2023 Vadym Zakovinko
 *
 * SPDX-License-Identifier: MIT
 */

#include "veml6070_interface.h"


int8_t veml6070_write8(uint8_t value) {
  // write 1 byte to device with VEML6070_ADDR_WRITE address
  return i2c1_write(VEML6070_ADDR_WRITE, &value, 1);
}

int8_t veml6070_read16(uint16_t *value) {
  // read from devices VEML6070_ADDR_LSB and VEML6070_ADDR_MSB
  uint8_t lsb, msb;

  int8_t status = i2c1_read(VEML6070_ADDR_LSB, &lsb, 1);
  status &= i2c1_read(VEML6070_ADDR_MSB, &msb, 1);

  *value = (msb << 8) | lsb;

  return status;
}
