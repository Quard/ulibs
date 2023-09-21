# SEN5x

Set of particulate matter sensors from Sensirion.

* [SEN50](https://sensirion.com/products/catalog/SEN50) - Environmental sensor node for _PM_ measurements
* [SEN54](https://sensirion.com/products/catalog/SEN54) - Environmental sensor node for _PM, RH/T, VOC_ measurements
* [SEN55](https://sensirion.com/products/catalog/SEN55) - Environmental sensor node for _PM, RH/T, VOC, NOx_ measurements

## Available interfaces

Check [`sensirion_interface`](../sensirion_interface/) folder of this repository, to get the interface template and implementation.

## Example using SEN50 sensor

```c
uint16_t pm10 = 0, pm25 = 0, pm40 = 0, pm100 = 0;
uint8_t sen5x_data_ready = 0;

sen5x_start_measurement(SEN5X_CMD_START_MEAS);

while (sen5x_data_ready == 0) {
    if (sen5x_is_data_ready(&sen5x_data_ready) != 0) break;
    // sleep
}

if (sen5x_data_ready) {
    sen5x_read_data(&pm10, &pm25, &pm40, &pm100);
}
```
