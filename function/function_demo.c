
#include <stdio.h>

void print_int(int a) {
    printf("%d\n", a);
}

int swap(int a, int b) {
    int tmp = a;
    a = b;
    b = tmp;
    printf("inside a: %d\n", a);
    printf("inside b: %d\n", b);
}

int swap_ref(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void add1(int nums[], int len) {
    nums[0] += 1; // <==> nums[0] = nums[0] + 2;  nums[0]++;
    printf("add1: nums add: %p\n", nums);
    printf("add1: nums add: %lu\n", sizeof(nums));
}

int main() {
    int a = 1, b = -1;
    swap(a, b);
    swap_ref(&a, &b);
    printf("outside a: %d\n", a);
    printf("outside b: %d\n", b);

    int nums1[] = {1, 2, 3};
    add1(nums1, 3);
    printf("nums1[0]: %d\n", nums1[0]);


    printf("main: nums1 add: %p\n", nums1);
    printf("main: nums1 add: %lu\n", sizeof(nums1));


}