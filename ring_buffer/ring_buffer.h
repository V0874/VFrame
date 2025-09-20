#include "../common_defs.h"
#include <util/atomic.h>

#define BUFFER_SIZE 255


typedef struct {
uint8_t buffer[BUFFER_SIZE];
uint8_t* read;
uint8_t* write;
uint8_t count;
} ring_buffer_t;

static inline void ring_buffer_init(ring_buffer_t* const buffer){
    buffer->read = buffer->buffer;
    buffer->write = buffer->buffer;
    buffer->count = 0;
}

static inline uint8_t ring_buffer_getcount(ring_buffer_t* const buffer){
    uint8_t count;
    
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE){
        count = buffer->count;
    }
    return count;
}

static inline bool ring_buffer_full(ring_buffer_t* const buffer){
    return (ring_buffer_getcount(buffer) == BUFFER_SIZE);
}

static inline bool ring_buffer_empty(ring_buffer_t* const buffer){
    return (ring_buffer_getcount(buffer) == 0);
}

static inline uint8_t ring_buffer_read(ring_buffer_t* const buffer){
    uint8_t data = *buffer->read;

    if (++buffer->read == &buffer->buffer[BUFFER_SIZE]){
        buffer->read = buffer->buffer;
    }

    ATOMIC_BLOCK(ATOMIC_RESTORESTATE){
        buffer->count--;
    }
    return data;
}

static inline void ring_buffer_write(ring_buffer_t* const buffer, const uint8_t data){
    *buffer->write = data;

    if (++buffer->write == &buffer->buffer[BUFFER_SIZE]){
        buffer->write = buffer->buffer;
    }

    ATOMIC_BLOCK(ATOMIC_RESTORESTATE){
        buffer->count++;
    }
}

