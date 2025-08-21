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

#define USART0 ((usart_t*) USART0_BASE)                         // pointer to where the USART peripherals start
#define USART1 ((usart_t*) USART1_BASE)
#define USART2 ((usart_t*) USART2_BASE)
#define USART3 ((usart_t*) USART3_BASE)

void usart_enable_doublespeed(usart_t* usart);                  // enables double transmission speed for asynchronous usart config
                                                                // changes the baud rate divisor from 16 to 8; disabled by default

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
