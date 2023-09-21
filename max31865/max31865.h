/*
 * Copyright (c) 2023 Vadym Zakovinko
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef __MAX31865_H__
#define __MAX31865_H__

#include <math.h>
#include "max31865_interface.h"

#define MAX31865_REG_CONFIGURATION  0x00
#define MAX31865_REG_RTD_MSB        0x01
#define MAX31865_REG_RTD_LSB        0x02
#define MAX31865_REG_HFT_MSB        0x03
#define MAX31865_REG_HFT_LSB        0x04
#define MAX31865_REG_LFT_MSB        0x05
#define MAX31865_REG_LFT_LSB        0x06
#define MAX31865_REG_FAULT_STATUS   0x07

#define MAX31865_CONFIG_VBIAS_ON                  0b1
#define MAX31865_CONFIG_VBIAS_OFF                 0b0
#define MAX31865_CONFIG_CONVERSION_AUTO           0b1
#define MAX31865_CONFIG_CONVERSION_OFF            0b0
#define MAX31865_CONFIG_3WIRE                     0b1
#define MAX31865_CONFIG_2WIRE                     0b0
#define MAX31865_CONFIG_4WIRE                     0b0
#define MAX31865_CONFIG_FDCC_NO_ACTION            0b00
#define MAX31865_CONFIG_FDCC_AUTO_DELAY           0b01
#define MAX31865_CONFIG_FDCC_RUN_MANUAL_DELAY     0b10
#define MAX31865_CONFIG_FDCC_FINISH_MANUAL_DELAY  0b11
#define MAX31865_CONFIG_FILTER_50HZ               0b1
#define MAX31865_CONFIG_FILTER_60HZ               0b0

#define MAX31865_A  3.90830e-3
#define MAX31865_B  -5.775e-7

typedef union {
	struct {
		uint8_t filter             : 1;
		uint8_t fault_status_clear : 1;
		uint8_t fdcc               : 2;  // Fault Detection Cycle Control
		uint8_t three_wire         : 1;
		uint8_t one_shot           : 1;
		uint8_t conversion_mode    : 1;
		uint8_t vbias              : 1;
	};
	uint8_t conf;
} MAX31865_Configuration_t;

int8_t max31865_set_config(MAX31865_Configuration_t *conf);
int8_t max31865_get_config(MAX31865_Configuration_t *conf);
int8_t max31865_set_thresholds(uint16_t low, uint16_t high);
int8_t max31865_get_thresholds(uint16_t *low, uint16_t *high);
int8_t max31865_one_shot(uint16_t *rtd);
int8_t max31865_read_rtd(uint16_t *rtd);
float max31865_calc_temperature(uint16_t rtd, uint16_t nominal, uint16_t rref);
int8_t max31865_read_fault_status(uint8_t *status);

#endif /* __MAX31865_H__ */
