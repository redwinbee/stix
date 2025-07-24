#include "chunk.h"
#include "common.h"
#include "value.h"
#include <stdio.h>
#include "vm.h"

vm_t vm;

void init_vm(void) {

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
        uint8_t instruction;
        switch (instruction = READ_BYTE()) {
            case OP_RETURN: {
                return INTERPRET_OK;
            }

            case OP_CONSTANT: {
                value_t constant = READ_CONSTANT();
                print_value(constant);
                printf("\n");
                break;
            }
        }
    }

    #undef READ_BYTE
}
