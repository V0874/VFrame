#include "watchdog_defs.h"
#include "common_defs.h"

typedef struct{
    uint8_t MCUSRn;
} mcu_status_flags_t;

typedef struct{
    uint8_t WDTCSRn;
} watchdog_t;

#define WATCHDOG0 ((volatile watchdog_ctrl_t*) WATCHDOG_CTRL_BASE)
#define MCU_STATUS ((volatile mcu_status_flags_t*) MCU_STATUS_BASE)
