#include "usart.h"

void usart_enable_doublespeed(volatile usart_t* usart, usart_mode_t* mode){
    usart->UCSRnA |= USART_DBL_SPEED_CONFIG;
    *mode = USART_DBL_SPEED_MODE;
}

void usart_disable_doublespeed(volatile usart_t* usart, usart_mode_t* mode){
    usart->UCSRnA &= ~USART_DBL_SPEED_CONFIG;
    *mode = USART_SYNC_MODE;
}

void usart_enable_multiproc_mode(volatile usart_t* usart){
    usart->UCSRnA |= USART_MULTI_PROC_MODE;
}

void usart_enable_rx_complete_isr(volatile usart_t* usart){
    usart->UCSRnB |= USART_RX_ISR_SET;
}

void usart_enable_tx_complete_isr(volatile usart_t* usart){
    usart->UCSRnB |= USART_TX_ISR_SET;
}

void usart_disable_rx_complete_isr(volatile usart_t* usart){
    usart->UCSRnB &= ~USART_RX_ISR_SET;
}

void usart_disable_tx_complete_isr(volatile usart_t* usart){
    usart->UCSRnB &= ~USART_TX_ISR_SET;
}

void usart_enable_buffempty_isr(volatile usart_t* usart){
    usart->UCSRnB |= USART_BUFF_ISR_SET;
}

void usart_disable_buffempty_isr(volatile usart_t* usart){
    usart->UCSRnB &= ~USART_BUFF_ISR_SET;
}

void usart_tx_enable(volatile usart_t* usart){
    usart->UCSRnB |= USART_TX_SET;
}

void usart_rx_enable(volatile usart_t* usart){
    usart->UCSRnB |= USART_RX_SET;
}

void usart_tx_disable(volatile usart_t* usart){
    usart->UCSRnB &= ~USART_TX_SET;
}

void usart_rx_disable(volatile usart_t* usart){
    usart->UCSRnB &= ~USART_RX_SET;
}

void usart_set_mode(volatile usart_t* usart, uint8_t config, usart_mode_t* mode){
    usart->UCSRnC |= config;
    switch(config){
        case USART_SYNC_CONFIG: *mode = USART_SYNC_MODE;
        case USART_MASTER_SPI_CONFIG: *mode = USART_SPI_MASTER_MODE;
    }
}

void usart_set_parity_mode(volatile usart_t* usart, uint8_t config){
    usart->UCSRnC |= config;
}

void usart_set_2stopbits(volatile usart_t* usart){
    usart->UCSRnC |= USART_2_STOP_BITS;
}

void usart_disable_clock_polarity(volatile usart_t* usart){
    usart->UCSRnC &= ~USART_CLOCK_POLARITY;
}

void usart_set_clock_polarity(volatile usart_t* usart){
    usart->UCSRnC |= USART_CLOCK_POLARITY;
}  

void usart_set_databits(volatile usart_t* usart, uint8_t config){
    switch(config){
        case 5: {
            usart->UCSRnC &= ~USART_DATA_BITS_MASK;
            break;
        }
        case 6: {
            usart->UCSRnC |= USART_DATA_BITS_6BITS;
            break;
        }
        case 7: {
            usart->UCSRnC |= USART_DATA_BITS_7BITS;
            break;
        }
        case 9: {
            usart->UCSRnB |= USART_DATA_BITS_9BITS;
            break;
        }
    }
}

void usart_set_dataorder(volatile usart_t* usart, uint8_t config){
    switch(config){
        case 0: {
            usart->UCSRnC &= ~USART_DATA_ORDER;
        }
        case 1: {
            usart->UCSRnC |= USART_DATA_ORDER;
        }
    }
}

void usart_set_spi_mode(volatile usart_t* usart, uint8_t config){
    switch(config){
        case 0:{
            usart->UCSRnC &= ~USART_CLOCK_PHASE;
            break;
        }
        case 2:{
            usart->UCSRnC &= ~USART_CLOCK_PHASE;
            usart->UCSRnC |= USART_CLOCK_POLARITY;
            break;
        }
        case 3:{
            usart->UCSRnC |= USART_CLOCK_POLARITY;
            break;
        }
    }
}

void usart_set_baudrate(volatile usart_t* usart, usart_mode_t* mode, uint32_t baud){
    switch(*mode){
        case USART_DBL_SPEED_MODE:{
            uint16_t UBRR = (F_CPU / (8UL * baud)) - 1;
            usart->UBRRnH = (uint8_t)(UBRR >> 8);
            usart->UBRRnL = (uint8_t)(UBRR);
            break;
        }
        case USART_SPI_MASTER_MODE:{
            uint16_t UBRR = (F_CPU / (2UL * baud)) - 1;
            usart->UBRRnH = (uint8_t)(UBRR >> 8);
            usart->UBRRnL = (uint8_t)(UBRR);
            break;
        }
        default: {
            uint16_t UBRR = (F_CPU / (16UL * baud)) - 1;
            usart->UBRRnH = (uint8_t)(UBRR >> 8);
            usart->UBRRnL = (uint8_t)(UBRR);
            break;
        }
    }
}