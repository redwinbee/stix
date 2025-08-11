#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"
#include "vm.h"

/* todo: magic numbers. */
int main(int argc, const char *argv[]) {
    init_vm();

    if (argc == 1) {
        repl();
    } else if (argc == 2) {
        run_file(argv[1]);
    } else {
        fprintf(stderr, "usage: stix [path]\n");
        exit(64);
    }

    free_vm();
    return 0;
}

void repl(void) {
    char line[1024];
    for (;;) {
        printf("> ");

        if (!fgets(line, sizeof(line), stdin)) {
            printf("\n");
            break;
        }

        interpret(line);
    }
}

void run_file(const char *path) {
    char *source = read_file(path);
    interpret_result result = interpret(source);
    free(source);

    if (result == INTERPRET_COMPILE_ERROR)
        exit(65);
    if (result == INTERPRET_RUNTIME_ERROR)
        exit(70);
}

char *read_file(const char *path) {
    FILE *file = fopen(path, "rb");
    if (file == NULL) {
        fprintf(stderr, "failed to open file `%s`.\n", path);
        exit(74);
    }

    fseek(file, 0L, SEEK_END);
    size_t fsize = ftell(file);
    rewind(file);

    char *buf = (char *)malloc(fsize + 1);
    if (buf == NULL) {
        fprintf(stderr, "not enough memory to read `%s`.\n", path);
        exit(74);
    }
    size_t bytes = fread(buf, sizeof(char), fsize, file);
    if (bytes < fsize) {
        size_t missing = fsize - bytes;
        fprintf(stderr, "failed to read all bytes in `%s` (missing %zu byte(s)).\n", path, missing);
        exit(74);
    }
    buf[bytes] = '\0';

    fclose(file);
    return buf;
}
