# VEML6070

[Datasheet](https://datasheet.octopart.com/VEML6070-Vishay-datasheet-78835461.pdf)

UV A Light Sensor with I 2C Interface.

## Available interfaces

### Generic

File suffix: `generic`.

Generic implemenration of inferface that use two function for I2C communication:

`i2c1_write(uint8_t <I2C address>, uint8_t <data buffer>, uint8_t <data length>)`
`i2c1_read(uint8_t <I2C address>, uint8_t <data buffer>, uint8_t <data length>)`

## Example using

```c
uint16_t uv_level = 0,

veml6070_init(VEML6070_ACK_DISABLE, 0, VEML6070_IT_1T);
veml6070_read(&uv_level);
```
