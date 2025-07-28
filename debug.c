#include <stdint.h>
#include <stdio.h>

#include "debug.h"
#include "chunk.h"
#include "value.h"

void disassemble_chunk(Chunk *chunk, const char *name) {
    printf("-[ %s ]-\n", name);
    for (int offset = 0; offset < chunk->count;) {
        offset = disassemble_instruction(chunk, offset);
    }
}

int disassemble_instruction(Chunk *chunk, int offset) {
    printf("%04d ", offset);

    // only print the line number for the bytecode if they originate from different lines in source
    if (offset > 0 && chunk->lines[offset] == chunk->lines[offset - 1]) {
        printf("   | ");
    } else {
        printf("%4d ", chunk->lines[offset]);
    }

    uint8_t instruction = chunk->code[offset];
    switch (instruction) {
        case OP_RETURN:
            return simple_instruction("OP_RETURN", offset);
        case OP_NEGATE:
            return simple_instruction("OP_NEGATE", offset);
        case OP_CONSTANT:
            return constant_instruction("OP_CONSTANT", chunk, offset);
        default:
            printf("unkown opcode '%d'", instruction);
            return offset + 1;
    }
}

int simple_instruction(const char* name, int offset) {
    printf("%s\n", name);
    return offset + 1;  // the next instruction is one byte away.
}

int constant_instruction(const char* name, Chunk* chunk, int offset) {
    uint8_t constant = chunk->code[offset + 1];
    printf("%-16s %4d '", name, constant);
    print_value(chunk->constants.values[constant]);
    printf("'\n");
    return offset + 2;  // OP_CONSTANT is a two-byte instruction (opcode, constant index).
}
