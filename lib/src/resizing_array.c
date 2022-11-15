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

Array copy_array(Array *const arr) {
    int size = arr->size * arr->capacity;
    void *data = malloc(arr->size * arr->capacity);
    TEST_NULL(data, RESIZING_ARRAY, "copy_arr");
    memcpy(data, arr->data, size);
    return (Array) {data, arr->size, arr->length, arr->capacity};
}

void copy_item_array(Array *const des, Array *const src, int i, int j) {
    // a lot of checks should be here
    memcpy(des->data + i * des->size, src->data + j + des->size, des->size);
}

int compare_item_array(Array *const des, Array *const src, int i, int j, COMPARATOR) {
    return com(des->data + i * des->size, src->data + j * des->size, NULL);
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


Array *shuffle_array(Array *const arr) {
    for (int i = 0, j; i < arr->length; ++i) {
        j = rand_int_range(arr->length - i);
        swap_array(arr, i, i + j);
    }
    return arr;
}

/**
 *
 * @param arr
 * @param aux
 * @param lo : start index of first array
 * @param mid : start index of second array
 * @param hi : next index after the second array
 * @param com
 * @return
 */
Array *merge_array(Array *const arr, Array *const aux, int lo, int mid, int hi, COMPARATOR) {
    int size = (hi - lo) * arr->size, start = lo * arr->size;
    memcpy(aux->data + start, arr->data + start, size);

    print_array(*arr);
    print_int_array(arr->data, arr->length);
    printf("---");
    print_array(*aux);
    print_int_array(aux->data, aux->length);


    int i = lo, j = hi;
    for (int k = lo; k < hi; ++k) {
        if (i >= mid) copy_item_array(arr, aux, k, j++);
        else if (j >= hi) copy_item_array(arr, aux, k, i++);
        else if (com(arr->data + i * arr->size, aux->data + j * aux->size, NULL) <= 1)
            copy_item_array(arr, aux, k, i++);
        else copy_item_array(arr, aux, k, j++);
    }
}


Array *mergesort_array(Array *const arr, COMPARATOR) {
    Array aux_array = copy_array(arr);
    Array *aux = &aux_array;

    for (int len = 1; len < arr->length; len <<= 1) {
        for (int lo = 0; lo < arr->length - len; lo += (len << 1)) {
            int mid = lo + len;
            int hi = lo + (len << 1);
            if (hi > arr->length) hi = arr->length;
            merge_array(arr, aux, lo, mid, hi, com);
        }
    }
    free(aux_array.data);
    return arr;
}


void swap_array(Array *const arr, int i, int j) {
    memswap(index_address_array(arr, i),
            index_address_array(arr, j), arr->size);
}

void *index_address_array(Array *const arr, int i) {
    if (i >= arr->length) return NULL;
    return arr->data + i * arr->size;
}

void print_array(Array arr) {
    printf("Array data: %p\tlength: %d\tcapacity: %d\tsize: %d\n",
           arr.data, arr.length, arr.capacity, arr.size);
}