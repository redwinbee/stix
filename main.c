#include "common.h"
#include "chunk.h"
#include "debug.h"
#include "vm.h"

int main(int argc, const char* argv[]) {
    init_vm();

    Chunk chunk;
    init_chunk(&chunk);

    // test the storing of a constant in a chunk
    // line numbers are arbitrary and only for testing in the meantime
    int constant = add_constant(&chunk, 1.2);
    write_chunk(&chunk, OP_CONSTANT, 1);
    write_chunk(&chunk, constant, 1);

    write_chunk(&chunk, OP_RETURN, 1);
    disassemble_chunk(&chunk, "test chunk");

    interpret(&chunk);

    free_vm();
    free_chunk(&chunk);

    return 0;
}
