#include "adc_defs.h"
#include "../common_defs.h"

typedef struct {
    uint8_t ADCLn;
    uint8_t ADCHn;
    uint8_t ADCSRAn;
    uint8_t ADCSRBn;
    uint8_t ADMUXn;
    uint8_t DIDR2n;
    uint8_t DIDR0n;
} adc_t;

#define ADC0 ((volatile adc_t*) ADC_BASE)

void adc_set_voltage_ref(volatile adc_t* adc, uint8_t mode);

void adc_reset_voltage_ref(volatile adc_t* adc);

void adc_enable_left_adjust_result(volatile adc_t* adc);

void adc_disable_left_adjust_result(volatile adc_t* adc);

void adc_set_analog_channel(volatile adc_t* adc, uint8_t mode);

void adc_enable(volatile adc_t* adc);

void adc_disable(volatile adc_t* adc);

void adc_start_conversion(volatile adc_t* adc);

void adc_auto_trigger_enable(volatile adc_t* adc);

void adc_enable_interrupt(volatile adc_t* adc);

void adc_disable_interrupt(volatile adc_t* adc);

void adc_set_prescaler(volatile adc_t* adc, uint8_t mode);

void adc_auto_trigger_source(volatile adc_t* adc, uint8_t mode);

void adc_digital_input_disable_0(volatile adc_t* adc, uint8_t mode);

void adc_digital_input_disable_2(volatile adc_t* adc, uint8_t mode);
