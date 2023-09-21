# Sensirion Interface

Common interface for different [Sensirion](sensirion.com/) sensors.

## Available interfaces

### Generic

File suffix: `generic`.

Generic implemenration of inferface that use two function for I2C communication:

`i2c1_write(uint8_t <I2C address>, uint8_t <data buffer>, uint8_t <data length>)`
`i2c1_read(uint8_t <I2C address>, uint8_t <data buffer>, uint8_t <data length>)`
