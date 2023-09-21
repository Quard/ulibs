/*
 * Copyright (c) 2023 Vadym Zakovinko
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef __SEN5X_H__
#define __SEN5X_H__

#include <sensirion_interface.h>

#define SEN5X_ADDR (0x69 << 1)

#define SEN5X_CMD_START_MEAS              0x0021
#define SEN5X_CMD_START_MEAS_RTH_GAS      0x0037
#define SEN5X_CMD_STOP_MES                0x0104
#define SEN5X_CMD_READ_DATA_READY_FLG     0x0202
#define SEN5X_CMD_READ_MEAS_VALUES        0x03C4
#define SEN5X_CMD_TEMP_COMPENSATION       0x60B2
#define SEN5X_CMD_WARM_START_PARAMS       0x60C6
#define SEN5X_CMD_VOC_TUNING_PARAMS       0x60D0
#define SEN5X_CMD_NOX_TINING_PARAMS       0x60E1
#define SEN5X_CMD_RHT_ACCEL_MODE          0x60F7
#define SEN5X_CMD_VOC_ALGO_STATE          0x6181
#define SEN5X_CMD_START_FAN_CLEANING      0x5607
#define SEN5X_CMD_AUTO_CLEANING_INTERVAL  0x8004
#define SEN5X_CMD_PRODUCT_NAME            0xD014
#define SEN5X_CMD_SERIAL_NUMBER           0xD033
#define SEN5X_CMD_FIRMWARE_VERSION        0xD100
#define SEN5X_CMD_DEVICE_STATUS           0xD206
#define SEN5X_CMD_CLEAR_DEVICE_STATUS     0xD210
#define SEN5X_CMD_RESET                   0xD304


int8_t sen5x_start_measurement(uint16_t mode);
int8_t sen5x_read_data(uint16_t *pm10, uint16_t *pm25, uint16_t *pm40, uint16_t *pm100);
int8_t sen5x_is_data_ready(uint8_t *ready);

#endif /* __SEN5X_H__ */
