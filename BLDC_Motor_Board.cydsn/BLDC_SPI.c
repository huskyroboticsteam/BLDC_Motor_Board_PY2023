// read fault
// TMC6100_SPI_read();
#include <project.h>

uint32 dataToSend;

void read_spi() {
    
    TMC6100_SPI_Start();
    
    TMC6100_SPI_SpiUartWriteTxData(dataToSend);
    
    
    CyDelay(1000);
    TMC6100_SPI_Stop();
}