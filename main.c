#include "usart/usart.h"
#include "gpio/gpio.h"
#include "ring_buffer/ring_buffer.h"

ring_buffer_t tx_rb;
ring_buffer_t rx_rb;

void usart_init(volatile usart_t* usart, usart_mode_t* mode, uint32_t baud);
void usart_send(volatile usart_t* usart, ring_buffer_t* buffer, const char* string);
void usart_sendbyte(volatile usart_t* usart, ring_buffer_t* buffer, uint8_t byte);
void usart_processrx(ring_buffer_t* buffer);

int main(){

    usart_init(USART0, USART0_MODE, 9600);
    sei();
    ring_buffer_init(&tx_rb);
    ring_buffer_init(&rx_rb);

    setOutput(&DDRH, PH6);

    while(1){
        usart_processrx(&rx_rb);
    

    }
}

void usart_init(volatile usart_t* usart, usart_mode_t* mode, uint32_t baud){
    usart_tx_enable(usart);
    usart_rx_enable(usart);
    usart_enable_rx_complete_isr(usart);
    usart_set_baudrate(usart, mode, baud);
}

void usart_processrx(ring_buffer_t* buffer){
    uint8_t byte;
    while(ring_buffer_getcount(buffer) > 0){
        byte = ring_buffer_read(buffer);
        if (byte == 'l'){
            setHigh(&PORTH, PH6);
        } else {
            setLow(&PORTH, PH6);
        }
    }
}

void usart_send(volatile usart_t* usart, ring_buffer_t* buffer, const char* string){
    while (*string != '\0'){
        ring_buffer_write(buffer, *string);
        string++;
    }
    usart_enable_buffempty_isr(usart);
}

void usart_sendbyte(volatile usart_t* usart, ring_buffer_t* buffer, uint8_t byte){
    usart_enable_buffempty_isr(usart);
    ring_buffer_write(buffer, byte);
}


ISR(USART0_UDRE_vect){
    if(ring_buffer_empty(&tx_rb)){
        usart_disable_buffempty_isr(USART0);
    }
    USART0->UDRn = ring_buffer_read(&tx_rb);
}

ISR(USART0_RX_vect){
    uint8_t data = USART0->UDRn;
    ring_buffer_write(&rx_rb, data);
    if(USART0->UCSRnA & USART_BUFF_EMPTY){
        USART0->UDRn = data;
    }
}