#pragma once
#include "../common_defs.h"

void setInput(volatile uint8_t* ddr, int pin);
void setOutput(volatile uint8_t* ddr, int pin);
void setLow(volatile uint8_t* port, int pin);
void setHigh(volatile uint8_t* port, int pin);
bool readPin(volatile uint8_t* mainpin, int pin);