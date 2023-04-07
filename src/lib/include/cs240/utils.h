//
// Created by haoyu on 3/1/2023.
//

#ifndef CS240_UTILS_H
#define CS240_UTILS_H

#include <time.h>
#include <stdlib.h>


#define max(a, b) (a) >= (b) ? a : b
#define PI 3.1416926

extern double pi;

#define TEST_NULL(p, file, func) if (NULL==p){ \
    fprintf(stderr, "Memory allocation failed in %s:%s\n",file, func);\
    exit(EXIT_FAILURE); \
}
#define TEST_OVERFLOW(val, file, func) if (val < 0){ \
    fprintf(stderr, "Integer overflow in %s:%s\n",file, func);\
    exit(EXIT_FAILURE); \
}


int add(int a, int b);

int rand_int();

int rand_int_range(int range);

int *rand_int_array_utils(int *arr, int l, int max);

int **rand_int_matrix_utils(int **arr, int m, int n, int max);

void print_int_matrix(int **matArg, int m, int n);

void print_int_array(int *const arr, int l);

void print_long_array(long *const arr, int l);

void *resize(void *a, int size);

void memswap(void *const a, void *const b, int size);

#endif //CS240_UTILS_H