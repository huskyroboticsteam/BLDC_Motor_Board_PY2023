// read fault
// TMC6100_SPI_read();
#include <project.h>

// uint32 dataToSend;

uint32 read_spi(uint8 address, uint32 dataToSend) {
    uint8 data[5];
    data[0] = address;
    data[1] = (dataToSend & 0xFF000000) >> 24;
    data[2] = (dataToSend & 0x00FF0000) >> 16;
    data[3] = (dataToSend & 0x0000FF00) >> 8;
    data[4] = (dataToSend & 0x000000FF);
    
    TMC6100_SpiUartPutArray(data, 5);
    
    
    TMC6100_SpiUartWriteTxData(0);
    TMC6100_SpiUartWriteTxData(0);
    TMC6100_SpiUartWriteTxData(0);
    TMC6100_SpiUartWriteTxData(0);
    
    uint32 res = 0;
    res |= TMC6100_SpiUartReadRxData();
    res <<= 8;
    res |= TMC6100_SpiUartReadRxData();
    res <<= 8;
    res |= TMC6100_SpiUartReadRxData();
    res <<= 8;
    res |= TMC6100_SpiUartReadRxData();
    
    return res;
    
    // TMC6100_SPI_SpiUartWriteTxData(dataToSend);
}