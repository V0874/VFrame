#include "ring_buffer.h"

void ring_buffer_init(volatile ring_buffer_t* buffer){
    buffer->Read = 0;
    buffer->Write = 0;
    buffer->Count = 0;
}

void ring_buffer_write(volatile ring_buffer_t* buffer, uint8_t data){
    
    buffer->Count++;
}

void ring_buffer_read(volatile ring_buffer_t* buffer, uint8_t data){
    
    buffer->Count--;
}

uint8_t ring_buffer_count(volatile ring_buffer_t* buffer){
    return buffer->Count;
}


