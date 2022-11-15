#include "resizing_array.h"
#include "utils.h"

//
// Created by haoyu on 11/14/22.
//
void int_array_demo() {
    Array arr = new_array(sizeof(int));
    Array *p_arr = &arr;
    print_array(arr);
    for (int i = 0; i < 10; ++i) {
        append_array(p_arr, &i);
    }
    print_array(arr);
    print_int_array(arr.data, arr.length);
    int val;
    for (int i = 0; i < 5; ++i) {
        pop_array(p_arr, &val);
    }
    print_array(arr);
    print_int_array(arr.data, arr.length);
}

void long_array_demo() {
    Array arr = new_array(sizeof(long));
    Array *p_arr = &arr;
    print_array(arr);
    for (long i = 0; i < 10; ++i) {
        append_array(p_arr, &i);
    }
    print_array(arr);
    print_int_array(arr.data, arr.length);
    long val;
    for (int i = 0; i < 5; ++i) {
        pop_array(p_arr, &val);
    }
    print_array(arr);
    print_long_array(arr.data, arr.length);
}

void shuffle_demo() {
    Array arr = new_array(sizeof(int));
    Array *p_arr = &arr;
    for (int i = 0; i < 10; ++i) {
        append_array(p_arr, &i);
    }
    print_array(arr);
    print_int_array(arr.data, arr.length);
    shuffle_array(p_arr);

    print_array(arr);
    print_int_array(arr.data, arr.length);

}

int int_comparator(void *const a, void *const b, void *const data) {
    return *(int *) a - *(int *) b;
}

void merge_sort_demo() {
    Array arr = new_array(sizeof(int));
    Array *p_arr = &arr;
    for (int i = 0; i < 10; ++i) {
        append_array(p_arr, &i);
    }
    shuffle_array(p_arr);
    print_array(arr);
    print_int_array(arr.data, arr.length);

    mergesort_array(p_arr, int_comparator);
    print_array(arr);
    print_int_array(arr.data, arr.length);
}

int main() {
//    int_array_demo();
//    long_array_demo();
//    shuffle_demo();
    merge_sort_demo();

    int arr[] = {1, 2};
    memswap(arr, arr + 1, 4);
    print_int_array(arr, 2);


}