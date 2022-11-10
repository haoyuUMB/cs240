//
// Created by haoyu on 10/11/22.
//

#include <utils.h>
#include <time.h>
#include <stdlib.h>

int setNthBit(int x, int n) {
    return x | (1 << n - 1);
}

void bin(unsigned n) {
    printf("%11d\t:\t", n);
    unsigned i, j = 0;
    for (i = 1 << 31; i > 0; i = i / 2) {
        (n & i) ? printf("1") : printf("0");
        if ((j + 1) % 8 == 0) printf(" ");
        j++;
    }
    printf("\n");
}

int randInt() {
    srand(time(NULL));
    return rand();
}

int *randIntArray(int *const arr, int l, int max) {
    srand(time(NULL));
    for (int i = 0; i < l; ++i) arr[i] = rand() % max;
    return arr;
}

void print_IntArray(int *const arr, int l) {
    for (int i = 0; i < l; ++i) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void *resize(void *a, int size) {
    a = realloc(a, size);
    TEST_NULL(a, "within utils.c file", "resize function")
}