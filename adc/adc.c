#include "adc.h"

void adc_set_voltage_ref(volatile adc_t* adc, uint8_t mode){
    adc->ADMUXn |= mode;
}

void adc_reset_voltage_ref(volatile adc_t* adc){
    adc->ADMUXn &= ~((1 << 6) | (1 << 7));
}

void adc_enable_left_adjust_result(volatile adc_t* adc){
    adc->ADMUXn |= ADC_LEFT_ADJUST_RESULT;
}

void adc_disable_left_adjust_result(volatile adc_t* adc){
    adc->ADMUXn &= ~ADC_LEFT_ADJUST_RESULT;
}

void adc_set_analog_channel(volatile adc_t* adc, uint8_t mode){
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

void adc_enable(volatile adc_t* adc){
    adc->ADCSRAn |= ADC_ENABLE;
}

void adc_disable(volatile adc_t* adc){
    adc->ADCSRAn &= ~ADC_ENABLE;
}

void adc_start_conversion(volatile adc_t* adc){
    adc->ADCSRAn |= ADC_START_CONVERSION;
}

void adc_auto_trigger_enable(volatile adc_t* adc){
    adc->ADCSRAn |= ADC_ENABLE_AUTO_TRIGGER;
}

void adc_enable_interrupt(volatile adc_t* adc){
    adc->ADCSRAn |= ADC_INTERRUPT_ENABLE;
}

void adc_disable_interrupt(volatile adc_t* adc){
    adc->ADCSRAn &= ~ADC_INTERRUPT_ENABLE;
}

void adc_set_prescaler(volatile adc_t* adc, uint8_t mode){
    adc->ADCSRAn |= mode;
}

void adc_auto_trigger_source(volatile adc_t* adc, uint8_t mode){
    adc->ADCSRBn |= mode;
}

void adc_digital_input_disable_0(volatile adc_t* adc, uint8_t mode){
    adc->DIDR0n |= mode;
}

void adc_digital_input_disable_2(volatile adc_t* adc, uint8_t mode){
    adc->DIDR2n |= mode;
}