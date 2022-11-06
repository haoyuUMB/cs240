//
// Created by haoyu on 11/5/22.
//

#include <malloc.h>
#include "resizing_array.h"
#include "utils.h"

#define SRC "resizing_array.c"

ArrayIntR new_ArrayIntR() {
    return (ArrayIntR) {malloc(sizeof(int)), 0, 10};
}

ArrayIntR *append_ArrayIntR(ArrayIntR *const arr, int val) {
    if (arr->length + 1 == arr->capacity) {
        arr->capacity <<= 1;
        TEST_OVERFLOW(arr->capacity, SRC, "append_ArrayIntR");
        arr->array = realloc(arr->array, arr->capacity);
        TEST_NULL(arr->array, SRC, "append_ArrayIntR");
    }
    arr->array[arr->length++] = val;
    return arr;
}