#ifndef stix_debug_h
#define stix_debug_h

#include "chunk.h"

int constant_instruction(const char* name, Chunk* chunk, int offset);
void disassemble_chunk(Chunk* chunk, const char* name);
int disassemble_instruction(Chunk* chunk, int offset);
int simple_instruction(const char* name, int offset);

#endif
