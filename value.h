#ifndef stix_value_h
#define stix_value_h

#include "common.h"

typedef double value_t; /* the internal representation for this value. */

typedef struct {
    int capacity;       /* the maximum amount of immediates this array can hold. */
    int count;          /* the current number of immediate values stored. */
    value_t* values;    /* the list of immediate values. */
} ValueArray;

void init_value_array(ValueArray* array);
void write_value_array(ValueArray* array, value_t value);
void free_value_array(ValueArray* array);

#endif
