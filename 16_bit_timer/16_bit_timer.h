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
} timer16bit_t;

typedef struct{
    uint8_t TIMSKn;
} timer16bit_interrupts_t;

typedef struct{
    uint8_t TIFRn;
} timer16bit_isr_flags_t;

typedef struct{
    uint8_t GTCCRn;
} timer16bit_sync_ctrl_t;


#define TIMER1 ((volatile timer16bit_t*) TIMER1_BASE)
#define TIMER3 ((volatile timer16bit_t*) TIMER3_BASE)
#define TIMER4 ((volatile timer16bit_t*) TIMER4_BASE)
#define TIMER5 ((volatile timer16bit_t*) TIMER5_BASE)

#define TIMER1_INTERRUPTS ((volatile timer16bit_interrupts_t*) TIMER1_ISR_BASE)
#define TIMER3_INTERRUPTS ((volatile timer16bit_interrupts_t*) TIMER3_ISR_BASE)
#define TIMER4_INTERRUPTS ((volatile timer16bit_interrupts_t*) TIMER4_ISR_BASE)
#define TIMER5_INTERRUPTS ((volatile timer16bit_interrupts_t*) TIMER5_ISR_BASE)

#define TIMER1_ISR_FLAGS ((volatile timer16bit_isr_flags_t*) TIMER1_ISR_FLAGS_BASE)
#define TIMER3_ISR_FLAGS ((volatile timer16bit_isr_flags_t*) TIMER3_ISR_FLAGS_BASE)
#define TIMER4_ISR_FLAGS ((volatile timer16bit_isr_flags_t*) TIMER4_ISR_FLAGS_BASE)
#define TIMER5_ISR_FLAGS ((volatile timer16bit_isr_flags_t*) TIMER5_ISR_FLAGS_BASE)

#define TIMER_SYNC_CTRL ((volatile timer16bit_sync_ctrl_t*) TIMER_SYNC_CTRL_BASE)

void timer16bit_set_prescaler(volatile timer16bit_t* timer, uint8_t mode);

uint16_t timer16bit_read_timer_value(volatile timer16bit_t* timer);

void timer16bit_set_timer_value(volatile timer16bit_t* timer, uint16_t value);

uint16_t timer16bit_read_output_compare_a(volatile timer16bit_t* timer);

void timer16bit_set_output_compare_a_value(volatile timer16bit_t* timer, uint16_t value);

uint16_t timer16bit_read_output_compare_b_value(volatile timer16bit_t* timer);

void timer16bit_set_output_compare_b_value(volatile timer16bit_t* timer, uint16_t value);

uint16_t timer16bit_read_output_compare_c_value(volatile timer16bit_t* timer);

void timer16bit_set_output_compare_c_value(volatile timer16bit_t* timer, uint16_t value);

uint16_t timer16bit_read_input_capture_value(volatile timer16bit_t* timer);

void timer16bit_set_input_capture_value(volatile timer16bit_t* timer, uint16_t value);

void timer16bit_input_capture_enable_interrupt(volatile timer16bit_interrupts_t* timer);

void timer16bit_output_compare_c_match_interrupt_enable(volatile timer16bit_interrupts_t* timer);

void timer16bit_output_compare_b_match_interrupt_enable(volatile timer16bit_interrupts_t* timer);

void timer16bit_output_compare_a_match_interrupt_enable(volatile timer16bit_interrupts_t* timer);

void timer16bit_overflow_interrupt_enable(volatile timer16bit_interrupts_t* timer);