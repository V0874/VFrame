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

#define ADC ((volatile adc_t*) ADC_BASE)

void select_reference_bits(adc_t* adc, uint8_t mode);

void reset_reference_bits(adc_t* adc);

void enable_left_adjust_result(adc_t* adc);

void disable_left_adjust_result(adc_t* adc);

void set_analog_channel_gain_select(adc_t* adc, uint8_t mode);

