#include "../common_defs.h"
#include <util/atomic.h>

#define BUFFER_SIZE 255


typedef struct {
uint8_t buffer[BUFFER_SIZE];
uint8_t* read;
uint8_t* write;
uint8_t count;
} ring_buffer_t;

void ring_buffer_init(ring_buffer_t* const buffer);

uint8_t ring_buffer_getcount(ring_buffer_t* const buffer);

bool ring_buffer_full(ring_buffer_t* const buffer);

bool ring_buffer_empty(ring_buffer_t* const buffer);

uint8_t ring_buffer_read(ring_buffer_t* const buffer);

void ring_buffer_write(ring_buffer_t* const buffer, const uint8_t data);