#include "usart.h"

void usart_enable_doublespeed(usart_t* usart){
    usart->UCSRnA |= USART_DBL_SPEED_MODE;
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