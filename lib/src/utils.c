//
// Created by haoyu on 10/11/22.
//

#include <utils.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define UTILS "utils.c"

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

int rand_int() {
    srand(time(NULL));
    return rand();
}

int rand_int_range(int range) {
    srand(time(NULL));
    return rand() % range;
}

int *rand_int_array_utils(int *const arr, int l, int max) {
    srand(time(NULL));
    for (int i = 0; i < l; ++i) arr[i] = rand() % max;
    return arr;
}

void print_int_array_utils(int *const arr, int l) {
    for (int i = 0; i < l; ++i) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void print_long_array(long *const arr, int l) {
    for (int i = 0; i < l; ++i) {
        printf("%ld\t", arr[i]);
    }
    printf("\n");
}

void *resize(void *a, int size) {
    a = realloc(a, size);
    TEST_NULL(a, "within utils.c file", "resize function");
    TEST_OVERFLOW(a, UTILS, "resize");
    return a;
}

// this is better than alloc, since as an utils function
// this may call very frequently, and stack memory is
// the efficient and clean choice for temp data storage
void memswap(void *const a, void *const b, int size) {
    char tmp[size];
    memcpy(tmp, b, size);
    memcpy(b, a, size);
    memcpy(a, tmp, size);
}