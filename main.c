#include "gpio/gpio.h"
#include "usart/usart.h"

#define F_CPU 16000000UL
#define BAUD 9600
#define UBRR ((F_CPU / (16UL * BAUD)) - 1)



int main(void){

// enable transmission and receiving 
UCSR0B |= (1 << TXEN0) | (1 << RXEN0);
    
//set async mode for usart // disable parity mode // set 1 stop bit - respectively
UCSR0C &= ~(1 << UMSEL00) | (1 << UMSEL01) | (1 << UPM00) | (1 << UPM01) | (1 << USBS0);

// set character size to 8 bit
UCSR0C |= (1 << UCSZ00) | (1 << UCSZ01);

UCSR0B &= ~(1 << UCSZ02);

// set transmission speed to double
UCSR0A |= (1 << U2X0);

// set baud rate
UBRR0 = UBRR;

usart_send("hello");
    
setOutput(&DDRH, PH6);

// initialize timer & compare match value
TCNT0 = 0;
OCR0A = 249;

// enable global interrupts
SREG |= (1 << SREG_I);

// set normal operation / no waveform on compare match
TCCR0A &= ~(1 << COM0A1) | (1 << COM0A0);

// set CTC mode 
TCCR0A &= ~(1 << WGM00);
TCCR0A |= (1 << WGM01);
TCCR0B &= ~(1 << WGM02);

// set prescaler to 64
TCCR0B |= (1 << CS00) | (1 << CS01);

// enable compare match interrupt
TIMSK0 |= (1 << OCIE0A);






while (1){ 
       setHigh(&PORTH, PH6);
  }
}