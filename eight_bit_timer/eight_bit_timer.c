#include "eight_bit_timer.h"

void timer_set_compareoutput_mode_ca(volatile timer8bit_t* timer, uint8_t config){
    timer->TCCRnA |= config;
}

void timer_set_compareoutput_mode_b(volatile timer8bit_t* timer, uint8_t config){
    timer->TCCRnA |= config;
}

void timer_force_output_compare_b(volatile timer8bit_t* timer){
    timer->TCCRnB |= FORCE_OUTPUT_COMPARE_B;
}

void timer_force_output_compare_a(volatile timer8bit_t* timer){
    timer->TCCRnB |= FORCE_OUTPUT_COMPARE_A;
}

void timer_set_prescaler(volatile timer8bit_t* timer, uint8_t config){
    timer->TCCRnB |= config;
}
uint8_t timer_read_counter(volatile timer8bit_t* timer){
    return timer->TCNTn;
}

void timer_set_counter(volatile timer8bit_t* timer, uint8_t value){
    timer->TCNTn = value;
}

uint8_t timer_read_output_compare_a(volatile timer8bit_t* timer){
    return timer->OCRnA;
}

void timer_set_output_compare_a(volatile timer8bit_t* timer, uint8_t value){
    timer->OCRnA = value;
}

uint8_t timer_read_output_compare_b(volatile timer8bit_t* timer){
    return timer->OCRnB;
}

void timer_set_output_compare_b(volatile timer8bit_t* timer, uint8_t value){
    timer->OCRnB = value;
}


void timer_enable_overflow_interrupt(volatile timer8bit_interrupts_t* timer){
    timer->TIMSKn |= TIMER_OVERFLOW_INTERRUPT_ENABLE;
}

void timer_disable_overflow_interrupt(volatile timer8bit_interrupts_t* timer){
    timer->TIMSKn &= ~TIMER_OVERFLOW_INTERRUPT_ENABLE;
}

void timer_enable_compmatch_a_interrupt(volatile timer8bit_interrupts_t* timer){
    timer->TIMSKn |= TIMER_OUTPUT_COMPMATCH_A_INTERRUPT_ENABLE;
}

void timer_disable_compmatch_a_interrupt(volatile timer8bit_interrupts_t* timer){
    timer->TIMSKn &= ~TIMER_OUTPUT_COMPMATCH_A_INTERRUPT_ENABLE;
}

void timer_enable_compmatch_b_interrupt(volatile timer8bit_interrupts_t* timer){
    timer->TIMSKn |= TIMER_OUTPUT_COMPMATCH_B_INTERRUPT_ENABLE;
}

void timer_disable_compmatch_b_interrupt(volatile timer8bit_interrupts_t* timer){
    timer->TIMSKn &= ~TIMER_OUTPUT_COMPMATCH_B_INTERRUPT_ENABLE;
}

void timer_enable_pwm_phasecorrect_mode(volatile timer8bit_t* timer){
    timer->TCCRnA |= PWM_PHASE_CORRECT_MODE;
}

void timer_enable_ctc_mode(volatile timer8bit_t* timer){
    timer->TCCRnA |= CTC_MODE;
}

void timer_enable_fastpwm_mode(volatile timer8bit_t* timer){
    timer->TCCRnA |= FAST_PWM_MODE;
}

void timer_enable_pwm_phasecorrect_ext_mode(volatile timer8bit_t* timer){
    timer->TCCRnA |= PWM_PHASE_CORRECT_MODE;
    timer->TCCRnB |= PWM_PHASE_CORRECT_EXT_MODE;
}

void timer_enable_fastpwm_ext_mode(volatile timer8bit_t* timer){
    timer->TCCRnA |= FAST_PWM_MODE;
    timer->TCCRnB |= FAST_PWM_EXT_MODE;
}

void timer_init(volatile timer8bit_t* timer){
    timer_enable_fastpwm_ext_mode(TIMER0);
    timer_set_output_compare_a(TIMER0, 255);
    timer_set_prescaler(timer, TIMER_1024PRESCALER);
    timer_set_comparematch_mode_a(TIMER0, TIMER_TOGGLE_OUTPUT_COMPARE_PINA);
}
