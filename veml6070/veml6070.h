/*
 * Copyright (c) 2023 Vadym Zakovinko
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef INC_VEML6070_H_
#define INC_VEML6070_H_

#include "veml6070_interface.h"

int8_t veml6070_init(uint8_t ack, uint8_t ack_thd, uint8_t it);
int8_t veml6070_read(uint16_t *uv_level);
int8_t veml6070_shutdown(void);

#endif /* INC_VEML6070_H_ */
