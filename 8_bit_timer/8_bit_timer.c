#include "8_bit_timer.h"

void timer8bit_set_compareoutput_mode_a(volatile timer8bit_t* timer, uint8_t config){
    timer->TCCRnA |= config;
}

void timer8bit_set_compareoutput_mode_b(volatile timer8bit_t* timer, uint8_t config){
    timer->TCCRnA |= config;
}

void timer8bit_force_output_compare_b(volatile timer8bit_t* timer){
    timer->TCCRnB |= FORCE_OUTPUT_COMPARE_B;
}

void timer8bit_force_output_compare_a(volatile timer8bit_t* timer){
    timer->TCCRnB |= FORCE_OUTPUT_COMPARE_A;
}

void timer8bit_set_prescaler(volatile timer8bit_t* timer, uint8_t config){
    timer->TCCRnB |= config;
}

uint8_t timer8bit_read_counter_value(volatile timer8bit_t* timer){
    return timer->TCNTn;
}

void timer8bit_set_counter_value(volatile timer8bit_t* timer, uint8_t value){
    timer->TCNTn = value;
}

uint8_t timer8bit_read_output_compare_a_value(volatile timer8bit_t* timer){
    return timer->OCRnA;
}

void timer8bit_set_output_compare_a_value(volatile timer8bit_t* timer, uint8_t value){
    timer->OCRnA = value;
}

uint8_t timer8bit_read_output_compare_b_value(volatile timer8bit_t* timer){
    return timer->OCRnB;
}

void timer8bit_set_output_compare_b_value(volatile timer8bit_t* timer, uint8_t value){
    timer->OCRnB = value;
}


void timer8bit_enable_overflow_interrupt(volatile timer8bit_interrupts_t* timer){
    timer->TIMSKn |= TIMER_OVERFLOW_INTERRUPT_ENABLE;
}

void timer8bit_disable_overflow_interrupt(volatile timer8bit_interrupts_t* timer){
    timer->TIMSKn &= ~TIMER_OVERFLOW_INTERRUPT_ENABLE;
}

void timer8bit_enable_compmatch_a_interrupt(volatile timer8bit_interrupts_t* timer){
    timer->TIMSKn |= TIMER_OUTPUT_COMPMATCH_A_INTERRUPT_ENABLE;
}

void timer8bit_disable_compmatch_a_interrupt(volatile timer8bit_interrupts_t* timer){
    timer->TIMSKn &= ~TIMER_OUTPUT_COMPMATCH_A_INTERRUPT_ENABLE;
}

void timer8bit_enable_compmatch_b_interrupt(volatile timer8bit_interrupts_t* timer){
    timer->TIMSKn |= TIMER_OUTPUT_COMPMATCH_B_INTERRUPT_ENABLE;
}

void timer8bit_disable_compmatch_b_interrupt(volatile timer8bit_interrupts_t* timer){
    timer->TIMSKn &= ~TIMER_OUTPUT_COMPMATCH_B_INTERRUPT_ENABLE;
}

void timer8bit_enable_pwm_phasecorrect_mode(volatile timer8bit_t* timer){
    timer->TCCRnA |= PWM_PHASE_CORRECT_MODE;
}

void timer8bit_enable_ctc_mode(volatile timer8bit_t* timer){
    timer->TCCRnA |= CTC_MODE;
}

void timer8bit_enable_fastpwm_mode(volatile timer8bit_t* timer){
    timer->TCCRnA |= FAST_PWM_MODE;
}

void timer8bit_enable_pwm_phasecorrect_ext_mode(volatile timer8bit_t* timer){
    timer->TCCRnA |= PWM_PHASE_CORRECT_MODE;
    timer->TCCRnB |= PWM_PHASE_CORRECT_EXT_MODE;
}

void timer8bit_enable_fastpwm_ext_mode(volatile timer8bit_t* timer){
    timer->TCCRnA |= FAST_PWM_MODE;
    timer->TCCRnB |= FAST_PWM_EXT_MODE;
}

void timer8bit_enable_external_clock(volatile timer8bit_async_status_t* timer){
    timer->ASSRn |= TIMER_ENABLE_EXT_CLOCKINPUT;
}

void timer8bit_enable_async_mode(volatile timer8bit_async_status_t* timer){
    timer->ASSRn |= TIMER_ENABLE_ASYNC_MODE;
}

void timer8bit_reset_prescaler(volatile timer8bit_async_ctrl_t* timer){
    timer->GTCCRn |= TIMER_PRESCALER_RESET;
}