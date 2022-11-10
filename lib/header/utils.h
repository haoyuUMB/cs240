//
// Created by haoyu on 10/11/22.
//

#ifndef CS240_UTILS_H
#define CS240_UTILS_H

#include <stdio.h>
#include <utils.h>
#include <time.h>
#include <stdlib.h>

#define TEST_NULL(p, file, func) if (NULL==p){ \
    fprintf(stderr, "Memory allocation failed in %s:%s\n",file, func);\
    exit(1); \
}
#define TEST_OVERFLOW(val, file, func) if (val < 0){ \
    fprintf(stderr, "Integer overflow in %s:%s\n",file, func);\
    exit(1); \
}

void bin(unsigned n);

int randInt();

int *randIntArray(int *const arr, int l, int max);

void print_IntArray(int *const arr, int l);

void *resize(void *a, int size);

#endif //CS240_UTILS_H
