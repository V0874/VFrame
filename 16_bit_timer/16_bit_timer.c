#include "16_bit_timer.h"

void timer16bit_timer_mode(volatile timer16bit_t* timer, uint8_t mode){
    uint8_t tccrna_bits = mode & 0x03;
    uint8_t tccrnb_bits = mode & 0x18;
    timer->TCCRnA &= ~tccrna_bits;
    timer->TCCRnB &= ~tccrnb_bits;
    timer->TCCRnA |= tccrna_bits;
    timer->TCCRnB |= tccrnb_bits;
}

void timer16bit_set_normal_compare_output_mode(volatile timer16bit_t* timer){
    timer->TCCRnA &= ~0xFC;
}

void timer16bit_set_compare_output_mode(volatile timer16bit_t* timer, uint8_t mode){
    timer->TCCRnA &= ~0xFC;
    timer->TCCRnA |= mode;
}

void timer16bit_enable_input_capture_noise_cancel(volatile timer16bit_t* timer){
    timer->TCCRnB |= TIMER16BIT_INPUT_CAPTURE_NOISE_CANCELER;
}

void timer16bit_disable_input_capture_noise_cancel(volatile timer16bit_t* timer){
    timer->TCCRnB &= ~TIMER16BIT_INPUT_CAPTURE_NOISE_CANCELER;
}

void timer16bit_input_capture_edge_select(volatile timer16bit_t* timer, uint8_t mode){
    if(mode == 0){
        timer->TCCRnB &= ~TIMER16BIT_INPUT_CAPTURE_EDGE_SELECT;
    } else {
        timer->TCCRnB |= TIMER16BIT_INPUT_CAPTURE_EDGE_SELECT;
    }
}

void timer16bit_set_prescaler(volatile timer16bit_t* timer, uint8_t mode){
    timer->TCCRnB |= mode;
}

void timer16bit_force_output_compare_a(volatile timer16bit_t* timer){
    timer->TCCRnC |= TIMER16BIT_FORCE_OUTPUT_COMPARE_A;
}

void timer16bit_force_output_compare_b(volatile timer16bit_t* timer){
    timer->TCCRnC |= TIMER16BIT_FORCE_OUTPUT_COMPARE_B;
}

void timer16bit_force_output_compare_c(volatile timer16bit_t* timer){
    timer->TCCRnC |= TIMER16BIT_FORCE_OUTPUT_COMPARE_C;
}

uint16_t timer16bit_read_timer_value(volatile timer16bit_t* timer){
    uint8_t timer_low = timer->TCNTnL;
    uint8_t timer_high = timer->TCNTnH;
    return ((uint16_t) timer_high << 8) | timer_low;
}

void timer16bit_set_timer_value(volatile timer16bit_t* timer, uint16_t value){
    timer->TCNTnH = (uint8_t) (value >> 8);
    timer->TCNTnL = (uint8_t) value;
}

uint16_t timer16bit_read_output_compare_a(volatile timer16bit_t* timer){
    uint8_t cmp_a_low = timer->OCRnAL;
    uint8_t cmp_a_high = timer->OCRnAH;
    return ((uint16_t) cmp_a_high << 8) | cmp_a_low;
}

void timer16bit_set_output_compare_a_value(volatile timer16bit_t* timer, uint16_t value){
    timer->OCRnAH = (uint8_t) (value >> 8);
    timer->OCRnAL = (uint8_t) value;
}

uint16_t timer16bit_read_output_compare_b_value(volatile timer16bit_t* timer){
    uint8_t cmp_b_low = timer->OCRnBL;
    uint8_t cmp_b_high = timer->OCRnBH;
    return ((uint16_t) cmp_b_high << 8) | cmp_b_low;
}

void timer16bit_set_output_compare_b_value(volatile timer16bit_t* timer, uint16_t value){
    timer->OCRnBH = (uint8_t) (value >> 8);
    timer->OCRnBL = (uint8_t) value;
}

uint16_t timer16bit_read_output_compare_c_value(volatile timer16bit_t* timer){
    uint8_t cmp_c_low = timer->OCRnCL;
    uint8_t cmp_c_high = timer->OCRnCH;
    return ((uint16_t) cmp_c_high << 8) | cmp_c_low;
}

void timer16bit_set_output_compare_c_value(volatile timer16bit_t* timer, uint16_t value){
    timer->OCRnCH = (uint8_t) (value >> 8);
    timer->OCRnCL = (uint8_t) value;
}

uint16_t timer16bit_read_input_capture_value(volatile timer16bit_t* timer){
    uint8_t input_cpt_low = timer->ICRnL;
    uint8_t input_cpt_high = timer->ICRnH;
    return ((uint16_t) input_cpt_high << 8) | input_cpt_low;
}

void timer16bit_set_input_capture_value(volatile timer16bit_t* timer, uint16_t value){
    timer->ICRnH = (uint8_t) (value >> 8);
    timer->ICRnL = (uint8_t) value;
}

void timer16bit_enable_input_capture_interrupt(volatile timer16bit_interrupts_t* timer){
    timer->TIMSKn |= TIMER16BIT_INPUT_CAPTURE_INTERRUPT_ENABLE;
}

void timer16bit_disable_input_capture_interrupt(volatile timer16bit_interrupts_t* timer){
    timer->TIMSKn &= ~TIMER16BIT_INPUT_CAPTURE_INTERRUPT_ENABLE;
}

void timer16bit_enable_output_compare_c_match_interrupt(volatile timer16bit_interrupts_t* timer){
    timer->TIMSKn |= TIMER16BIT_OUTPUT_COMPARE_C_MATCH_INTERRUPT_ENABLE;
}

void timer16bit_disable_output_compare_c_match_interrupt(volatile timer16bit_interrupts_t* timer){
    timer->TIMSKn &= ~TIMER16BIT_OUTPUT_COMPARE_C_MATCH_INTERRUPT_ENABLE;
}

void timer16bit_enable_output_compare_b_match_interrupt(volatile timer16bit_interrupts_t* timer){
    timer->TIMSKn |= TIMER16BIT_OUTPUT_COMPARE_B_MATCH_INTERRUPT_ENABLE;
}

void timer16bit_disable_output_compare_b_match_interrupt(volatile timer16bit_interrupts_t* timer){
    timer->TIMSKn &= ~TIMER16BIT_OUTPUT_COMPARE_B_MATCH_INTERRUPT_ENABLE;
}

void timer16bit_enable_output_compare_a_match_interrupt(volatile timer16bit_interrupts_t* timer){
    timer->TIMSKn |= TIMER16BIT_OUTPUT_COMPARE_A_MATCH_INTERRUPT_ENABLE;
}

void timer16bit_disable_output_compare_a_match_interrupt(volatile timer16bit_interrupts_t* timer){
    timer->TIMSKn &= ~TIMER16BIT_OUTPUT_COMPARE_A_MATCH_INTERRUPT_ENABLE;
}

void timer16bit_enable_overflow_interrupt(volatile timer16bit_interrupts_t* timer){
    timer->TIMSKn |= TIMER16BIT_OVERFLOW_INTERRUPT_ENABLE;
}

void timer16bit_disable_overflow_interrupt(volatile timer16bit_interrupts_t* timer){
    timer->TIMSKn &= ~TIMER16BIT_OVERFLOW_INTERRUPT_ENABLE;
}

void enable_pwm_timer3_pin5(){
    timer16bit_timer_mode(TIMER3, TIMER16BIT_FAST_PWM_8BIT);
    timer16bit_set_prescaler(TIMER3, TIMER16BIT_64PRESCALER);
    timer16bit_set_output_compare_b_value(TIMER3, 255);
}