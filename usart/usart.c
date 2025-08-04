#include "usart.h"
#include "gpio.h"

volatile char* tx_buffer;

void usart_send(char* data){
    tx_buffer = data;
    UCSR0B |= (1 << UDRIE0);
}

ISR(USART0_UDRE_vect){
    if (*tx_buffer != '\0'){
    UDR0 = *tx_buffer;
    tx_buffer++; 
    } else {
    UCSR0B &= ~(1 << UDRIE0);
    }
}
