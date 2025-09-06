#include "usart_defs.h"
#include "../common_defs.h"

typedef struct {
    uint8_t UCSRnA;                                    // Config and status register;  flag and config setting definitions are in usart_defs
    uint8_t UCSRnB;                                    // Config and status register
    uint8_t UCSRnC;                                    // Config and status register
    uint8_t __RESERVED;                                // Not usable
    uint8_t UBRRnL;                                    // 8 bit low byte register for setting baud rate
    uint8_t UBRRnH;                                    // 8 bit high byte register for setting baud rate
    uint8_t UDRn;                                      // TX and RX buffer register
} usart_t;

#define USART0 ((volatile usart_t*) USART0_BASE)                        // USART peripheral starting blocks; there are 4 usarts available on the chip                         
#define USART1 ((volatile usart_t*) USART1_BASE)                        
#define USART2 ((volatile usart_t*) USART2_BASE)
#define USART3 ((volatile usart_t*) USART3_BASE)

typedef enum {
    USART_ASYNC_MODE,                                                   // track state of USART mode
    USART_DBL_SPEED_MODE,
    USART_SYNC_MODE,
    USART_SPI_MASTER_MODE
} usart_mode_t;

usart_mode_t usart_modes[4];                                            // USART mode that corresponds to each peripheral

#define USART0_MODE (&usart_modes[0])
#define USART1_MODE (&usart_modes[1])
#define USART2_MODE (&usart_modes[2])
#define USART3_MODE (&usart_modes[3])



void usart_enable_doublespeed(usart_t* usart, usart_mode_t* mode);         /* enables double transmission speed for asynchronous usart config
                                                                                    changes the baud rate divisor from 16 to 8
                                                                                    you must pass in the mode that corresponds to the USART you are setting
                                                                                    ex: if you are using USART0, you must pass in USART0_MODE */

void usart_disable_doublespeed(usart_t* usart, usart_mode_t* mode);        /* double speed should be disabled when using synchronous mode
                                                                                    otherwise this setting can be ignored
                                                                                    you must pass in the mode that corresponds to the USART you are setting
                                                                                    ex: if you are using USART0, you must pass in USART0_MODE
                                                                                    when disabled, the state is switched to synchronous for convenience */

void usart_enable_multiproc_mode(usart_t* usart);      /* enables multi-processor communication mode
                                                                all incoming frames to the USART receiver not containing address info are ignored */

void usart_enable_rx_complete_isr(usart_t* usart);     /* enables receive complete interrupt routine; global interrupts must be enabled
                                                                interrupt will only fire if the USART_RX_SUCCESS bit is set */

void usart_enable_tx_complete_isr(usart_t* usart);     /* enables transmit complete interrupt routine; global interrupts must be enabled
                                                                interrupt will only fire if the USART_TX_SUCCESS bit is set */

void usart_disable_rx_complete_isr(usart_t* usart);    // disables receive complete interrupt routine

void usart_disable_tx_complete_isr(usart_t* usart);    // disables transmit complete interrupt routine

void usart_enable_buffempty_isr(usart_t* usart);       /* enables buffer empty interrupt routine; global interrupts must be enabled
                                                                interrupt will only fire if the USART_BUFF_EMPTY bit is set */

void usart_disable_buffempty_isr(usart_t* usart);      // disables buffer empty interrupt routine;

void usart_tx_enable(usart_t* usart);                  // enables tx communication 

void usart_rx_enable(usart_t* usart);                  // enables rx communication

void usart_tx_disable(usart_t* usart);                 /* disables tx communication 
                                                                disabling will not become effective until all transmissions have complete */

void usart_rx_disable(usart_t* usart);                 /* disables rx communication
                                                                                    disabling will flush the receive buffer */

void usart_set_mode(usart_t* usart, uint8_t config, usart_mode_t* mode);   /* sets the usart mode; synchronous and master spi mode are available modes
                                                                                    usart is set to asynchronous mode by default
                                                                                    you must pass in the mode that corresponds to the USART you are setting
                                                                                    ex: if you are using USART0, you must pass in USART0_MODE */

void set_parity_mode(usart_t* usart, uint8_t config);          /* even and odd parity configuration are available; 
                                                                        by default parity is disabled
                                                                        must pass in USART_EVEN/ODD_PARITY selection */

void usart_set_2stopbits(usart_t* usart);                       /* 1 stop bit is set by default for all usarts
                                                                        this should only be enabled to set 2 stop bits */

void usart_disable_clock_polarity(usart_t* usart);             // polarity must be disabled when asynchronous mode is used

void usart_set_clock_polarity(usart_t* usart);                 /* polarity sets the relationship between data output change and data input sample
                                                                        and the synchronous clock; for synchronous mode only */

void usart_set_databits(usart_t* usart, uint8_t config);       /* configures the data bits mode
                                                                        data bit modes available: 5, 6, 7, and 9
                                                                        must pass in the value that is desired as the config parameter */

void usart_set_spi_mode(usart_t* usart, uint8_t config);      /* sets the current spi mode, there is a table to reference in the defines
                                                                        the mode is defaulted to spi mode one; otherwise you must pass in a value for
                                                                        the specific mode that you want to set based on desired config ie: 0, 2, 3; */

void usart_set_dataorder(usart_t* usart, uint8_t config);     /* enables the least or most significant bit of the data to be transmitted first
                                                                       for master SPI mode only; value 0 will be the most significant bit transmitted first;
                                                                       value 1 will be the least significant bit transmitted first (for config parameter) */

void usart_set_baudrate(usart_t* usart, usart_mode_t* mode, uint32_t baud);    /* sets the baud rate
                                                                                        you must pass in the mode that corresponds to the USART used
                                                                                        ex: if you are using USART0, you must pass in USART0_MODE
                                                                                        so that the baud rate is calculated correctly based on state */



