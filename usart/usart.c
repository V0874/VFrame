#include "usart.h"

void usart_enable_doublespeed(usart_t* usart){
    usart->UCSRnA |= USART_DBL_SPEED_MODE;
}

void usart_disable_doublespeed(usart_t* usart){
    usart->UCSRnA &= ~USART_DBL_SPEED_MODE;
}

void usart_enable_multiproc_mode(usart_t* usart){
    usart->UCSRnA |= USART_MULTI_PROC_MODE;
}

void usart_enable_rx_complete_isr(usart_t* usart){
    usart->UCSRnB |= USART_RX_ISR_SET;
}

void usart_enable_tx_complete_isr(usart_t* usart){
    usart->UCSRnB |= USART_TX_ISR_SET;
}

void usart_disable_rx_complete_isr(usart_t* usart){
    usart->UCSRnB &= ~USART_RX_ISR_SET;
}

void usart_disable_tx_complete_isr(usart_t* usart){
    usart->UCSRnB &= ~USART_TX_ISR_SET;
}

void usart_enable_buffempty_isr(usart_t* usart){
    usart->UCSRnB |= USART_BUFF_ISR_SET;
}

void usart_disable_buffempty_isr(usart_t* usart){
    usart->UCSRnB &= ~USART_BUFF_ISR_SET;
}

void usart_tx_enable(usart_t* usart){
    usart->UCSRnB |= USART_TX_SET;
}

void usart_rx_enable(usart_t* usart){
    usart->UCSRnB |= USART_RX_SET;
}

void usart_tx_disable(usart_t* usart){
    usart->UCSRnB &= ~USART_TX_SET;
}

void usart_rx_disable(usart_t* usart){
    usart->UCSRnB &= ~USART_RX_SET;
}

void usart_clear_mode(usart_t* usart){
    usart->UCSRnC &= ~USART_MODE_RESET;
}

void usart_set_mode(usart_t* usart, uint8_t mode){
    usart->UCSRnC |= mode;
}

void clear_parity_mode(usart_t* usart){
    usart->UCSRnC &= ~USART_PARITY_RESET;
}

void set_parity_mode(usart_t* usart, uint8_t mode){
    usart->UCSRnC |= mode;
}

void usart_set_1stopbit(usart_t* usart){
    usart->UCSRnC &= ~USART_STOP_BIT_MODE;
}

void usart_set_2stopbits(usart_t* usart){
    usart->UCSRnC |= USART_STOP_BIT_MODE;
}

void usart_clear_clock_polarity(usart_t* usart){
    usart->UCSRnC &= USART_CLOCK_POLARITY;
}

void usart_set_clock_polarity(usart_t* usart){
    usart->UCSRnC |= USART_CLOCK_POLARITY;
}  

void usart_clear_databits_mode(usart_t* usart){
    usart->UCSRnB &= ~USART_DATA_BITS;
    usart->UCSRnC &= ~USART_DATA_BITS_MODE;
}

void usart_set_databits(usart_t* usart, uint8_t mode){
    usart->UCSRnC |= mode;
}

void usart_set_9databits(usart_t* usart, uint8_t mode){
    usart->UCSRnB |= USART_DATA_BITS;
    usart->UCSRnC |= USART_DATA_BITS_9BITS;
}

void usart_set_baudrate(usart_t* usart, uint32_t baud){

}