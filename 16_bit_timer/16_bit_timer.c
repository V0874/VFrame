#include "16_bit_timer.h"

uint16_t timer16bit_read_timer_value(timer16bit_t* timer){
    uint8_t timer_low = timer->TCNTnL;
    uint8_t timer_high = timer->TCNTnH;
    return ((uint16_t) timer_high << 8) | timer_low;
}

void timer16bit_set_timer_value(timer16bit_t* timer, uint16_t value){

}

uint16_t timer16bit_read_output_compare_a(timer16bit_t* timer){
    uint8_t cmp_a_low = timer->OCRnAL;
    uint8_t cmp_a_high = timer->OCRnAH;
    return ((uint16_t) cmp_a_high << 8) | cmp_a_low;
}

void timer16bit_set_output_compare_a_value(timer16bit_t* timer, uint16_t value){

}

uint16_t timer16bit_read_output_compare_b_value(timer16bit_t* timer){
    uint8_t cmp_b_low = timer->OCRnBL;
    uint8_t cmp_b_high = timer->OCRnBH;
    return ((uint16_t) cmp_b_high << 8) | cmp_b_low;
}

void timer16bit_set_output_compare_b_value(timer16bit_t* timer, uint16_t value){

}

uint16_t timer16bit_read_output_compare_c_value(timer16bit_t* timer){
    uint8_t cmp_c_low = timer->OCRnCL;
    uint8_t cmp_c_high = timer->OCRnCH;
    return ((uint16_t) cmp_c_high << 8) | cmp_c_low;
}

void timer16bit_set_output_compare_c_value(timer16bit_t* timer, uint16_t value){

}

uint16_t timer16bit_read_input_capture_value(timer16bit_t* timer){
    uint8_t input_cpt_low = timer->ICRnL;
    uint8_t input_cpt_high = timer->ICRnH;
    return ((uint16_t) input_cpt_high << 8) | input_cpt_low;
}

void timer16bit_set_input_capture_value(timer16bit_t* timer, uint16_t value){

}

void timer16bit_input_capture_enable_interrupt(timer16bit_interrupts_t* timer){
    timer->TIMSKn |= TIMER_INPUT_CAPTURE_INTERRUPT_ENABLE;
}

void timer16bit_output_compare_c_match_interrupt_enable(timer16bit_interrupts_t* timer){
    timer->TIMSKn |= TIMER_OUTPUT_COMPARE_C_MATCH_INTERRUPT_ENABLE;
}

void timer16bit_output_compare_b_match_interrupt_enable(timer16bit_interrupts_t* timer){
    timer->TIMSKn |= TIMER_OUTPUT_COMPARE_B_MATCH_INTERRUPT_ENABLE;
}

void timer16bit_output_compare_a_match_interrupt_enable(timer16bit_interrupts_t* timer){
    timer->TIMSKn |= TIMER_OUTPUT_COMPARE_A_MATCH_INTERRUPT_ENABLE;
}

void timer16bit_overflow_interrupt_enable(timer16bit_interrupts_t* timer){
    timer->TIMSKn |= TIMER_OVERFLOW_INTERRUPT_ENABLE;
}