#include <stdlib.h>

#include "memory.h"

void* reallocate(void* pointer, size_t old_size, size_t new_size) {
    if (new_size == 0) {
        free(pointer);
        return NULL;
    }

    void* result = realloc(pointer, new_size);
    if (result == NULL) exit(1);    /* can't continue if we don't have the requsted memory. */
    return result;
}
