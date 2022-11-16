//
// Created by haoyu on 11/5/22.
//

#ifndef CS240_RESIZING_ARRAY_H
#define CS240_RESIZING_ARRAY_H

#define COMPARATOR int (*com)(void *const a, void *const b, void *const data)


typedef struct array_resizing {
    void *data;
    int type, length, capacity;
} Array;

Array new_Array(int type);

Array new_Array_length(int type, int len);

Array *append_array(Array *const arr, void *val);

Array *pop_array(Array *const arr, void *val);

Array rand_Array_int(int len, int range);

void print_Array_int(Array arr);

Array copy_Array(Array arr);

void swap_Array_items(Array *const arr, int i, int j);

int compare_Array_items(Array *const arr, int i, int j, COMPARATOR);

Array *shuffle_array(Array *const arr);

int min_index_Array(Array *const arr, COMPARATOR);

int min_index_Array_range(Array *const arr, int i, int j, COMPARATOR);


Array *selection_sort_Array(Array *const arr, COMPARATOR);

void copy_Array_item(Array *const des, Array *const src, int i, int j);

Array *merge_array(Array *const arr, Array *const aux, int lo, int mid, int hi, COMPARATOR);

Array *mergesort_array(Array *const arr, int (*com)(void *const a, void *const b, void *const data));


void *index_address_array(Array *const arr, int i);

void print_Array_attributes(Array arr);

#endif //CS240_RESIZING_ARRAY_H
