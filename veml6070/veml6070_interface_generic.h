/*
 * Copyright (c) 2023 Vadym Zakovinko
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef __VEML6070_INCLUDES_VEML6070_INTERFACE_H__
#define __VEML6070_INCLUDES_VEML6070_INTERFACE_H__

#include "main.h"
#include "veml6070_regs.h"

int8_t veml6070_write8(uint8_t value);
int8_t veml6070_read16(uint16_t *value);

#endif /* __VEML6070_INCLUDES_VEML6070_INTERFACE_H__ */
