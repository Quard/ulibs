/*
 * Copyright (c) 2023 Vadym Zakovinko
 *
 * SPDX-License-Identifier: MIT
 */

#include "max31865.h"


int8_t max31865_set_config(MAX31865_Configuration_t *conf) {
	return max31865_write(MAX31865_REG_CONFIGURATION | 0x80, (uint8_t *)conf, 1);
}

int8_t max31865_get_config(MAX31865_Configuration_t *conf) {
	return max31865_read(MAX31865_REG_CONFIGURATION, (uint8_t *)conf, 1);
}

int8_t max31865_set_thresholds(uint16_t low, uint16_t high) {
	uint8_t buf[2];

	buf[0] = low >> 8;
	buf[1] = low & 0xFF;
	int8_t err = max31865_write(MAX31865_REG_LFT_MSB | 0x80, buf, 2);
	if (err != 0) return err;

	buf[0] = high >> 8;
	buf[1] = high & 0xFF;
	return max31865_write(MAX31865_REG_HFT_MSB | 0x80, buf, 2);
}

int8_t max31865_get_thresholds(uint16_t *low, uint16_t *high) {
	int8_t err;
	uint8_t buf[2];

	err = max31865_read(MAX31865_REG_LFT_MSB, buf, 2);
	if (err != 0) return err;
	*low = (buf[0] << 8) | buf[1];

	err = max31865_read(MAX31865_REG_HFT_MSB, buf, 2);
	if (err != 0) return err;
	*high = (buf[0] << 8) | buf[1];

	return err;
}

int8_t max31865_one_shot(uint16_t *rtd) {
	MAX31865_Configuration_t conf;

	int8_t err = max31865_get_config(&conf);
	if (err != 0) return err;

	conf.conversion_mode = MAX31865_CONFIG_CONVERSION_OFF;
	conf.fault_status_clear = 1;
	conf.one_shot = 0;
	conf.fdcc = MAX31865_CONFIG_FDCC_NO_ACTION;
	max31865_set_config(&conf);
	if (err != 0) return err;

	conf.vbias = MAX31865_CONFIG_VBIAS_ON;
	max31865_set_config(&conf);
	if (err != 0) return err;
	max31865_delay(10);

	conf.one_shot = 1;
	max31865_set_config(&conf);
	if (err != 0) return err;
	max31865_delay(65);

	err = max31865_read_rtd(rtd);

	conf.vbias = MAX31865_CONFIG_VBIAS_OFF;
	err &= max31865_set_config(&conf);

	return err;
}

float max31865_calc_temperature(uint16_t rtd, uint16_t nominal, uint16_t rref) {
	float t1, t2, t3, t4, rt, temp;

	rt = rtd / 32768.0f * (float)rref;

	t1 = -MAX31865_A;
	t2 = MAX31865_A * MAX31865_A - (4 * MAX31865_B);
	t3 = (4 * MAX31865_B) / (float)nominal;
	t4 = 2 * MAX31865_B;

	temp = (sqrt(t2 + (t3 * rt)) + t1) / t4;

	if (temp >= 0) return temp;

	// normalize to 100 Ohm
	rt = rt / (float)nominal * 100;

	float rpoly = rt;

	temp = -242.02 + 2.2228 * rpoly;
	rpoly *= rpoly;
	temp += 2.5859e-3 * rpoly;
	rpoly *= rpoly;
	temp -= 4.8260e-6 * rpoly;
	rpoly *= rpoly;
	temp -= 2.8183e-8 * rpoly;
	rpoly *= rpoly;
	temp += 1.5243e-10 * rpoly;

	return temp;
}

int8_t max31865_read_rtd(uint16_t *rtd) {
	int8_t err;
	uint8_t buf[2];

	err = max31865_read(MAX31865_REG_RTD_MSB, buf, 2);
	*rtd = ((buf[0] << 8) | buf[1]) >> 1;

	return err;
}

int8_t max31865_read_fault_status(uint8_t *status) {
	return max31865_read(MAX31865_REG_FAULT_STATUS, status, 1);
}
