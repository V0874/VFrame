/*
---------------------------------------------------------------------------------------------------------------------------------------------------------
                                                        Timer base peripheral block addresses
*/

#define TIMER0_BASE                 (0x44UL)
#define TIMER2_BASE                 (0xB0UL)

#define TIMER0_ISR_BASE             (0x6EUL)
#define TIMER2_ISR_BASE             (0x70UL)

#define TIMER0_ISR_FLAGS_BASE       (0x35UL)
#define TIMER2_ISR_FLAGS_BASE       (0x37UL)

#define TIMER2_ASYNC_STATUS_BASE    (0xB6UL)
#define TIMER2_ASYNC_CTRL_BASE      (0x43UL)

/*
----------------------------------------------------------------------------------------------------------------------------------------------------------
                                                        Timer flag and configuration settings
*/

#define TIMER8BIT_TOGGLE_OUTPUT_COMPARE_PINA              (1 << 6) /* there is a table that explains the behavior for these settings in the eight_bit_timer 
                                                                    header; it changes dependant on the mode that is selected */

#define TIMER8BIT_CLEAR_OUTPUT_COMPARE_PINA               (1 << 7)  
#define TIMER8BIT_SET_OUTPUT_COMPARE_PINA                 (1 << 6) | (1 << 7) 

#define TIMER8BIT_TOGGLE_OUTPUT_COMPARE_PINB              (1 << 4)
#define TIMER8BIT_CLEAR_OUTPUT_COMPARE_PINB               (1 << 5)
#define TIMER8BIT_SET_OUTPUT_COMPARE_PINB                 (1 << 4) | (1 << 5) // description above

#define TIMER8BIT_OVERFLOW_INTERRUPT_ENABLE               (1 << 0)  /* enables ISR on overflow, the frequency of the interrupt depends on the timer prescaler
                                                                as well as the value of the top of the timer */

#define TIMER8BIT_OUTPUT_COMPMATCH_A_INTERRUPT_ENABLE     (1 << 1)  /* enables ISR's on compare match A or B, the frequency of the interrupt depends on
                                                                the timer prescaler set as well as the value of the compare register */

#define TIMER8BIT_OUTPUT_COMPMATCH_B_INTERRUPT_ENABLE     (1 << 2)  // description above

#define TIMER8BIT_OVERFLOW_FLAG                           (1 << 0)  /* can be used to poll for an overflow event instead of utilizing interrupts, the flag 
                                                                must be cleared once it is set. ISR clears the flag once it exits the routine.*/

#define TIMER8BIT_OUTPUT_COMPMATCH_A_FLAG                 (1 << 1)  /* similarly, can be used to poll for an output compare match event instead of utilizing
                                                                interrupts, as well as the flag must be cleared once it is set; ISR also clears the flag
                                                                once it exits the routine.*/

#define TIMER8BIT_OUTPUT_COMPMATCH_B_FLAG                 (1 << 2)  // description above
 
#define TIMER8BIT_NO_PRESCALER                            (1 << 0)  // uses the system clock for the timer clock source

#define TIMER8BIT_8PRESCALER                              (1 << 1)  /* the system clock will be divided by the prescaler and used as the timer clock source 
                                                                for example, if the clock source is 16mhz and 8 prescaler is set, the timer clock source
                                                                will be equal to 2 MHz*/

#define TIMER8BIT_64PRESCALER                             (1 << 0) | (1 << 1)
#define TIMER8BIT_256PRESCALER                            (1 << 2)              
#define TIMER8BIT_1024PRESCALER                           (1 << 0) | (1 << 2)

#define TIMER8BIT_EXTCLOCK_FALLING_EDGE                   (1 << 1) | (1 << 2) /* when set and an external clock source is provided to the t0 pin, the timer 
                                                                          will increment based on the selected edge (rising or falling)*/

#define TIMER8BIT_EXTCLOCK_RISING_EDGE                    (1 << 0) | (1 << 1) | (1 << 2) // description above

#define TIMER8BIT_FORCE_OUTPUT_COMPARE_B                        (1 << 6)  /* forces an immediate compare match event to the compare register; this setting is only 
                                                                active when the timer is set to a non-PWM mode; this setting is implemented as a strobe,
                                                                will not generate an interrupt, and will not clear the timer in CTC mode */

#define TIMER8BIT_FORCE_OUTPUT_COMPARE_A                        (1 << 7)  // description above


/*
                                                the 8 bit timer is automatically set in normal mode by default;
                                                however, by default the timer is configured to a maximum value of 255;
                                                furthermore, the timer overflow flag gets set once the timer reaches the max value
                                                , as well as if a value is set in the OCRnX register,it is immediately updated
                                                and a compare match will be achieved once the timer reaches the specified value.
*/


#define TIMER8BIT_PWM_PHASE_CORRECT_MODE      (1 << 0)    /* sets the 8 bit timer to PWM phase correct mode
                                                the max value of the timer is configured to be 255, however, the OCRnx register
                                                value will only be set once the timer reaches the max value, furthermore,
                                                the timer overflow flag will be set once the timer wraps back to 0
                                                if the MODE2 setting is set, the max value of the timer can effectively be set to 
                                                what value the OCRnA register holds */

#define TIMER8BIT_CTC_MODE                    (1 << 1)    /* sets the 8 bit timer to clear timer on compare match mode;
                                                CTC mode uses the OCRnA register as the top timer value;
                                                but can create an overflow event if OCRnA is set to max: (255)   */

#define TIMER8BIT_FAST_PWM_MODE               (1 << 0) | (1 << 1) /*sets the 8 bit timer to fast PWM mode; the max value of the timer is
                                                        configured to be 255, and the value specified in OCRx will be updated
                                                        once the timer reaches the max value; furthermore, the timer overflow 
                                                        flag will be set once the timer reaches the max value; if the MODE2 setting
                                                        is set, the max value of the timer can effectively be set to what value
                                                        the OCRnA register holds*/

#define TIMER8BIT_PWM_PHASE_CORRECT_EXT_MODE      (1 << 3)    /* this setting changes the mode to allow the top of the timer to be set to the value
                                                    of OCRnA; it must be combined with PWM_PHASE_CORRECT_MODE */
                                                
#define TIMER8BIT_FAST_PWM_EXT_MODE               (1 << 3)    /* this setting changes the mode to allow the top of the timer to be set to the value
                                                    of OCRnA; it must be combined with FAST_PWM_MODE */

/*
---------------------------------------------------------------------------------------------------------------------------------------------------------
                                                        Timer2 specific settings (Asynchronous mode)
*/

#define TIMER8BIT_ENABLE_EXT_CLOCKINPUT           (1 << 6) /* this setting must be set before asynchronous mode; the external clock input is enabled
                                                       and an external clock can be input on the timer oscillator pin (TOSC1) instead of the
                                                       32 kHz crystal. the crystal oscillator will be run by default.*/

#define TIMER8BIT_ENABLE_ASYNC_MODE               (1 << 5) /* timer 2 is by default clocked from the io clock source (selected prescaler); when this 
                                                       setting is enabled the timer is clocked from a crystal oscillator that is connected to the 
                                                       timer oscillator pin (TOSC1); when this setting is enabled, timer values, and compare match
                                                       register values might be corrupted*/

#define TIMER8BIT_UPDATE_BUSY_FLAG                (1 << 4) /* when the timer is asynchronous and the timer counter value is written, this flag is set;
                                                       when the timer gets updated (count increases) the flag is cleared by hardware; checking this
                                                       flag indicates that the timer counter value is ready to be updated
                                                       
                                                       the behavior of the 4 other flags below are identical aside from that they are used to check 
                                                       different behavior. once the compare registers are ready to be written to again the flag will
                                                       be cleared, the same for the control registers. since the asynchronous timer is in a different 
                                                       domain and runs slower than the cpu clock, synchronization is required to avoid glitches in 
                                                       behavior.*/

#define TIMER8BIT_COMPREGISTER_A_UPDATEBUSY_FLAG  (1 << 3) /* flag for timer output compare register a */
#define TIMER8BIT_COMPREGISTER_B_UPDATEBUSY_FLAG  (1 << 2) /* flag for timer output compare register b */
#define TIMER8BIT_CTRLREGISTER_A_UPDATEBUSY_FLAG  (1 << 1) /* flag for timer output control register a*/
#define TIMER8BIT_CTRLREGISTER_B_UPDATEBUSY_FLAG  (1 << 0) /* flag for timer output control register b*/

#define TIMER8BIT_PRESCALER_RESET                       (1 << 1) /* when this setting is enabled, the timer2 prescaler will be reset; if this setting is enabled
                                                       whenever timer2 is in asynchronous mode, it will remain enabled until the prescaler has been 
                                                       reset; this setting is disabled by default by the hardware and TSM bit is set (for 16 bit timers)
                                                       this setting will not be disabled by default*/
/*
---------------------------------------------------------------------------------------------------------------------------------------------------------
*/