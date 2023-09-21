# MAX31865

Need to implement communication functions in `max31865_interface.c` according to used MCU.

## Available interfaces

### STM32 HAL

File suffix: `stm32hal`.

## Example using STM32 with HAL

```c
uint8_t fault_status;
uint16_t rtd;
float temp;
uint8_t buf[100] = {'\0'};

HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET);

MAX31865_Configuration_t conf = {.three_wire = 1};
max31865_set_config(&conf);
max31865_set_thresholds(0, 0xFFFF);

max31865_one_shot(&rtd);
max31865_read_fault_status(&fault_status);
// 100 for PT100 (1000 for PT1000)
// 430 is a REF resistor on a board
temp = max31865_calc_temperature(rtd, 100, 430);

sprintf((char *)buf, "temp: %0.2f C\r\nstatus: %d\r\n ******* \r\n", temp, fault_status);
HAL_UART_Transmit(&huart2, buf, strlen((char *)buf), 500);
```
