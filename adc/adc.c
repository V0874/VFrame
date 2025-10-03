#include "adc.h"

void select_reference_bits(adc_t* adc, uint8_t mode){
    adc->ADMUXn |= mode;
}

void reset_reference_bits(adc_t* adc){
    adc->ADMUXn &= ~((1 << 6) | (1 << 7));
}

void enable_left_adjust_result(adc_t* adc){
    adc->ADMUXn |= ADC_LEFT_ADJUST_RESULT;
}

void disable_left_adjust_result(adc_t* adc){
    adc->ADMUXn &= ~ADC_LEFT_ADJUST_RESULT;
}

void set_analog_channel_gain_select(adc_t* adc, uint8_t mode){
    uint8_t mask = 0x1F;
    if (mode & (1 << 5)){
        uint8_t mux_bits = mode & mask;
        adc->ADCSRBn |= (1 << 3);
        adc->ADMUXn &= ~mask;
        adc->ADMUXn |= mux_bits;
    } else {
            adc->ADCSRBn &= ~(1 << 3);
            adc->ADMUXn &= ~mask;
            adc->ADMUXn |= mode;
    }
}