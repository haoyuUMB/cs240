//
// Created by haoyu on 3/9/2023.
//
#include <stdio.h>


void func(char nums[]) {
    char nums_local[2] = {'c', 'd'};
    for (int i = 0; 1; ++i) {
        printf("main nums and local nums - %d addresses:"
               " %p\t%p\n", i, nums, nums_local + i);
        if (nums_local + i == nums) {
            printf(" Get to the main nums address from local"
                   "the char is %c\n", nums_local[i]);
            printf(" Change them to x and y\n");
            nums_local[i++] = 'x';
            nums_local[i++] = 'y';
            return;
        }

    }
}

void swap_int(int a, int b) {
    printf("local a address and a value: %p and %d\n", &a, a);

    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

void swap_index(int nums[], int i, int j) {
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}

void print_int_array(int nums[], int len) {

    printf("Local nums address: %p\n", nums);


    for (int i = 0; i < len; ++i) {
        printf("%d\t", nums[i]);
    }
    printf("\n");
}


int main(int argc, char *argv[]) {
//    char nums[2] = {'a', 'b'};
//    func(nums);
//    printf(" From main: nums are: %c, %c\n", nums[0], nums[1]);
    int a = 1, b = 2, tmp;
    printf("main a address and a value: %p and %d\n", &a, a);


    swap_int(a, b);

    // array
    int nums[] = {0, 1, 2};
    printf("main nums address: %p\n", nums);


    printf("a:%d  b:%d\n", a, b);

    print_int_array(nums, 3);
    swap_index(nums, 0, 2);
    print_int_array(nums, 3);
}