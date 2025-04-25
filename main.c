#define F_CPU 16000000UL

#include <avr/io.h>
#include <gpio.h>

int main(void){

setInput(&DDRH, PH4);
setOutput(&DDRH, PH6);



while (1){

  if (readPin(&PINH, PH4)){

    setHigh(&PORTH, PH6);
    
  }

  }
}