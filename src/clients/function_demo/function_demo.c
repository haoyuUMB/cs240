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
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

int main(int argc, char *argv[]) {
//    char nums[2] = {'a', 'b'};
//    func(nums);
//    printf(" From main: nums are: %c, %c\n", nums[0], nums[1]);
    int a = 1, b = 2, tmp;
    swap_int(a, b);
    printf("a:%d  b:%d", a, b);
}