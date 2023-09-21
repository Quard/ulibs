/*
 * Copyright (c) 2023 Vadym Zakovinko
 *
 * SPDX-License-Identifier: MIT
 */

#include <sensirion_interface.h>


int8_t sensirion_cmd(uint8_t addr, uint16_t cmd) {
  // write command (2 bytes) to the device
}

int8_t sensirion_read(uint8_t addr, uint8_t *buf, uint8_t len) {
  // read len bytes from the device to the buf
}

uint8_t sensirion_get_crc(uint8_t data[2]) {
  uint8_t crc = 0xFF;

  for (int8_t i=0; i<2; i++) {
    crc ^= data[i];
    for (uint8_t bit=8; bit > 0; --bit) {
      if (crc & 0x80) {
        crc = (crc << 1) ^ 0x31u;
      } else {
        crc = (crc << 1);
      }
    }
  }

  return crc;
}
