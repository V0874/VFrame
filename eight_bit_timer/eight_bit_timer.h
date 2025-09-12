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
    uint8_t TIMSKn
} timer8bit_interrupts_t;

typedef struct {
    uint8_t TIFRn
} timer8bit_isr_flags_t;

typedef struct {
    uint8_t ASSRn
} timer8bit_async_status_t;

typedef struct {
    uint8_t GTCCRn
} timer8bit_async_control_t;

#define TIMER0 ((volatile timer8bit_t*) TIMER0_BASE)                       
#define TIMER2 ((volatile timer8bit_t*) TIMER2_BASE)

#define TIMER0_ISR ((volatile timer8bit_interrupts_t*) TIMER0_ISR_BASE)
#define TIMER2_ISR ((volatile timer8bit_interrupts_t*) TIMER2_ISR_BASE)

#define TIMER0_ISR_FLAGS ((volatile timer8bit_isr_flags_t*) TIMER0_ISR_FLAGS_BASE)
#define TIMER2_ISR_FLAGS ((volatile timer8bit_isr_flags_t*) TIMER2_ISR_FLAGS_BASE)

#define TIMER2_ASYNC_STATUS ((volatile timer8bit_async_status_t*) TIMER2_ASYNC_STATUS_BASE)
#define TIMER2_ASYNC_CTRL ((volatile timer8bit_async_control_t*) TIMER2_ASYNC_CTRL_BASE)

