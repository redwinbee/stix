#ifndef stix_vm_h
#define stix_vm_h

#include "chunk.h"

typedef struct {
    Chunk* chunk;
    uint8_t* ip;
} vm_t;

typedef enum {
    INTERPRET_OK,
    INTERPRET_COMPILE_ERROR,
    INTERPRET_RUNTIME_ERROR,
} interpret_result;

void init_vm(void);
void free_vm(void);
interpret_result interpret(Chunk* chunk);
interpret_result run(void);

#endif
