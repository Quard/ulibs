/*
 * Copyright (c) 2023 Vadym Zakovinko
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef __HP206_REGS_H__
#define __HP206_REGS_H__

#define HP206_I2C_ADDR  0xED

#define HP206_CMD_SOFT_RST   0x06
#define HP206_CMD_READ_PT    0x10
#define HP206_CMD_READ_AT    0x11
#define HP206_CMD_READ_P     0x30
#define HP206_CMD_READ_A     0x31
#define HP206_CMD_READ_T     0x32
#define HP206_CMD_ANA_CAL    0x28
#define HP206_CMD_READ_REG   0x80
#define HP206_CMD_WRITE_REG  0xC0

#define HP206_ADC_CVT_CHNL_Pos  0
#define HP206_ADC_CVT_OSR_Pos   2
#define HP206_ADC_CVT_CHNL_PT   0b00
#define HP206_ADC_CVT_CHNL_T    0b10
#define HP206_ADC_CVT_OSR_4096  0b000
#define HP206_ADC_CVT_OSR_2048  0b001
#define HP206_ADC_CVT_OSR_1024  0b010
#define HP206_ADC_CVT_OSR_512   0b011
#define HP206_ADC_CVT_OSR_256   0b100
#define HP206_ADC_CVT_OSR_128   0b101


#define HP206_REG_ALT_OFF_LSB  0x00
#define HP206_REG_ALT_OFF_MSB  0x01
#define HP206_REG_PA_H_TH_LSB  0x02
#define HP206_REG_PA_H_TH_MSB  0x03
#define HP206_REG_PA_M_TH_LSB  0x04
#define HP206_REG_PA_M_TH_MSB  0x05
#define HP206_REG_PA_L_TH_LSB  0x06
#define HP206_REG_PA_L_TH_MSB  0x07
#define HP206_REG_T_H_TH       0x08
#define HP206_REG_T_M_TH       0x09
#define HP206_REG_T_L_TH       0x10
#define HP206_REG_INT_EN       0x0B
#define HP206_REG_INT_CFG      0x0C
#define HP206_REG_INT_SRC      0x0D
#define HP206_REG_INT_DIR      0x0E
#define HP206_REG_PARA         0x0F


#endif /* __HP206_REGS_H__ */
