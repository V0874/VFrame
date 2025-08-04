#include "gpio.h"

void setInput(volatile uint8_t *ddr, int pin){
    *ddr &= ~(1 << pin);
}

void setOutput(volatile uint8_t *ddr, int pin){
    *ddr |= (1 << pin);
}

void setLow(volatile uint8_t *port, int pin){
    *port &= ~(1 << pin);
}

void setHigh(volatile uint8_t *port, int pin){
    *port |= (1 << pin);
}

bool readPin(volatile uint8_t *mainpin, int pin){
   return (*mainpin & (1 << pin)) != 0;
}
void enablePullUp(volatile uint8_t *port, int pin){
    *port |= (1 << pin);
}
void disablePullUp(volatile uint8_t *port, int pin){
    *port & ~(1 << pin);
}

ISR(TIMER0_COMPA_vect){
    setLow(&PORTH, PH6);
}