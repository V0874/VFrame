#include "usart/usart.h"
#include "gpio/gpio.h"
#include "ring_buffer/ring_buffer.h"

ring_buffer_t ring;

void usart_init();
void usart_send(const char* string);


int main(){

    ring_buffer_init(&ring);
    usart_init();


    setOutput(&DDRH, PH6);

    usart_send("hello");

    uint8_t foo = ring_buffer_getcount(&ring);


    while(1){

    setHigh(&PORTH, PH6);

    

    }
}

void usart_init(){
    usart_tx_enable(USART0);
    usart_rx_enable(USART0);
    usart_set_baudrate(USART0, USART0_MODE, 9600);
}

void usart_send(const char* string){
    while (*string != '\0'){
        ring_buffer_write(&ring, *string);
        string++;
    }
    sei();
    usart_enable_buffempty_isr(USART0);
}


ISR(USART0_UDRE_vect){
    if(ring_buffer_empty(&ring)){
        usart_disable_buffempty_isr(USART0);
    }
    USART0->UDRn = ring_buffer_read(&ring);
}