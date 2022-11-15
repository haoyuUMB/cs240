//
// Created by haoyu on 11/5/22.
//

#ifndef CS240_RESIZING_ARRAY_H
#define CS240_RESIZING_ARRAY_H
typedef struct array_int_resizing {
    void *data;
    int size, length, capacity;
} Array;

Array new_array(int size);

Array *append_array(Array *const arr, void *val);

Array *pop_array(Array *const arr, void *val);

void print_array(Array arr);

#endif //CS240_RESIZING_ARRAY_H
