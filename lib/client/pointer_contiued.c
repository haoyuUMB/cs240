#include <malloc.h>

//
// Created by haoyu on 10/20/22.
//
int main() {
    int (*arr)[3] = calloc(2, 3 * sizeof(int));
    printf("%p\n", arr[1]);
    printf("%p\n", arr[0]);
    printf("%ld\n", arr[1] - arr[0]);
    printf("%ld\n", &arr[1] - &arr[0]);
}