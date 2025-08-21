#include "usart.h"

void usart_enable_doublespeed(usart_t* usart){
    usart->UCSRnA |= USART_DBL_SPEED_MODE;
}

void usart_enable_multiproc_mode(usart_t* usart){
    usart->UCSRnA |= USART_MULTI_PROC_MODE;
}

void usart_enable_rx_complete_isr(usart_t* usart){
    usart->UCSRnB |= USART_RX_ISR_BIT;
}

void usart_enable_tx_complete_isr(usart_t* usart){
    usart->UCSRnB |= USART_TX_ISR_BIT;
}

void usart_disable_rx_complete_isr(usart_t* usart){
    usart->UCSRnB &= ~USART_RX_ISR_BIT;
}

void usart_disable_tx_complete_isr(usart_t* usart){
    usart->UCSRnB &= ~USART_TX_ISR_BIT;
}