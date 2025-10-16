#include "spi_defs.h"
#include "../common_defs.h"

typedef struct{
    uint8_t SPCRn;
    uint8_t SPSRn;
    uint8_t SPDRn;
} spi_t;

#define SPI ((volatile spi_t*) SPI_BASE)

void spi_enable_interrupt(spi_t* spi);

void spi_disable_interrupt(spi_t* spi);

void spi_enable(spi_t* spi);

void spi_disable(spi_t* spi);

void spi_set_data_order(spi_t* spi, uint8_t mode);

void spi_set_master_slave_mode(spi_t* spi, uint8_t mode);

void spi_set_clock_polarity(spi_t* spi, uint8_t mode);

void spi_set_clock_phase(spi_t* spi, uint8_t mode);

void spi_set_clock_rate(spi_t* spi, uint8_t mode);

void spi_set_double_speed(spi_t* spi);
