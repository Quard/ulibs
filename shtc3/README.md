# SHTC3

[Sensirion SHTC3](https://sensirion.com/products/catalog/SHTC3) temperature/humidity sensor.

## Available interfaces

Check [`sensirion_interface`](../sensirion_interface/) folder of this repository, to get the interface template and implementation.

## Example

```c
float temperature = 0, humidity = 0;

shtc3_wakeup();
shtc3_get_measurements(0, &temperature, &humidity);
shtc3_sleep();
```

## ToDo

* implement support of mode for `shtc3_get_measurements` function
