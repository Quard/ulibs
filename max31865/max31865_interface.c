/*
 * Copyright (c) 2023 Vadym Zakovinko
 *
 * SPDX-License-Identifier: MIT
 */

#include "max31865_interface.h"


void max31865_delay(uint32_t delay) {
	// implement delay in micro seconds
}

void max31865_select(void) {
	// activate CS pin
}

void max31865_deselect(void) {
	// deactivate CS pin
}

int8_t max31865_read(uint8_t reg, uint8_t *buf, uint8_t len) {
	max31865_select();
	// implement read
	max31865_deselect();

	return err;
}

int8_t max31865_write(uint8_t reg, uint8_t *buf, uint8_t len) {
	max31865_select();
	// implement write
	max31865_deselect();

	return err;
}
