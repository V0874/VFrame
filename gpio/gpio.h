#pragma once
#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>
#include <avr/interrupt.h>

void setInput(volatile uint8_t* ddr, int pin);
void setOutput(volatile uint8_t* ddr, int pin);
void setLow(volatile uint8_t* port, int pin);
void setHigh(volatile uint8_t* port, int pin);
bool readPin(volatile uint8_t* mainpin, int pin);