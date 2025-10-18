#include "ac_defines.h"
#include "../common_defs.h"

typedef struct{
    uint8_t ADCSRAn;
    uint8_t ADCSRBn;
    uint8_t ADMUXn;
} ac_t;

typedef struct{
    uint8_t ACSRn;
} ac_ctrl_t;

typedef struct{
    uint8_t DIDRn;
} ac_digi_input_t;

#define AC0 ((volatile ac_t*) AC_BASE)
#define AC0_CTRL ((volatile ac_ctrl_t*) AC_CTRL_STATUS_BASE)
#define AC0_DIGI_INPUT ((volatile ac_digi_input_t*) AC_DIGITAL_INPUT_BASE)

void ac_set_multiplexer(ac_t* ac, int multiplexer);

void ac_enable(ac_ctrl_t* ac);

void ac_disable(ac_ctrl_t* ac);

void ac_set_bandgap_fixed(ac_ctrl_t* ac);

void ac_set_bandgap_ain0(ac_ctrl_t* ac);

void ac_enable_interrupt(ac_ctrl_t* ac);

void ac_disable_interrupt(ac_ctrl_t* ac);

void ac_input_capture_enable(ac_ctrl_t* ac);

void ac_input_capture_disable(ac_ctrl_t* ac);

void ac_interrupt_mode_select(ac_ctrl_t* ac, uint8_t mode);

void ac_digital_input_disable(ac_ctrl_t* ac, uint8_t ain_pin);