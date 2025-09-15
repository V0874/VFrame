/*
--------------------------------------------------------------------------------------------------------------------------------------------
                                                        Timer base peripheral block addresses
*/

#define TIMER0_BASE                 (0x24UL)
#define TIMER2_BASE                 (0xB0UL)

#define TIMER0_ISR_BASE             (0x6EUL)
#define TIMER2_ISR_BASE             (0x70UL)

#define TIMER0_ISR_FLAGS_BASE       (0x15UL)
#define TIMER2_ISR_FLAGS_BASE       (0x17UL)

#define TIMER2_ASYNC_STATUS_BASE    (0xB6UL)
#define TIMER2_ASYNC_CTRL_BASE      (0x23UL)

/*
--------------------------------------------------------------------------------------------------------------------------------------------
                                                        Timer flag and configuration settings
*/

#define TIMER_TOGGLE_OUTPUT_COMPARE_PINA              (1 << 6)
#define TIMER_CLEAR_OUTPUT_COMPARE_PINA               (1 << 7)
#define TIMER_SET_OUTPUT_COMPARE_PINA                 (1 << 6) | (1 << 7)

#define TIMER_TOGGLE_OUTPUT_COMPARE_PINB              (1 << 4)              
#define TIMER_CLEAR_OUTPUT_COMPARE_PINB               (1 << 5)
#define TIMER_SET_OUTPUT_COMPARE_PINB                 (1 << 4) | (1 << 5)

#define TIMER_OVERFLOW_INTERRUPT_ENABLE               (1 << 0) 
#define TIMER_OUTPUT_COMPMATCH_A_INTERRUPT_ENABLE     (1 << 1)
#define TIMER_OUTPUT_COMPMATCH_B_INTERRUPT_ENABLE     (1 << 2)

#define TIMER_OVERFLOW_FLAG                           (1 << 0)
#define TIMER_OUTPUT_COMPMATCH_A_FLAG                 (1 << 1)
#define TIMER_OUTPUT_COMPMATCH_B_FLAG                 (1 << 2)
 
#define TIMER_NO_PRESCALER                            (1 << 0)
#define TIMER_8PRESCALER                              (1 << 1)
#define TIMER_64PRESCALER                             (1 << 0) | (1 << 1)
#define TIMER_256PRESCALER                            (1 << 2)  
#define TIMER_1024PRESCALER                           (1 << 0) | (1 << 2)
#define TIMER_EXTCLOCK_FALLING_EDGE                   (1 << 1) | (1 << 2)
#define TIMER_EXTCLOCK_RISING_EDGE                    (1 << 0) | (1 << 1) | (1 << 2)

#define FORCE_OUTPUT_COMPARE_B                        (1 << 6)
#define FORCE_OUTPUT_COMPARE_A                        (1 << 7)


/*
                                                the 8 bit timer is automatically set in normal mode by default;
                                                however, by default the timer is configured to a maximum value of 255;
                                                furthermore, the timer overflow flag gets set once the timer reaches the max value
                                                , as well as if a value is set in the OCRnX register,it is immediately updated
                                                and a compare match will be achieved once the timer reaches the specified value.
*/


#define PWM_PHASE_CORRECT_MODE      (1 << 0)    /* sets the 8 bit timer to PWM phase correct mode
                                                the max value of the timer is configured to be 255, however, the OCRnx register
                                                value will only be set once the timer reaches the max value, furthermore,
                                                the timer overflow flag will be set once the timer wraps back to 0
                                                if the MODE2 setting is set, the max value of the timer can effectively be set to 
                                                what value the OCRnA register holds */

#define CTC_MODE                    (1 << 1)    /* sets the 8 bit timer to clear timer on compare match mode;
                                                CTC mode uses the OCRnA register as the top timer value;
                                                but can create an overflow event if OCRnA is set to max: (255)   */

#define FAST_PWM_MODE               (1 << 0) | (1 << 1) /*sets the 8 bit timer to fast PWM mode; the max value of the timer is
                                                        configured to be 255, and the value specified in OCRx will be updated
                                                        once the timer reaches the max value; furthermore, the timer overflow 
                                                        flag will be set once the timer reaches the max value; if the MODE2 setting
                                                        is set, the max value of the timer can effectively be set to what value
                                                        the OCRnA register holds*/

#define PWM_PHASE_CORRECT_EXT_MODE      (1 << 3)    /* this setting changes the mode to allow the top of the timer to be set to the value
                                                    of OCRnA; it must be combined with PWM_PHASE_CORRECT_MODE */
                                                
#define FAST_PWM_EXT_MODE               (1 << 3)    /* this setting changes the mode to allow the top of the timer to be set to the value
                                                    of OCRnA; it must be combined with FAST_PWM_MODE */
