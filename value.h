#ifndef stix_value_h
#define stix_value_h

#include "common.h"

typedef double value_t; /* the internal representation for this value. */

typedef struct {
    int capacity;    /* the maximum amount of immediates this array can hold. */
    int count;       /* the current number of immediate values stored. */
    value_t *values; /* the list of immediate values. */
} value_array_t;

void init_value_array(value_array_t *array);
void write_value_array(value_array_t *array, value_t value);
void free_value_array(value_array_t *array);
void print_value(value_t value);

#endif
