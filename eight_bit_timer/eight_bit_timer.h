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

#define TIMER0 ((volatile timer8bit_t*) TIMER0_BASE)                                /* starting addresses for the configuration registers */
#define TIMER2 ((volatile timer8bit_t*) TIMER2_BASE)

#define TIMER0_INTERRUPTS ((volatile timer8bit_interrupts_t*) TIMER0_ISR_BASE)      /* starting addresses for the interrupt registers*/
#define TIMER2_INTERRUPTS ((volatile timer8bit_interrupts_t*) TIMER2_ISR_BASE)

#define TIMER0_ISR_FLAGS ((volatile timer8bit_isr_flags_t*) TIMER0_ISR_FLAGS_BASE)  /* starting addresses for the flag registers */
#define TIMER2_ISR_FLAGS ((volatile timer8bit_isr_flags_t*) TIMER2_ISR_FLAGS_BASE)

#define TIMER2_ASYNC_STATUS ((volatile timer8bit_async_status_t*) TIMER2_ASYNC_STATUS_BASE) /* starting addresses for the async status registers / timer02  */

#define TIMER2_ASYNC_CTRL ((volatile timer8bit_async_control_t*) TIMER2_ASYNC_CTRL_BASE)    /* starting addresses for the async control registers / timer02 */


void timer_set_comparematch_mode_a(volatile timer8bit_t* timer, uint8_t config);            /* sets the desired compare match A pin mode.

                                                                                            if no compare match is selected it is not enabled.

                                                                                            furthermore, the behavior changes based on the current selected mode;
                                                                                            non-pwm mode, fast pwm mode, or phase correct pwm mode and whether their extended modes are enabled.

                                                                                            TOGGLE_OUTPUT_COMPARE:

                                                                                            sets the output pin A/B to high or low based on its current state;
                                                                                            when a compare match is reached, if the pin is low, it will flip to high and vice-versa;

                                                                                            if extended mode is set it will toggle the pin on compare match
                                                                                            for either fast pwm mode or phase correct pwm mode;
                                                                                            otherwise the compare match pin will be disconnected for these selected modes;

                                                                                            CLEAR_OUTPUT_COMPARE: 

                                                                                            clearing on output compare match will set the output pin to low;

                                                                                            fast pwm mode: clear will set the pin to low on compare match, and set the pin to high
                                                                                            once the timer wraps around to the bottom value.

                                                                                            phase correct pwm mode: clear will set the pin to low when up counting, and set the pin to high
                                                                                            when down counting.
                                                                                            
                                                                                            SET_OUTPUT_COMPARE:

                                                                                            setting the output pin on compare match will set the output pin to high.

                                                                                            fast pwm mode: the pin will be set to high on compare match, and the pin will be low once the 
                                                                                            timer wraps around to the bottom value.
                                                                                            
                                                                                            phase correct pwm mode: the pin will be set to high when up counting, and low when down counting */


void timer_set_comparematch_mode_b(volatile timer8bit_t* timer, uint8_t config);            /* this function has the same behavior as above */

void timer_force_output_compare_b(volatile timer8bit_t* timer);                             /* */

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

void timer_init(volatile timer8bit_t* timer);