#include "usart_defs.h"
#include "../common_defs.h"

typedef struct usart_t {
    volatile uint8_t UCSRnA;                                    // Config and status register;  flag and config setting definitions are in usart_defs
    volatile uint8_t UCSRnB;                                    // Config and status register
    volatile uint8_t UCSRnC;                                    // Config and status register
    volatile uint8_t __RESERVED;                                // Not usable
    volatile uint8_t UBRRnL;                                    // 8 bit low byte register for setting baud rate
    volatile uint8_t UBRRnH;                                    // 8 bit high byte register for setting baud rate
    volatile uint8_t UDRn;                                      // TX and RX buffer register
} usart_t;

#define USART0 ((usart_t*) USART0_BASE)                         // USART peripheral starting blocks being as the chip has a total of 4
#define USART1 ((usart_t*) USART1_BASE)                         // each with their own individual settings
#define USART2 ((usart_t*) USART2_BASE)
#define USART3 ((usart_t*) USART3_BASE)

void usart_enable_doublespeed(usart_t* usart);                  // enables double transmission speed for asynchronous usart config
                                                                // changes the baud rate divisor from 16 to 8;

void usart_disable_doublespeed(usart_t* usart);                 // double speed should be disabled when using synchronous mode otherwise can be ignored

void usart_enable_multiproc_mode(usart_t* usart);               // enables multi-processor communication mode
                                                                // all incoming frames to the USART receiver not containing address info are ignored

void usart_enable_rx_complete_isr(usart_t* usart);              // enables receive complete interrupt routine; global interrupts must be enabled
                                                                // interrupt will only fire if the USART_RX_SUCCESS bit is set

void usart_enable_tx_complete_isr(usart_t* usart);              // enables transmit complete interrupt routine; global interrupts must be enabled
                                                                // interrupt will only fire if the USART_TX_SUCCESS bit is set

void usart_disable_rx_complete_isr(usart_t* usart);             // disables receive complete interrupt routine
void usart_disable_tx_complete_isr(usart_t* usart);             // disables transmit complete interrupt routine

void usart_enable_buffempty_isr(usart_t* usart);                // enables buffer empty interrupt routine; global interrupts must be enabled
                                                                // interrupt will only fire if the USART_BUFF_EMPTY bit is set

void usart_disable_buffempty_isr(usart_t* usart);               // disables buffer empty interrupt routine;

void usart_tx_enable(usart_t* usart);                           // enables tx communication 

void usart_rx_enable(usart_t* usart);                           // enables rx communication

void usart_tx_disable(usart_t* usart);                          // disables tx communication 
                                                                // disabling will not become effective until all transmissions have complete

void usart_rx_disable(usart_t* usart);                          // disables rx communication
                                                                // disabling will flush the receive buffer

void usart_clear_mode(usart_t* usart);                          // resets the current usart mode
                                                                // asynchronous mode is the default if usart_set_mode is not used subsequently

void usart_set_mode(usart_t* usart, uint8_t mode);              // sets the usart mode; synchronous and master spi mode are available modes

void clear_parity_mode(usart_t* usart);                         // resets the parity mode, should be reset before configuration
                                                                // by default once reset, parity is disabled

void set_parity_mode(usart_t* usart, uint8_t mode);             // even and odd parity configuration are available

void usart_set_stopbits(usart_t* usart);                        // sets 1 stop bit

void usart_set_2stopbits(usart_t* usart);                       // sets 2 stop bits

void usart_clear_clock_polarity(usart_t* usart);                // polarity must be cleared when asynchronous mode is used

void usart_set_clock_polarity(usart_t* usart);                  // polarity sets the relationship between data output change and data input sample
                                                                // and the synchronous clock;