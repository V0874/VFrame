#include "ac.h"

void ac_set_multiplexer(volatile ac_t* ac, int multiplexer){
    uint8_t mask = 0x07;
    if(multiplexer == AC_NEGATIVE_INPUT_AIN1){
        ac->ADCSRBn &= ~AC_MULTIPLEXER_ENABLE;
        return;
    }
      ac->ADCSRBn |= AC_MULTIPLEXER_ENABLE;

     if(multiplexer <= 7){
        ac->ADCSRBn &= ~(1 << 3);
    } else {
        ac->ADCSRBn |= (1 << 3);
    }
        ac->ADMUXn &= ~mask;
        ac->ADMUXn |= (multiplexer & mask);
}

void ac_enable(volatile ac_ctrl_t* ac){
    ac->ACSRn &= ~AC_DISABLE;
}

void ac_disable(volatile ac_ctrl_t* ac){
    ac->ACSRn |= AC_DISABLE;
}

void ac_set_bandgap_fixed(volatile ac_ctrl_t* ac){
   ac->ACSRn |= AC_BANDGAP_SELECT;
}

void ac_set_bandgap_ain0(volatile ac_ctrl_t* ac){
    ac->ACSRn &= ~AC_BANDGAP_SELECT;
}

void ac_enable_interrupt(volatile ac_ctrl_t* ac){
    ac->ACSRn |= AC_INTERRUPT_ENABLE;
}

void ac_disable_interrupt(volatile ac_ctrl_t* ac){
    ac->ACSRn &= ~AC_INTERRUPT_ENABLE;
}

void ac_input_capture_enable(volatile ac_ctrl_t* ac){
    ac->ACSRn |= AC_INPUT_CAPTURE_ENABLE;
}

void ac_input_capture_disable(volatile ac_ctrl_t* ac){
    ac->ACSRn &= ~AC_INPUT_CAPTURE_ENABLE;
}

void ac_interrupt_mode_select(volatile ac_ctrl_t* ac, uint8_t mode){
    ac->ACSRn |= mode;
}

void ac_digital_input_disable(volatile ac_digi_input_t* ac, uint8_t ain_pin){
    ac->DIDRn |= ain_pin;
}