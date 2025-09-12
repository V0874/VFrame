#include "eight_bit_timer_defs.h"
#include "../common_defs.h"

typedef struct {
    uint8_t TCCRnA;                                    
    uint8_t TCCRnB;                                    
    uint8_t TCNTn;                                    
    uint8_t OCRnA;                                
    uint8_t OCRnB;                                                                         
} timer8bit_t;

#define TIMER0 ((volatile timer8bit_t*) TIMER0_BASE)                       
#define TIMER2 ((volatile timer8bit_t*) TIMER2_BASE)   
