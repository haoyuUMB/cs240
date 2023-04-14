#include <stdio.h>
#include "cs240/utils.h"

// what is 1, 0

// why cannot > <
int intCompare1(const int *a, const int *b) {
    if (*a > *b) return 1;
    if (*a < *b) return -1;
    return 0;

//    return *a - *b;
}

int intCompare(const void *a, const void *b) {

    int *pa = (int *) a;
    int *pb = (int *) b;
    return *pa - *pb;

    return *(int *) a - *(int *) b;
}

int longlongCompare(const long long *a, const long long *b) {
    return (int) (*a - *b);
}

/**
 * return the index of the minimum value of  generic array, with its comparator
 * @param a
 * @param size
 * @param compare
 * @return
 */
int minGeneric(const void *a, int len, int size, int (*compare)(const void *, const void *)) {
    int res = 0;
    for (int i = 1; i < len; ++i) {
        if (compare(a + i * size, a + res * size) < 0) res = i;
    }
    return res;
}


int main(int argc, char *argv[]) {
    int len = 10;
    int nums[len];
    rand_int_array_utils(nums, len, 20);
    print_int_array(nums, len);
    qsort(nums, len, sizeof(int), (int (*)(const void *, const void *)) intCompare1);
    qsort(nums, len, sizeof(int), intCompare);
    print_int_array(nums, len);

    long long nums_long[len];
    qsort(nums_long, len, sizeof(long long), (int (*)(const void *, const void *)) longlongCompare);

    rand_int_array_utils(nums, len, 20);
    print_int_array(nums, len);
    printf("min index is: %d", minGeneric(nums, len, sizeof(int), intCompare));


    return 0;
}