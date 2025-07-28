#ifndef stix_vm_h
#define stix_vm_h

#include "chunk.h"
#include "value.h"

#define STACK_MAX 256

typedef struct {
    Chunk* chunk;
    uint8_t* ip;
    value_t stack[STACK_MAX];
    value_t* stack_top;
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
void reset_stack(void);
void push(value_t valut);
value_t pop(void);

#endif
