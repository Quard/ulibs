/*
 * Copyright (c) 2023 Vadym Zakovinko
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef __HP206_INTERFACE_H__
#define __HP206_INTERFACE_H__

#include "hp206_regs.h"

int8_t hp206_cmd(uint8_t cmd);
int8_t hp206_read8(uint8_t reg, uint8_t *value);
int8_t hp206_read(uint8_t reg, uint8_t *buf, uint8_t len);
int8_t hp206_read_reg(uint8_t reg, uint8_t *buf, uint8_t len);
int8_t hp206_write_reg(uint8_t reg, uint8_t value);

#endif /* __HP206_INTERFACE_H__ */
