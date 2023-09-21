/*
 * Copyright (c) 2023 Vadym Zakovinko
 *
 * SPDX-License-Identifier: MIT
 */

#include "max31865_interface.h"

extern SPI_HandleTypeDef hspi1;


void max31865_delay(uint32_t delay) {
	HAL_Delay(delay);
}

void max31865_select(void) {
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);
}

void max31865_deselect(void) {
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET);
}

int8_t max31865_read(uint8_t reg, uint8_t *buf, uint8_t len) {
	max31865_select();
	HAL_StatusTypeDef err = HAL_SPI_Transmit(&hspi1, &reg, 1, 5000);
	if (err != HAL_OK)
		return err;
	err = HAL_SPI_Receive(&hspi1, buf, len, 500);
	max31865_deselect();

	return err;
}

int8_t max31865_write(uint8_t reg, uint8_t *buf, uint8_t len) {
	max31865_select();
	HAL_StatusTypeDef err = HAL_SPI_Transmit(&hspi1, &reg, 1, 5000);
	if (err != HAL_OK)
		return err;
	err = HAL_SPI_Transmit(&hspi1, buf, len, 5000);
	max31865_deselect();

	return err;
}
