#include <stdio.h>
#include "cs240/utils.h"


int *rand_array(int len) {
    int nums[len];
    rand_int_array_utils(nums, len, 10);
    print_int_array(nums, len);
    printf("%p\n", nums);
    return nums;
}

int factorial(int n) {
    if (n == 1) return n;
    return n * factorial(n - 1);
}

int main(int argc, char *argv[]) {

//    int len = 10;
//    int *nums = rand_array(len);
//    factorial(100);
//    print_int_array(nums, len);

    for (int i = 0; i < 10; ++i) {
        printf("%2d: %d\n", i, i & -i);
    }
    int i = 0;
    while (i < 20) printf("%d: ", i = i | (i + 1));
    i = 2;
    while (i < 20) printf("%d: ", i = i | (i + 1));
    return 0;
}