#include "gpio.h"

void setInput(volatile uint8_t* ddr, int pin){
    *ddr &= ~(1 << pin);
}

void setOutput(volatile uint8_t* ddr, int pin){
    *ddr |= (1 << pin);
}

void setLow(volatile uint8_t* port, int pin){
    *port &= ~(1 << pin);
}
    
void setHigh(volatile uint8_t* port, int pin){
    *port |= (1 << pin);
}

bool readPin(volatile uint8_t* port, int pin){
   return (*port & (1 << pin)) != 0;
}

