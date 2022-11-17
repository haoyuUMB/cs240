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

void print_Array_int_range(Array arr, int lo, int hi) {
    printf("Array type: %d\tlo: %d\thi: %d\t\ndata:\t",
           arr.type, lo, hi, arr.data);
    int *data = arr.data;
    for (int i = lo; i < hi; ++i) {
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

void copy_2Arrays_range(Array *const des, Array *const src, int di, int si, int len) {
    // a lot of checks should be here
    memcpy(des->data + di * des->type, src->data + si * des->type, len * des->type);
}

int compare_2Arrays_items(Array *const des, Array *const src, int i, int j, COMPARATOR) {
    return com(des->data + i * des->type, src->data + j * des->type, NULL);
}

int is_sorted_Array_range(Array *const arr, int lo, int hi, COMPARATOR) {
    for (int i = lo; i < hi - 1; ++i) {
        if (compare_Array_items(arr, i, i + 1, com) > 0) return 0;
    }
    return 1;
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
Array *merge_Array_range(Array *const arr, Array *const aux, int lo, int mid, int hi, COMPARATOR) {
    copy_2Arrays_range(aux, arr, lo, lo, hi - lo);
    int i = lo, j = mid;
    for (int k = lo; k < hi; ++k) {
        if (i >= mid) copy_2Arrays_range(arr, aux, k, j++, 1);
        else if (j >= hi) copy_2Arrays_range(arr, aux, k, i++, 1);
        else if (compare_2Arrays_items(aux, aux, i, j, com) <= 0)
            copy_2Arrays_range(arr, aux, k, i++, 1);
        else copy_2Arrays_range(arr, aux, k, j++, 1);
    }
    int flag = is_sorted_Array_range(arr, lo, hi, com);
    if (flag) return arr;
    fprintf(stderr, "Error: range [%d, %d) is not sorted\n", lo, hi);
    print_Array_int_range(*aux, lo, hi);
    print_Array_int_range(*arr, lo, hi);
    exit(EXIT_FAILURE);
}


Array *mergesort_Array(Array *const arr, COMPARATOR) {
    Array aux = copy_Array(*arr);
    Array *p_aux = &aux;

    for (int len = 1; len < arr->length; len <<= 1) {
        for (int lo = 0; lo < arr->length - len; lo += (len << 1)) {
            int mid = lo + len;
            int hi = lo + (len << 1);
            if (hi > arr->length) hi = arr->length;
            merge_Array_range(arr, p_aux, lo, mid, hi, com);
        }
    }
    free(aux.data);
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