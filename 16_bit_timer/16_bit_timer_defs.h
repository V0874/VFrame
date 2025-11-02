
#define TIMER1_BASE                                     (0x80UL)
#define TIMER3_BASE                                     (0x90UL)
#define TIMER4_BASE                                     (0xA0UL)
#define TIMER5_BASE                                     (0x120UL)

#define TIMER1_ISR_BASE                                 (0x6FUL)
#define TIMER3_ISR_BASE                                 (0x71UL)
#define TIMER4_ISR_BASE                                 (0x72UL)
#define TIMER5_ISR_BASE                                 (0x73UL)

#define TIMER1_ISR_FLAGS_BASE                           (0x36UL)
#define TIMER3_ISR_FLAGS_BASE                           (0x38UL)
#define TIMER4_ISR_FLAGS_BASE                           (0x39UL)
#define TIMER5_ISR_FLAGS_BASE                           (0x3AUL)

#define TIMER_SYNC_CTRL_BASE                            (0x43UL)

#define TIMER_INPUT_CAPTURE_INTERRUPT_ENABLE            (1 << 5)
#define TIMER_OUTPUT_COMPARE_C_MATCH_INTERRUPT_ENABLE   (1 << 3)
#define TIMER_OUTPUT_COMPARE_B_MATCH_INTERRUPT_ENABLE   (1 << 2)
#define TIMER_OUTPUT_COMPARE_A_MATCH_INTERRUPT_ENABLE   (1 << 1)
#define TIMER_OVERFLOW_INTERRUPT_ENABLE          (1 << 0)

#define TIMER_INPUT_CAPTURE_FLAG                        (1 << 5)
#define TIMER_OUTPUT_COMPARE_C_MATCH_FLAG               (1 << 3)
#define TIMER_OUTPUT_COMPARE_B_MATCH_FLAG               (1 << 2)
#define TIMER_OUTPUT_COMPARE_A_MATCH_FLAG               (1 << 1)
#define TIMER_OVERFLOW_FLAG                             (1 << 0)