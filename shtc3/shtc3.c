/*
 * Copyright (c) 2023 Vadym Zakovinko
 *
 * SPDX-License-Identifier: MIT
 */

#include "shtc3.h"


int8_t shtc3_wakeup(void) {
  return sensirion_cmd(SHTC3_ADDR, SHTC3_CMD_WAKEUP);
}

int8_t shtc3_sleep(void) {
  return sensirion_cmd(SHTC3_ADDR, SHTC3_CMD_SLEEP);
}

int8_t shtc3_soft_reset(void) {
  return sensirion_cmd(SHTC3_ADDR, SHTC3_CMD_SOFT_RESET);
}

int8_t shtc3_id(uint16_t *id) {
  int8_t err = sensirion_cmd(SHTC3_ADDR, SHTC3_CMD_ID);
  uint8_t buf[3] = {0};
  err = sensirion_read(SHTC3_ADDR, buf, 3);
  if (err != 0) {
    return err;
  }

  if (sensirion_get_crc(buf) == buf[2]) {
    *id = (buf[0] << 8) | buf[1];
  }

  return 0;
}

int8_t shtc3_get_measurements(uint8_t mode, float *temperature, float *humidity) {
  int8_t err = sensirion_cmd(SHTC3_ADDR, SHTC3_CMD_MEAS_NORMAL_CS_EN_T_FIRST);
  if (err != 0) {
    return err;
  }
  uint8_t buf[6] = {0};
  err = sensirion_read(SHTC3_ADDR, buf, 6);
  if (err != 0) {
    return err;
  }

  uint16_t value;
  if (sensirion_get_crc(buf) == buf[2]) {
    value = (buf[0] << 8) | buf[1];
    *temperature = -45.0f + 175.0f * ((float)value / 65536.0f);
  } else {
    return 10;
  }

  if (sensirion_get_crc(buf + 3) == buf[5]) {
    value = (buf[3] << 8) | buf[4];
    *humidity = 100.0f * ((float)value / 65536.0f);
  } else {
    return 20;
  }

  return 0;
}
