#include "spi.h"

void spi_enable_interrupt(volatile spi_t* spi){
    spi->SPCRn |= SPI_INTERRUPT_ENABLE;
}

void spi_disable_interrupt(volatile spi_t* spi){
    spi->SPCRn &= ~SPI_INTERRUPT_ENABLE;
}

void spi_enable(volatile spi_t* spi){
    spi->SPCRn |= SPI_ENABLE;
}

void spi_disable(volatile spi_t* spi){   
    spi->SPCRn &= ~SPI_ENABLE;
}

void spi_set_data_order(volatile spi_t* spi, uint8_t mode){
    if(mode == 0){
        spi->SPCRn &= ~SPI_DATA_ORDER_SELECT;
    } else {
        spi->SPCRn |= SPI_DATA_ORDER_SELECT;
    }
}

void spi_set_master_mode(volatile spi_t* spi, uint8_t mode){
    if(mode == 0){
        spi->SPCRn &= ~SPI_MASTER_SLAVE_SELECT;
    } else {
        spi->SPCRn |= SPI_MASTER_SLAVE_SELECT;
    }
}

void spi_set_clock_polarity(volatile spi_t* spi, uint8_t mode){
    if(mode == 0){
        spi->SPCRn &= ~SPI_CLOCK_POLARITY_SELECT;
    } else {
        spi->SPCRn |= SPI_CLOCK_POLARITY_SELECT;
    }
}

void spi_set_clock_phase(volatile spi_t* spi, uint8_t mode){
    if(mode == 0){
        spi->SPCRn &= ~SPI_CLOCK_PHASE_SELECT;
    } else {
        spi->SPCRn |= SPI_CLOCK_PHASE_SELECT;
    }
}

void spi_set_clock_rate(volatile spi_t* spi, uint8_t mode){
    spi->SPCRn |= mode;
}

void spi_set_double_speed(volatile spi_t* spi){
    spi->SPSRn |= SPI_DOUBLE_SPEED_ENABLE;
}
