/*
 * Copyright (c) 2023 Vadym Zakovinko
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef __HP206_H__
#define __HP206_H__

#include "hp206_interface.h"
#include "hp206_regs.h"


int8_t hp206_init(uint8_t compensation);
int8_t hp206_start(uint8_t chnl, uint8_t osr);
int8_t hp206_read_p(uint32_t *pressure);
int8_t hp206_read_pt(uint32_t *temp, uint32_t *pressure);
int8_t hp206_get_interrupts(uint8_t *value);


#endif /* __HP206_H__ */
