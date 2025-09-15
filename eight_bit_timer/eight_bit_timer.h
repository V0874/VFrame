#include "eight_bit_timer_defs.h"
#include "../common_defs.h"

typedef struct {
    uint8_t TCCRnA;                                    
    uint8_t TCCRnB;                                    
    uint8_t TCNTn;                                    
    uint8_t OCRnA;                                
    uint8_t OCRnB;                                                                         
} timer8bit_t;

typedef struct {
    uint8_t TIMSKn;
} timer8bit_interrupts_t;

typedef struct {
    uint8_t TIFRn;
} timer8bit_isr_flags_t;

typedef struct {
    uint8_t ASSRn;
} timer8bit_async_status_t;

typedef struct {
    uint8_t GTCCRn;
} timer8bit_async_control_t;

#define TIMER0 ((volatile timer8bit_t*) TIMER0_BASE)                       
#define TIMER2 ((volatile timer8bit_t*) TIMER2_BASE)

#define TIMER0_INTERRUPTS ((volatile timer8bit_interrupts_t*) TIMER0_ISR_BASE)
#define TIMER2_INTERRUPTS ((volatile timer8bit_interrupts_t*) TIMER2_ISR_BASE)

#define TIMER0_ISR_FLAGS ((volatile timer8bit_isr_flags_t*) TIMER0_ISR_FLAGS_BASE)
#define TIMER2_ISR_FLAGS ((volatile timer8bit_isr_flags_t*) TIMER2_ISR_FLAGS_BASE)

#define TIMER2_ASYNC_STATUS ((volatile timer8bit_async_status_t*) TIMER2_ASYNC_STATUS_BASE)
#define TIMER2_ASYNC_CTRL ((volatile timer8bit_async_control_t*) TIMER2_ASYNC_CTRL_BASE)


void timer_set_comparematch_mode_a(volatile timer8bit_t* timer, uint8_t config);
void timer_set_comparematch_mode_b(volatile timer8bit_t* timer, uint8_t config);
void timer_force_output_compare_b(volatile timer8bit_t* timer);
void timer_force_output_compare_a(volatile timer8bit_t* timer);
void timer_set_prescaler(volatile timer8bit_t* timer, uint8_t config);
void timer_set_counter(volatile timer8bit_t* timer, uint8_t value);
uint8_t timer_read_counter(volatile timer8bit_t* timer);
void timer_set_output_compare_a(volatile timer8bit_t* timer, uint8_t value);
uint8_t timer_read_output_compare_a(volatile timer8bit_t* timer);
void timer_set_output_compare_b(volatile timer8bit_t* timer, uint8_t value);
uint8_t timer_read_output_compare_b(volatile timer8bit_t* timer);
void timer_enable_overflow_interrupt(volatile timer8bit_interrupts_t* timer);
void timer_disable_overflow_interrupt(volatile timer8bit_interrupts_t* timer);
void timer_enable_compmatch_a_interrupt(volatile timer8bit_interrupts_t* timer);
void timer_disable_compmatch_a_interrupt(volatile timer8bit_interrupts_t* timer);
void timer_enable_compmatch_b_interrupt(volatile timer8bit_interrupts_t* timer);
void timer_disable_compmatch_b_interrupt(volatile timer8bit_interrupts_t* timer);
void timer_enable_pwm_phasecorrect_mode(volatile timer8bit_t* timer);
void timer_enable_ctc_mode(volatile timer8bit_t* timer);
void timer_enable_fastpwm_mode(volatile timer8bit_t* timer);
void timer_enable_pwm_phasecorrect_ext_mode(volatile timer8bit_t* timer);
void timer_enable_fastpwm_ext_mode(volatile timer8bit_t* timer);
