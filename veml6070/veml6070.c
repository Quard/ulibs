/*
 * Copyright (c) 2023 Vadym Zakovinko
 *
 * SPDX-License-Identifier: MIT
 */

#include "veml6070.h"


int8_t veml6070_init(uint8_t ack, uint8_t ack_thd, uint8_t it) {
  uint8_t cmd = ack | ack_thd | it;
  return veml6070_write8(cmd);
}

int8_t veml6070_read(uint16_t *uv_level) {
  return veml6070_read16(uv_level);
}

int8_t veml6070_shutdown(void) {
  return veml6070_write8(VEML6070_SD_ENABLE);
}
