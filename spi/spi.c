#include "spi.h"

void spi_enable_interrupt(spi_t* spi){
    spi->SPCRn |= SPI_INTERRUPT_ENABLE;
}

void spi_disable_interrupt(spi_t* spi){
    spi->SPCRn &= ~SPI_INTERRUPT_ENABLE;
}

void spi_enable(spi_t* spi){
    spi->SPCRn |= SPI_ENABLE;
}

void spi_disable(spi_t* spi){   
    spi->SPCRn &= ~SPI_ENABLE;
}

void spi_set_data_order(spi_t* spi, uint8_t mode){
    if(mode == 0){
        spi->SPCRn &= ~SPI_DATA_ORDER_SELECT;
    } else {
        spi->SPCRn |= SPI_DATA_ORDER_SELECT;
    }
}

void spi_set_master_mode(spi_t* spi, uint8_t mode){
    if(mode == 0){
        spi->SPCRn &= ~SPI_MASTER_SLAVE_SELECT;
    } else {
        spi->SPCRn |= SPI_MASTER_SLAVE_SELECT;
    }
}

void spi_set_clock_polarity(spi_t* spi, uint8_t mode){
    if(mode == 0){
        spi->SPCRn &= ~SPI_CLOCK_POLARITY_SELECT;
    } else {
        spi->SPCRn |= SPI_CLOCK_POLARITY_SELECT;
    }
}

void spi_set_clock_phase(spi_t* spi, uint8_t mode){
    if(mode == 0){
        spi->SPCRn &= ~SPI_CLOCK_PHASE_SELECT;
    } else {
        spi->SPCRn |= SPI_CLOCK_PHASE_SELECT;
    }
}

void spi_set_clock_rate(spi_t* spi, uint8_t mode){
    spi->SPCRn |= mode;
}

void spi_set_double_speed(spi_t* spi){
    spi->SPSRn |= SPI_DOUBLE_SPEED_ENABLE;
}
