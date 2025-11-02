#include "8_bit_timer_defs.h"
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
} timer8bit_async_ctrl_t;

#define TIMER0 ((volatile timer8bit_t*) TIMER0_BASE)                                /* current timer selection; these are passed to functions
                                                                                    to make timer selection easier.  */
#define TIMER2 ((volatile timer8bit_t*) TIMER2_BASE)

#define TIMER0_INTERRUPTS ((volatile timer8bit_interrupts_t*) TIMER0_ISR_BASE)      /* current timer interrupt selections */
#define TIMER2_INTERRUPTS ((volatile timer8bit_interrupts_t*) TIMER2_ISR_BASE)

#define TIMER0_ISR_FLAGS ((volatile timer8bit_isr_flags_t*) TIMER0_ISR_FLAGS_BASE)  /* current timer flags  */
#define TIMER2_ISR_FLAGS ((volatile timer8bit_isr_flags_t*) TIMER2_ISR_FLAGS_BASE)

#define TIMER2_ASYNC_STATUS ((volatile timer8bit_async_status_t*) TIMER2_ASYNC_STATUS_BASE) /* async status flags / for timer02 only */

#define TIMER2_ASYNC_CTRL ((volatile timer8bit_async_ctrl_t*) TIMER2_ASYNC_CTRL_BASE)    /* async control selections / for timer02 only */


void timer8bit_set_compareoutput_mode_a(volatile timer8bit_t* timer, uint8_t config);            /*------------------------------------------------------------------------------------------------

                                                                                            sets the desired compare match A pin mode.

                                                                                            if no compare match is selected it is not enabled.

                                                                                            furthermore, the behavior changes based on the current selected mode;
                                                                                            non-pwm mode, fast pwm mode, or phase correct pwm mode and whether their extended modes are enabled.

                                                                                            --------------------  TOGGLE_OUTPUT_COMPARE -------------------------------------------------------

                                                                                            sets the output pin A/B to high or low based on its current state;
                                                                                            when a compare match is reached, if the pin is low, it will flip to high and vice-versa;

                                                                                            if extended mode is set it will toggle the pin on compare match
                                                                                            for either fast pwm mode or phase correct pwm mode;
                                                                                            otherwise the compare match pin will be disconnected for these selected modes;

                                                                                            --------------------  CLEAR OUTPUT COMPARE -------------------------------------------------------

                                                                                            clearing on output compare match will set the output pin to low;

                                                                                            fast pwm mode: clear will set the pin to low on compare match, and set the pin to high
                                                                                            once the timer wraps around to the bottom value.

                                                                                            phase correct pwm mode: clear will set the pin to low when up counting, and set the pin to high
                                                                                            when down counting.
                                                                                            
                                                                                            --------------------  SET OUTPUT COMPARE -------------------------------------------------------

                                                                                            setting the output pin on compare match will set the output pin to high.

                                                                                            fast pwm mode: the pin will be set to high on compare match, and the pin will be low once the 
                                                                                            timer wraps around to the bottom value.
                                                                                            
                                                                                            phase correct pwm mode: the pin will be set to high when up counting, and low when down counting 
                                                                                            ------------------------------------------------------------------------------------------------*/
                                                                                            

void timer8bit_set_compareoutput_mode_b(volatile timer8bit_t* timer, uint8_t config);            // description above

void timer8bit_force_output_compare_b(volatile timer8bit_t* timer);                             /* enables a forced output compare match event for the current timer; this setting is only 
                                                                                            available for non-PWM modes and will implement a strobe; furthermore, it will not generate
                                                                                            an interrupt nor will it clear the timer in CTC mode*/

void timer8bit_force_output_compare_a(volatile timer8bit_t* timer);                             // description above

void timer8bit_set_prescaler(volatile timer8bit_t* timer, uint8_t config);                      /* sets the desired prescaler for the current timer clock source; the available modes are:
                                                                                            no clock source (by default), no prescaler, /8, /64, /256, /1024 (the system clock will be 
                                                                                            divided by the prescaler selected and used for the timer clock source); furthermore, there is 
                                                                                            a setting to provide an external clock source to the Tn pin that will increment the counter 
                                                                                            based on the falling edge/rising edge of the timer clock source.*/

void timer8bit_set_counter_value(volatile timer8bit_t* timer, uint8_t value);                         /* sets the current timer counter value; if written to, the current compare match will be removed 
                                                                                            on the timer clock as well as risks missing a compare match*/

uint8_t timer8bit_read_counter_value(volatile timer8bit_t* timer);                                    // reads the current value of the current timer

void timer8bit_set_output_compare_a_value(volatile timer8bit_t* timer, uint8_t value);                /* sets the output compare match A value that is continuously compared with the current value
                                                                                            of the timer; the compare match can generate an interrupt or generate a waveform on the OCnA pin */

uint8_t timer8bit_read_output_compare_a_value(volatile timer8bit_t* timer);                           // reads the current value of the output compare match A register for the current timer

void timer8bit_set_output_compare_b_value(volatile timer8bit_t* timer, uint8_t value);

uint8_t timer8bit_read_output_compare_b_value(volatile timer8bit_t* timer);                           // description above for both set and read

/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

                                                                                            /* the interrupts below must be passed the proper TIMER0/TIMER2_INTERRUPTS based on what is desired */

void timer8bit_enable_overflow_interrupt(volatile timer8bit_interrupts_t* timer);               // enables overflow ISR on the current timer

void timer8bit_disable_overflow_interrupt(volatile timer8bit_interrupts_t* timer);              // disables overflow ISR on the current timer

void timer8bit_enable_compmatch_a_interrupt(volatile timer8bit_interrupts_t* timer);            // enables compare match A interrupt on the current timer

void timer8bit_disable_compmatch_a_interrupt(volatile timer8bit_interrupts_t* timer);           // disables compare match A interrupt on the current timer

void timer8bit_enable_compmatch_b_interrupt(volatile timer8bit_interrupts_t* timer);            // enables compare match B interrupt on the current timer

void timer8bit_disable_compmatch_b_interrupt(volatile timer8bit_interrupts_t* timer);           // disables compare match B interrupt on the current timer

/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
                                                                                            /*--------------------  NORMAL -----------------------------------------------------------------------
                                                                                            
                                                                                            the normal timer operation is set and the timer top
                                                                                            value is set to 255; the output compare register is immediately
                                                                                            updated when it is set and the timer overflow flag is set when the
                                                                                            timer reaches the max and wraps back to 0

                                                                                            -------------------- PWM PHASE CORRECT ---------------------------------------------------------------
                                                                                            
                                                                                            for pwm phase correct mode, the top of the timer is defaulted to 255
                                                                                            and the output compare register is updated once the top value is reached;
                                                                                            the timer overflow flag is set when the bottom of the timer is reached

                                                                                            for pwm phase correct extended mode the top of the timer can be set to 
                                                                                            the output compare register a value, and the output compare register is 
                                                                                            updated once the timer reaches the top value as to not miss a compare match
                                                                                            once the value is initially set. the timer overflow flag is set at the bottom
                                                                                            of the timer.
                                                                                            
                                                                                            -------------------- CTC -----------------------------------------------------------------------------

                                                                                            for ctc mode, the top of the timer is set to the value of the output compare a 
                                                                                            register and ocrn register is immediately updated once the output compare a register
                                                                                            is set; the timer overflow flag is set once the timer reaches the max value and wraps 
                                                                                            back to 0

                                                                                            -------------------- FAST PWM ------------------------------------------------------------------------

                                                                                            for fast pwm mode, the top of the timer is defaulted to 255; the ocrn register is updated
                                                                                            once the top of the timer is reached and the timer overflow flag is set once the timer reaches
                                                                                            the max value and wraps back to 0;

                                                                                            for fast pwm extended mode, the top of the timer is set to the value of the output compare a
                                                                                            register, and the ocrn register is updated once the timer reaches the bottom value (usually 0);
                                                                                            the timer overflow flag is set once the timer reaches the top value
                                                                                            
                                                                                            */
                                                                                           
void timer8bit_enable_pwm_phasecorrect_mode(volatile timer8bit_t* timer);                       // enables PWM phase correct mode for the current timer

void timer8bit_enable_ctc_mode(volatile timer8bit_t* timer);                                    // enables CTC mode for the current timer

void timer8bit_enable_fastpwm_mode(volatile timer8bit_t* timer);                                // enables fast PWM mode for the current timer

void timer8bit_enable_pwm_phasecorrect_ext_mode(volatile timer8bit_t* timer);                   /* enables pwm phase correct extended mode for the current timer;
                                                                                            i have labeled it extended mode because of the behavior of the top 
                                                                                            value when the setting is set; the full description is in the table 
                                                                                            near the top of this file for setting compare output mode */

void timer8bit_enable_fastpwm_ext_mode(volatile timer8bit_t* timer);                            /* enables fast pwm extended mode; the description is similar to above
                                                                                            and the full description is in the table at the top of this file*/

void timer8bit_enable_external_clock(volatile timer8bit_async_status_t* timer);                 /* enables external clock input on the external clock source pin */
    
void timer8bit_enable_async_mode(volatile timer8bit_async_status_t* timer);                   /* enables asynchronous mode for timer2 only */

void timer8bit_reset_prescaler(volatile timer8bit_async_ctrl_t* timer);                      /* resets the prescaler for timer2 in asynchronous mode only */

void timer8bit_init(volatile timer8bit_t* timer);                                               /* initializes a timer with basic settings */