//
// Created by haoyu on 9/19/2022.
//
#include <stdio.h>

void print_p(void *p) {
    printf("%p\n", p);
}

void print_lu(long unsigned n) {
    printf("%lu\n", n);
}

void f1(int nums1[]) {
    int nums2[1] = {100};
    printf("sizeof :%lu\n", sizeof(nums1));
    print_p(nums1);
    print_p(nums2);
    print_lu(nums1 - nums2); // pointer arithmetic: the type info is playing in part
    printf("inside nums1[0]  :%p\t%d\n", &nums1[0], nums1[0]);
    printf("inside nums1[-2] :%p\t%d\n", &nums1[-1], nums1[-1]);
    printf("inside nums1[-2] :%p\t%d\n", &nums1[-2], nums1[-2]);
    printf("inside nums1[-8] :%p\t%d\n", &nums1[-8], nums1[-8]);
    printf("inside nums2[0]  :%p\t%d\n", nums2, nums2[0]);

}


int main() {
    int nums[1];
    printf("sizeof :%lu\n", sizeof(nums));
    f1(nums);
    printf("\n");
    printf("outside nums[-2] :%p\t%d\n", nums - 2, nums[-2]);
    printf("outside nums[-8] :%p\t%d\n", nums - 8, nums[-8]);
}