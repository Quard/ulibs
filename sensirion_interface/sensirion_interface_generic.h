/*
 * Copyright (c) 2023 Vadym Zakovinko
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef SENSIRION_INCLUDES_SENSIRION_INTERFACE_H_
#define SENSIRION_INCLUDES_SENSIRION_INTERFACE_H_

#include "main.h"

int8_t sensirion_cmd(uint8_t addr, uint16_t cmd);
int8_t sensirion_read(uint8_t addr, uint8_t *buf, uint8_t len);
uint8_t sensirion_get_crc(uint8_t data[2]);

#endif /* SENSIRION_INCLUDES_SENSIRION_INTERFACE_H_ */
