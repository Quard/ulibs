/*
 * Copyright (c) 2023 Vadym Zakovinko
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef __MAX31865_INTERFACE_H__
#define __MAX31865_INTERFACE_H__

#include "stm32g0xx_hal.h"

void max31865_delay(uint32_t delay);
void max31865_select(void);
void max31865_deselect(void);
int8_t max31865_read(uint8_t reg, uint8_t *buf, uint8_t len);
int8_t max31865_write(uint8_t reg, uint8_t *buf, uint8_t len);

#endif /* __MAX31865_INTERFACE_H__ */
