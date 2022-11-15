//
// Created by haoyu on 11/5/22.
//

#include <malloc.h>
#include <string.h>
#include "resizing_array.h"
#include "utils.h"

#define RESIZING_ARRAY "resizing_array.c"

Array new_array(int size) {
    int cap = 5;
    void *data = calloc(cap, size);
    TEST_NULL(data, RESIZING_ARRAY, "new_array");
    return (Array) {data, size, 0, cap};
}

Array *append_array(Array *const arr, void *val) {
    if (arr->length + 1 == arr->capacity) {
        arr->capacity <<= 1;
        arr->data = resize(arr->data, arr->capacity * arr->size);
    }
    memcpy(arr->data + arr->length * arr->size, val, arr->size);
    arr->length++;
    return arr;
}

Array *pop_array(Array *const arr, void *val) {
    if (arr->length == 0) return NULL;
    arr->length--;
    memcpy(val, arr->data + arr->length * arr->size, arr->size);
    if (arr->length <= (arr->capacity >> 1)) {
        arr->capacity >>= 1;
        arr->data = resize(arr->data, arr->capacity * arr->size);
    }
}

void print_array(Array arr) {
    printf("Array data: %p\tlength: %d\tcapacity: %d\tsize: %d\n",
           arr.data, arr.length, arr.capacity, arr.size);
}