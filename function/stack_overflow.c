//
// Created by haoyu on 9/21/2022.
//
#include <stdio.h>

void print_p(void *p) {
    printf("%p\n", p);
}

void print_lu(long unsigned n) {
    printf("%lu\n", n);
}

void f1(int nums1[]) {

    for (int i = 0; i > -10; i--) nums1[i] = 0;
}


int main() {
    int nums[1];
    printf("sizeof :%lu\n", sizeof(nums));
    f1(nums);
    printf("\n");
    printf("outside nums[-2] :%p\t%d\n", nums - 2, nums[-2]);
    printf("outside nums[-8] :%p\t%d\n", nums - 8, nums[-8]);
}