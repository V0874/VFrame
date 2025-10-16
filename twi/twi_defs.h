
#define TWI_BASE (0xB8UL)

#define TWI_INTERRUPT_FLAG                (1 << 7)
#define TWI_ENABLE_ACKNOWLEDGE_PULSE      (1 << 6)
#define TWI_START_CONDITION               (1 << 5)
#define TWI_STOP_CONDITION                (1 << 4)
#define TWI_WRITE_COLLISION_FLAG          (1 << 3)
#define TWI_ENABLE                        (1 << 2)
#define TWI_INTERRUPT_ENABLE              (1 << 0)
#define TWI_PRESCALER_4                   (1 << 0)
#define TWI_PRESCALER_16                  (1 << 1)
#define TWI_PRESCALER_64                  (1 << 0) | (1 << 1)
#define TWI_GENERAL_CALL_REC_ENABLE       (1 << 0)
