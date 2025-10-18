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
#define AC_CTRL ((volatile ac_ctrl_t*) AC_CTRL_STATUS_BASE)
#define AC_DIGI_INPUT ((volatile ac_digi_input_t*) AC_DIGITAL_INPUT_BASE)

