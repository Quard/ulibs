/*
 * Copyright (c) 2023 Vadym Zakovinko
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef SHTC3_INCLUDES_SHTC3_H_
#define SHTC3_INCLUDES_SHTC3_H_

#include <sensirion_interface.h>

#define SHTC3_ADDR (0x70 << 1)

#define SHTC3_CMD_ID                          0xEFC8
#define SHTC3_CMD_SLEEP                       0xB098
#define SHTC3_CMD_WAKEUP                      0x3517
#define SHTC3_CMD_SOFT_RESET                  0x805D
#define SHTC3_CMD_MEAS_NORMAL_CS_EN_T_FIRST   0x7CA2
#define SHTC3_CMD_MEAS_NORMAL_CS_EN_H_FIRST   0x5C24
#define SHTC3_CMD_MEAS_NORMAL_CS_DIS_T_FIRST  0x7866
#define SHTC3_CMD_MEAS_NORMAL_CS_DIS_H_FIRST  0x58E0
#define SHTC3_CMD_MEAS_LOWPWR_CS_EN_T_FIRST   0x6458
#define SHTC3_CMD_MEAS_LOWPWR_CS_EN_H_FIRST   0x44DE
#define SHTC3_CMD_MEAS_LOWPWR_CS_DIS_T_FIRST  0x609C
#define SHTC3_CMD_MEAS_LOWPWR_CS_DIS_H_FIRST  0x401A

int8_t shtc3_wakeup(void);
int8_t shtc3_sleep(void);
int8_t shtc3_id(uint16_t *id);
int8_t shtc3_soft_reset(void);
int8_t shtc3_get_measurements(uint8_t mode, float *temperature, float *humidity);

#endif /* SHTC3_INCLUDES_SHTC3_H_ */
