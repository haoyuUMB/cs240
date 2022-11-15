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
    print_IntArray(arr.data, arr.length);
    int val;
    for (int i = 0; i < 5; ++i) {
        pop_array(p_arr, &val);
    }
    print_array(arr);
    print_IntArray(arr.data, arr.length);
}

int main() {
    int_array_demo();
}