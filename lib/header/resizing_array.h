//
// Created by haoyu on 11/5/22.
//

#ifndef CS240_RESIZING_ARRAY_H
#define CS240_RESIZING_ARRAY_H
typedef struct array_int_resizing {
    int *array, length, capacity;
} ArrayIntR;

ArrayIntR new_ArrayIntR();

#endif //CS240_RESIZING_ARRAY_H
