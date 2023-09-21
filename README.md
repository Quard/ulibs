# µLibs

Set of my libs for MCU. Some of them may not cover full functional of the device.

In general each lib consists of two parts, communication interface and logic. Such division is very handy for migration between different MCUs or frameworks, like STM32 HAL/LL or CMSIS. Most of the libs are already has the implemented interface that can be used as it is or as a reference for implementation own interface.

To use any of existing interfaces just rename interface files by deleting the suffix.

```sh
mv libname_interface_stm32hal.c libname_interface.c
mv libname_interface_stm32hal.h libname_interface.h
```
