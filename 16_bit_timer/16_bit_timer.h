#include "16_bit_timer_defs.h"
#include "../common_defs.h"

typedef struct{
    uint8_t TCCRnA;
    uint8_t TCCRnB;
    uint8_t TCCRnC;
    uint8_t _RESERVED_;
    uint8_t TCNTnL;
    uint8_t TCNTnH;
    uint8_t ICRnL;
    uint8_t ICRnH;
    uint8_t OCRnAL;
    uint8_t OCRnAH;
    uint8_t OCRnBL;
    uint8_t OCRnBH;
    uint8_t OCRnCL;
    uint8_t OCRnCH;
} timer_16bit_t;

typedef struct{
    uint8_t TIMSKn;
} timer_16bit_interrupts_t;

typedef struct{
    uint8_t TIFRn;
} timer_16bit_isr_flags_t;

typedef struct{
    uint8_t GTCCRn;
} timer_16bit_sync_ctrl_t;


#define TIMER1 ((volatile timer_16bit_t*) TIMER1_BASE)
#define TIMER3 ((volatile timer_16bit_t*) TIMER3_BASE)
#define TIMER4 ((volatile timer_16bit_t*) TIMER4_BASE)
#define TIMER5 ((volatile timer_16bit_t*) TIMER5_BASE)

#define TIMER1_INTERRUPTS ((volatile timer_16bit_interrupts_t*) TIMER1_ISR_BASE)
#define TIMER3_INTERRUPTS ((volatile timer_16bit_interrupts_t*) TIMER3_ISR_BASE)
#define TIMER4_INTERRUPTS ((volatile timer_16bit_interrupts_t*) TIMER4_ISR_BASE)
#define TIMER5_INTERRUPTS ((volatile timer_16bit_interrupts_t*) TIMER5_ISR_BASE)

#define TIMER1_ISR_FLAGS ((volatile timer_16bit_isr_flags_t*) TIMER1_ISR_FLAGS_BASE)
#define TIMER3_ISR_FLAGS ((volatile timer_16bit_isr_flags_t*) TIMER3_ISR_FLAGS_BASE)
#define TIMER4_ISR_FLAGS ((volatile timer_16bit_isr_flags_t*) TIMER4_ISR_FLAGS_BASE)
#define TIMER5_ISR_FLAGS ((volatile timer_16bit_isr_flags_t*) TIMER5_ISR_FLAGS_BASE)

#define TIMER_SYNC_CTRL ((volatile timer_16bit_sync_ctrl_t*) TIMER_SYNC_CTRL_BASE)

