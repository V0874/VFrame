#include "spi_defs.h"
#include "../common_defs.h"

typedef struct{
    uint8_t SPCRn;
    uint8_t SPSRn;
    uint8_t SPDRn;
} spi_t;

#define SPI ((volatile spi_t*) SPI_BASE)

void spi_enable_interrupt(volatile spi_t* spi);

void spi_disable_interrupt(volatile spi_t* spi);

void spi_enable(volatile spi_t* spi);

void spi_disable(volatile spi_t* spi);

void spi_set_data_order(volatile spi_t* spi, uint8_t mode);

void spi_set_master_slave_mode(volatile spi_t* spi, uint8_t mode);

void spi_set_clock_polarity(volatile spi_t* spi, uint8_t mode);

void spi_set_clock_phase(volatile spi_t* spi, uint8_t mode);

void spi_set_clock_rate(volatile spi_t* spi, uint8_t mode);

void spi_set_double_speed(volatile spi_t* spi);
