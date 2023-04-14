#include <stdio.h>
#include "cs240/utils.h"


int *rand_array(int len) {
    int nums[len]; // have to use heap memory
    rand_int_array_utils(nums, len, 10);
    print_int_array(nums, len);
    printf("%p\n", nums);
    return nums;
}

int *rand_array_heap(int len) {
    int *nums = calloc(10, sizeof(int)); // have to use heap memory
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

    int len = 10;
//    int *nums = rand_array(len);
    int *nums = rand_array_heap(len);
    printf("%p\n", nums);
    factorial(100);
    print_int_array(nums, len);
}