/*
 * Copyright (c) 2023 Vadym Zakovinko
 *
 * SPDX-License-Identifier: MIT
 */

#include "hp206.h"

int8_t hp206_init(uint8_t compensation) {
  if (compensation) {
    compensation = 1 << 7;
  }
//  int8_t status = hp206_cmd(HP206_CMD_SOFT_RST);
//  if (status != 0) {
//    return status;
//  }
  int8_t status = hp206_write_reg(HP206_REG_PARA, 0x00);
  if (status != 0) {
    return status;
  }

  return hp206_write_reg(HP206_REG_INT_EN, (1 << 5));
}

int8_t hp206_start(uint8_t chnl, uint8_t osr) {
  return hp206_cmd(0b01000000 | (osr << HP206_ADC_CVT_OSR_Pos) | (chnl << HP206_ADC_CVT_CHNL_Pos));
}

int8_t hp206_read_p(uint32_t *pressure) {
  *pressure = 0;
  return hp206_read(HP206_CMD_READ_P, (uint8_t *)pressure, 3);
}

int8_t hp206_read_pt(uint32_t *temp, uint32_t *pressure) {
  uint8_t buf[6];
  int8_t status = hp206_read(HP206_CMD_READ_PT, buf, 6);
  if (status == 0) {
    *temp = (buf[0] << 16) | (buf[1] << 8) | buf[2];
    *pressure = (buf[3] << 16) | (buf[4] << 8) | buf[5];
  }

  return status;
}

int8_t hp206_get_interrupts(uint8_t *value) {
  return hp206_read_reg(HP206_REG_INT_SRC, value, 1);
}
