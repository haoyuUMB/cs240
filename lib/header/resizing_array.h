//
// Created by haoyu on 11/5/22.
//

#ifndef CS240_RESIZING_ARRAY_H
#define CS240_RESIZING_ARRAY_H

#define COMPARATOR int (*com)(void *const a, void *const b, void *const data)


typedef struct array_resizing {
    void *data;
    int size, length, capacity;
} Array;

Array new_array(int size);

Array copy_array(Array *const arr);

void copy_item_array(Array *const des, Array *const src, int i, int j);


Array *append_array(Array *const arr, void *val);

Array *pop_array(Array *const arr, void *val);

Array *shuffle_array(Array *const arr);

Array *merge_array(Array *const arr, Array *const aux, int lo, int mid, int hi, COMPARATOR);

Array *mergesort_array(Array *const arr, int (*com)(void *const a, void *const b, void *const data));

void swap_array(Array *const arr, int i, int j);

void *index_address_array(Array *const arr, int i);

void print_array(Array arr);

#endif //CS240_RESIZING_ARRAY_H
