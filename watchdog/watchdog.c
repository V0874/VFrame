#include "watchdog.h"

void watchdog_config(volatile watchdog_t* watchdog, uint8_t prescaler, uint8_t mode){
    cli();
    watchdog_kick();
    watchdog->WDTCSRn = WATCHDOG_CHANGE_ENABLE | WATCHDOG_SYSTEM_RESET_MODE;
    watchdog->WDTCSRn = prescaler | mode;
    sei();
}

void watchdog_disable(volatile watchdog_t* watchdog, mcu_status_t* mcu){
    cli();
    watchdog_kick();
    mcu->MCUSRn &= ~WATCHDOG_RESET_FLAG;
    watchdog->WDTCSRn = WATCHDOG_CHANGE_ENABLE | WATCHDOG_SYSTEM_RESET_MODE;
    watchdog->WDTCSRn = 0x00;
    sei();
}