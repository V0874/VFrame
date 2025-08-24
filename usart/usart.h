#include "usart_defs.h"
#include "../common_defs.h"

typedef struct {
    volatile uint8_t UCSRnA;                                    // Config and status register;  flag and config setting definitions are in usart_defs
    volatile uint8_t UCSRnB;                                    // Config and status register
    volatile uint8_t UCSRnC;                                    // Config and status register
    volatile uint8_t __RESERVED;                                // Not usable
    volatile uint8_t UBRRnL;                                    // 8 bit low byte register for setting baud rate
    volatile uint8_t UBRRnH;                                    // 8 bit high byte register for setting baud rate
    volatile uint8_t UDRn;                                      // TX and RX buffer register
} usart_t;

typedef enum {
    USART_ASYNC_MODE,
    USART_ASYNC_DBL_MODE,
    USART_SPI_MASTER_MODE
} usart_mode_t;


#define USART0 ((usart_t*) USART0_BASE)                         // USART peripheral starting blocks; there are 4 usarts available on the chip                         
#define USART1 ((usart_t*) USART1_BASE)                        
#define USART2 ((usart_t*) USART2_BASE)
#define USART3 ((usart_t*) USART3_BASE)

void usart_enable_doublespeed(usart_t* usart);                  /* enables double transmission speed for asynchronous usart config
                                                                changes the baud rate divisor from 16 to 8 */

void usart_disable_doublespeed(usart_t* usart);                 // double speed should be disabled when using synchronous mode otherwise can be ignored

void usart_enable_multiproc_mode(usart_t* usart);               /* enables multi-processor communication mode
                                                                all incoming frames to the USART receiver not containing address info are ignored */

void usart_enable_rx_complete_isr(usart_t* usart);              /* enables receive complete interrupt routine; global interrupts must be enabled
                                                                interrupt will only fire if the USART_RX_SUCCESS bit is set */

void usart_enable_tx_complete_isr(usart_t* usart);              /* enables transmit complete interrupt routine; global interrupts must be enabled
                                                                interrupt will only fire if the USART_TX_SUCCESS bit is set */

void usart_disable_rx_complete_isr(usart_t* usart);             // disables receive complete interrupt routine

void usart_disable_tx_complete_isr(usart_t* usart);             // disables transmit complete interrupt routine

void usart_enable_buffempty_isr(usart_t* usart);                /* enables buffer empty interrupt routine; global interrupts must be enabled
                                                                interrupt will only fire if the USART_BUFF_EMPTY bit is set */

void usart_disable_buffempty_isr(usart_t* usart);               // disables buffer empty interrupt routine;

void usart_tx_enable(usart_t* usart);                           // enables tx communication 

void usart_rx_enable(usart_t* usart);                           // enables rx communication

void usart_tx_disable(usart_t* usart);                          /* disables tx communication 
                                                                disabling will not become effective until all transmissions have complete */

void usart_rx_disable(usart_t* usart);                          /* disables rx communication
                                                                disabling will flush the receive buffer */

void usart_set_mode(usart_t* usart, uint8_t mode);              /* sets the usart mode; synchronous and master spi mode are available modes
                                                                usart is set to asynchronous mode by default */

void set_parity_mode(usart_t* usart, uint8_t mode);             /* even and odd parity configuration are available; 
                                                                by default parity is disabled */

void usart_set_stopbits(usart_t* usart);                        /* 1 stop bit is set by default
                                                                this should only be enabled to set 2 stop bits */

void usart_disable_clock_polarity(usart_t* usart);              // polarity must be disabled when asynchronous mode is used

void usart_set_clock_polarity(usart_t* usart);                  /* polarity sets the relationship between data output change and data input sample
                                                                and the synchronous clock; for synchronous mode only */

void usart_clear_databits_mode(usart_t* usart);                 /* clears the current data bits mode selected; 
                                                                must clear the configuration before setting the mode
                                                                to anything other than 8 data bits; 8 data bits is the default mode without config;
                                                                if the mode is cleared, 5 data bits mode is to be expected without config*/

void usart_set_databits(usart_t* usart, uint8_t mode);          /* configures the data bits mode
                                                                data bit modes available: 5, 6, and 7;
                                                                for 9 data bits use the exclusive function */

void usart_set_9databits(usart_t* usart);                       // sets 9 data bits; the mode must be cleared before its set

void usart_set_baudrate(usart_t* usart, uint32_t baud);         /* sets the baud rate
                                                                if the master SPI mode is set
                                                                the baud rate will be calculated differently */


