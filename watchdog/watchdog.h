#include "watchdog_defs.h"
#include "../common_defs.h"

typedef struct{
    uint8_t MCUSRn;
} mcu_status_t;

typedef struct{
    uint8_t WDTCSRn;
} watchdog_t;

#define WATCHDOG0 ((volatile watchdog_ctrl_t*) WATCHDOG_CTRL_BASE)
#define MCU_STATUS ((volatile mcu_status_t*) MCU_STATUS_BASE)

void watchdog_config(volatile watchdog_t* watchdog, uint8_t prescaler, uint8_t mode);

void watchdog_disable(volatile watchdog_t* watchdog, mcu_status_t* mcu);

static inline void watchdog_kick(){
    asm volatile("wdr");
}