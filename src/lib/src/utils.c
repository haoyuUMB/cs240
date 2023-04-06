//
// Created by haoyu on 3/9/2023.
//
#include <cs240/utils.h>
#include <stdio.h>

double pi = 3.1416926; // global
static int seed = 3; // static external limit the scope to the current file
int non_static = 3;

extern int add(int a, int b) {
    return a + b;
}

int getSeed() {
    return seed;
}

void setSeed(int a) {
    seed = a;
}

int rand_int() {
    srand(time(NULL));
    return rand();
}

int rand_int_range(int range) {
    static int count = 0;
    srand(time(NULL) + count++);
    return rand() % range;
}

int *rand_int_array_utils(int *const arr, int l, int max) {
    static int count = 0;
    srand(time(NULL) + count++);
    for (int i = 0; i < l; ++i) arr[i] = rand() % max;
    return arr;
}

int **rand_int_matrix_utils(int **matArg, int m, int n, int max) {
    int (*mat)[n] = (int (*)[n]) matArg;
    for (int i = 0; i < m; ++i) {
        rand_int_array_utils(mat[i], n, max);
    }
    return (int **) mat;
}

void print_int_matrix(int **matArg, int m, int n) {
    int (*mat)[n] = (int (*)[n]) matArg;
    for (int i = 0; i < m; ++i) {
        print_int_array(mat[i], n);
    }
    printf("\n");
}

void print_int_array(int *const arr, int l) {
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
