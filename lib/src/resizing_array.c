//
// Created by haoyu on 11/5/22.
//

#include <malloc.h>
#include <string.h>
#include "resizing_array.h"
#include "utils.h"

#define RESIZING_ARRAY "resizing_array.c"

Array new_Array(int type) {
    int cap = 5;
    void *data = calloc(cap, type);
    TEST_NULL(data, RESIZING_ARRAY, "new_Array");
    return (Array) {data, type, 0, cap};
}

Array new_Array_length(int type, int len) {
    int cap = len;
    void *data = calloc(cap, type);
    TEST_NULL(data, RESIZING_ARRAY, "new_Array");
    return (Array) {data, type, len, cap};
}

Array *append_array(Array *const arr, void *val) {
    if (arr->length + 1 == arr->capacity) {
        arr->capacity <<= 1;
        arr->data = resize(arr->data, arr->capacity * arr->type);
    }
    memcpy(arr->data + arr->length * arr->type, val, arr->type);
    arr->length++;
    return arr;
}

Array *pop_array(Array *const arr, void *val) {
    if (arr->length == 0) return NULL;
    arr->length--;
    memcpy(val, arr->data + arr->length * arr->type, arr->type);
    if (arr->length <= (arr->capacity >> 1)) {
        arr->capacity >>= 1;
        arr->data = resize(arr->data, arr->capacity * arr->type);
    }
}


Array rand_Array_int(int len, int range) {
    Array arr = new_Array_length(sizeof(int), len);
    rand_int_array_utils(arr.data, len, range);
    return arr;
}

void print_Array_int(Array arr) {
    printf("Array type: %d\tlength: %d\tcapacity: %d\taddress: %p\ndata:\t",
           arr.type, arr.length, arr.capacity, arr.data);
    int *data = arr.data;
    for (int i = 0; i < arr.length; ++i) {
        printf("%d\t", data[i]);
    }
    printf("\n");
}

Array copy_Array(Array arr) {
    int size = arr.type * arr.capacity;
    void *data = malloc(arr.type * arr.capacity);
    TEST_NULL(data, RESIZING_ARRAY, "copy_arr");
    memcpy(data, arr.data, size);
    return (Array) {data, arr.type, arr.length, arr.capacity};
}

void swap_Array_items(Array *const arr, int i, int j) {
    memswap(index_address_array(arr, i),
            index_address_array(arr, j), arr->type);
}

int compare_Array_items(Array *const arr, int i, int j, COMPARATOR) {
    return com(arr->data + i * arr->type, arr->data + j * arr->type, NULL);
}


Array *shuffle_array(Array *const arr) {
    for (int i = 0, j; i < arr->length; ++i) {
        j = rand_int_range(arr->length - i);
        swap_Array_items(arr, i, i + j);
    }
    return arr;
}

int min_index_Array(Array *const arr, COMPARATOR) {
    int min = 0, flag;
    for (int i = 0; i < arr->length; ++i) {
        flag = compare_Array_items(arr, min, i, com);
        if (flag > 0) min = i;
    }
    return min;
}

/**
 *
 * @param arr
 * @param i
 * @param j not inclusive
 * @param com
 * @return
 */
int min_index_Array_range(Array *const arr, int i, int j, COMPARATOR) {
    int min = i, flag;
    for (int k = i; k < j; ++k) {
        flag = compare_Array_items(arr, min, k, com);
        if (flag > 0) min = k;
    }
    return min;
}

Array *selection_sort_Array(Array *const arr, COMPARATOR) {
    for (int i = 0; i < arr->length; ++i) {
        int min = min_index_Array_range(arr, i, arr->length, com);
        swap_Array_items(arr, i, min);
    }
}


int compare_Arrays_items(Array *const des, Array *const src, int i, int j, COMPARATOR) {
    return com(des->data + i * des->type, src->data + j * des->type, NULL);
}


void copy_Array_item(Array *const des, Array *const src, int i, int j) {
    // a lot of checks should be here
    memcpy(des->data + i * des->type, src->data + j + des->type, des->type);
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
    int size = (hi - lo) * arr->type, start = lo * arr->type;
    memcpy(aux->data + start, arr->data + start, size);

    print_Array_attributes(*arr);
//    print_int_array(arr->data, arr->length);
    printf("---");
    print_Array_attributes(*aux);
//    print_int_array(aux->data, aux->length);


    int i = lo, j = hi;
    for (int k = lo; k < hi; ++k) {
        if (i >= mid) copy_Array_item(arr, aux, k, j++);
        else if (j >= hi) copy_Array_item(arr, aux, k, i++);
        else if (com(arr->data + i * arr->type, aux->data + j * aux->type, NULL) <= 1)
            copy_Array_item(arr, aux, k, i++);
        else copy_Array_item(arr, aux, k, j++);
    }
}


Array *mergesort_array(Array *const arr, COMPARATOR) {
    Array aux_array = copy_Array(*arr);
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


void *index_address_array(Array *const arr, int i) {
    if (i >= arr->length) return NULL;
    return arr->data + i * arr->type;
}

void print_Array_attributes(Array arr) {
    printf("Array data: %p\tlength: %d\tcapacity: %d\tsize: %d\n",
           arr.data, arr.length, arr.capacity, arr.type);
}