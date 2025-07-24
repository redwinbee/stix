#ifndef stix_chunk_h
#define stix_chunk_h

#include "common.h"
#include "value.h"
#include <stdint.h>

typedef enum {
    OP_CONSTANT,    /* store a constant value. */
    OP_RETURN,      /* return from the current function. */
} OpCode;

typedef struct {
    int capacity;           /* max amount of operations. */
    int count;              /* current number of operations. */
    uint8_t* code;          /* operation code. */
    int* lines;             /* array of lines in the bytecode. */
    value_array_t constants;   /* immediate values accessible to this chunk. */
} Chunk;

void init_chunk(Chunk* chunk);
void free_chunk(Chunk* chunk);
void write_chunk(Chunk* chunk, uint8_t byte, int line);
int add_constant(Chunk* chunk, value_t value);

#endif
