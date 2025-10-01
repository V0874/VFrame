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

