#include "twi_defs.h"
#include "../common_defs.h"

typedef struct{
    uint8_t TWBRn;
    uint8_t TWSRn;
    uint8_t TWARn;
    uint8_t TWDRn;
    uint8_t TWCRn;
    uint8_t TWAMRn;
} twi_t;

#define TWI ((volatile twi_t*) TWI_BASE)

void twi_set_bitrate(twi_t* twi, uint8_t byte);

void twi_enable_acknowledge_pulse(twi_t* twi);

void twi_disable_acknowledge_pulse(twi_t* twi);

void twi_enable_start_condition(twi_t* twi);

void twi_disable_start_condition(twi_t* twi);

void twi_enable_stop_condition(twi_t* twi);

void twi_enable(twi_t* twi);

void twi_disable(twi_t* twi);

void twi_enable_interrupt(twi_t* twi);

void twi_disable_interrupt(twi_t* twi);

uint8_t twi_check_status(twi_t* twi);

void twi_set_prescaler(twi_t* twi, uint8_t mode);

uint8_t twi_read_data(twi_t* twi);

void twi_write_data(twi_t* twi, uint8_t byte);

void twi_enable_general_call_rec(twi_t* twi);

void twi_set_address_mask(twi_t* twi, uint8_t mask);
