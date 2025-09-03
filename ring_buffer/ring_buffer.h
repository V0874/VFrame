#include "common_defs.h"

#define BUFFER_SIZE 255

typedef struct {
volatile uint8_t Buffer[BUFFER_SIZE];
volatile uint8_t* Read;
volatile uint8_t* Write;
volatile uint8_t Count;
} ring_buffer_t;

void ring_buffer_init(volatile ring_buffer_t* buffer);

void ring_buffer_write(volatile ring_buffer_t* buffer, uint8_t data);

void ring_buffer_read(volatile ring_buffer_t* buffer, uint8_t data);

uint8_t ring_buffer_count(volatile ring_buffer_t* buffer);