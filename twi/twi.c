#include "twi.h"

void twi_set_bitrate(twi_t* twi, uint8_t byte){
    twi->TWBRn = byte;
}

void twi_enable_acknowledge_pulse(twi_t* twi){
    twi->TWCRn |= TWI_ENABLE_ACKNOWLEDGE_PULSE;
}

void twi_disable_acknowledge_pulse(twi_t* twi){ 
    twi->TWCRn &= ~TWI_ENABLE_ACKNOWLEDGE_PULSE;
}

void twi_enable_start_condition(twi_t* twi){
    twi->TWCRn |= TWI_START_CONDITION;
}

void twi_disable_start_condition(twi_t* twi){
    twi->TWCRn &= ~TWI_START_CONDITION;
}

void twi_enable_stop_condition(twi_t* twi){
    twi->TWCRn |= TWI_STOP_CONDITION;
}

void twi_enable(twi_t* twi){
    twi->TWCRn |= TWI_ENABLE;
}

void twi_disable(twi_t* twi){
    twi->TWCRn &= ~TWI_ENABLE;
}

void twi_enable_interrupt(twi_t* twi){
    twi->TWCRn |= TWI_INTERRUPT_ENABLE;
}

void twi_disable_interrupt(twi_t* twi){
    twi->TWCRn &= ~TWI_INTERRUPT_ENABLE;
}

uint8_t twi_check_status(twi_t* twi){
    uint8_t mask = 0xF8;
    uint8_t status = twi->TWSRn & mask;
    return status;
}

void twi_set_prescaler(twi_t* twi, uint8_t mode){
    twi->TWSRn |= mode;
}

uint8_t twi_read_data(twi_t* twi){
    return twi->TWDRn;
}

void twi_write_data(twi_t* twi, uint8_t byte){
    twi->TWDRn = byte;
}

void twi_set_slave_address(twi_t* twi, uint8_t address){
    twi->TWARn = (1 << address);
}

void twi_enable_general_call_rec(twi_t* twi){
    twi->TWARn |= TWI_GENERAL_CALL_REC_ENABLE;
}

void twi_set_address_mask(twi_t* twi, uint8_t mask){
    twi->TWAMRn = mask;
}
