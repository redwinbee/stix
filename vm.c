#include "chunk.h"
#include "common.h"
#include "debug.h"
#include "value.h"
#include <stdio.h>
#include "vm.h"

vm_t vm;

void init_vm(void) {
    reset_stack();
}

void free_vm(void) {

}

interpret_result interpret(Chunk *chunk) {
    vm.chunk = chunk;
    vm.ip = vm.chunk->code;
    return run();
}

interpret_result run(void) {
    #define READ_BYTE() (*vm.ip++)
    #define READ_CONSTANT() (vm.chunk->constants.values[READ_BYTE()])

    for (;;) {
        #ifdef DEBUG_TRACE_EXECUTION
            printf("\t");
            for (value_t* slot = vm.stack; slot < vm.stack_top; slot++) {
                printf("* [");
                print_value(*slot);
                printf("]");
            }
            printf("\n");

            disassemble_instruction(vm.chunk, (int)(vm.ip - vm.chunk->code));
        #endif

        uint8_t instruction;
        switch (instruction = READ_BYTE()) {
            case OP_RETURN: {
                print_value(pop());
                printf("\n");
                return INTERPRET_OK;
            }

            case OP_NEGATE: {
                push(-pop());
                break;
            }

            case OP_CONSTANT: {
                value_t constant = READ_CONSTANT();
                push(constant);
                break;
            }
        }
    }

    #undef READ_BYTE
    #undef READ_CONSTANT
}

void reset_stack(void) {
    vm.stack_top = vm.stack;
}

void push(value_t value) {
    *vm.stack_top = value;
    vm.stack_top++;
}

value_t pop(void) {
    vm.stack_top--;
    return *vm.stack_top;
}
