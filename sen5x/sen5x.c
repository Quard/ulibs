/*
 * Copyright (c) 2023 Vadym Zakovinko
 *
 * SPDX-License-Identifier: MIT
 */

#include "sen5x.h"


int8_t sen5x_start_measurement(uint16_t mode) {
  return sensirion_cmd(SEN5X_ADDR, mode);
}

int8_t sen5x_read_data(uint16_t *pm10, uint16_t *pm25, uint16_t *pm40, uint16_t *pm100) {
  uint8_t buf[12];

  int8_t err = sensirion_cmd(SEN5X_ADDR, SEN5X_CMD_READ_MEAS_VALUES);
  if (err != 0) return err;
  delay_ms(20);
  err = sensirion_read(SEN5X_ADDR, buf, 12);
  if (err != 0) return err;

  for (uint8_t i=0; i<12; i+=3) {
    if (sensirion_get_crc(buf + i) != buf[i + 2])
        return i * 10;
  }

  *pm10 = (buf[0] << 8) | buf[1];
  *pm25 = (buf[3] << 8) | buf[4];
  *pm40 = (buf[6] << 8) | buf[7];
  *pm100 = (buf[9] << 8) | buf[10];

  return err;
}

int8_t sen5x_is_data_ready(uint8_t *ready) {
  uint8_t buf[3] = {0};

  int8_t err = sensirion_cmd(SEN5X_ADDR, SEN5X_CMD_READ_DATA_READY_FLG);
  if (err != 0) return err;
  err = sensirion_read(SEN5X_ADDR, buf, 3);
  if (err != 0) return err;

  if (sensirion_get_crc(buf) == buf[2]) {
    *ready = buf[1];
  } else {
    return 10;
  }

  return err;
}
