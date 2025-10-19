#include "twi.h"

void twi_set_bitrate(volatile twi_t* twi, uint8_t byte){
    twi->TWBRn = byte;
}

void twi_enable_acknowledge_pulse(volatile twi_t* twi){
    twi->TWCRn |= TWI_ENABLE_ACKNOWLEDGE_PULSE;
}

void twi_disable_acknowledge_pulse(volatile twi_t* twi){ 
    twi->TWCRn &= ~TWI_ENABLE_ACKNOWLEDGE_PULSE;
}

void twi_enable_start_condition(volatile twi_t* twi){
    twi->TWCRn |= TWI_START_CONDITION;
}

void twi_disable_start_condition(volatile twi_t* twi){
    twi->TWCRn &= ~TWI_START_CONDITION;
}

void twi_enable_stop_condition(volatile twi_t* twi){
    twi->TWCRn |= TWI_STOP_CONDITION;
}

void twi_enable(volatile twi_t* twi){
    twi->TWCRn |= TWI_ENABLE;
}

void twi_disable(volatile twi_t* twi){
    twi->TWCRn &= ~TWI_ENABLE;
}

void twi_enable_interrupt(volatile twi_t* twi){
    twi->TWCRn |= TWI_INTERRUPT_ENABLE;
}

void twi_disable_interrupt(volatile twi_t* twi){
    twi->TWCRn &= ~TWI_INTERRUPT_ENABLE;
}

uint8_t twi_check_status(volatile twi_t* twi){
    uint8_t mask = 0xF8;
    uint8_t status = twi->TWSRn & mask;
    return status;
}

void twi_set_prescaler(volatile twi_t* twi, uint8_t mode){
    twi->TWSRn |= mode;
}

uint8_t twi_read_data(volatile twi_t* twi){
    return twi->TWDRn;
}

void twi_write_data(volatile twi_t* twi, uint8_t byte){
    twi->TWDRn = byte;
}

void twi_set_slave_address(volatile twi_t* twi, uint8_t address){
    twi->TWARn = (1 << address);
}

void twi_enable_general_call_rec(volatile twi_t* twi){
    twi->TWARn |= TWI_GENERAL_CALL_REC_ENABLE;
}

void twi_set_address_mask(volatile twi_t* twi, uint8_t mask){
    twi->TWAMRn = mask;
}
