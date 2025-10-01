
#define ADC_BASE (0x78UL)

#define ADC_AVCC_EXTCAP                     (1 << 6)
#define ADC_INTERNAL_1_1_VOLT_REF_EXTCAP    (1 << 7) 
#define ADC_INTERNAL_2_56_VOLT_REF_EXTCAP   (1 << 6) | (1 << 7)

#define ADC_LEFT_ADJUST_RESULT              (1 << 5)

#define ADC_ENABLE                          (1 << 7)