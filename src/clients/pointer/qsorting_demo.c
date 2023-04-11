#include <stdio.h>
#include "string.h"
#include "cs240/utils.h"

/*
 *  comparator function has to return an integer
 *
 *  positive: bigger than
 *  negative: smaller than
 *  zero: equal
 * */

int add100(int a, int b) {
    return a + b;
}


void typecast_demo() {
    int a = 10;
    void *pa;
    printf("%p\n", pa);
    pa = &a;
    printf("%d\n", *(int *) pa);
    printf("%p\n", pa);


    float f = 3.14f;
    pa = &f;
    printf("%f\n", *(float *) pa);
    printf("%f\n", ((float *) pa)[0]);
    printf("%p\n", pa);

    pa = add100;
    printf("%d\n", ((int (*)(int, int)) pa)(1, 2));
    printf("%p\n", pa);

}

//
//int compareInt(void *a, void *b){
//    return
//}

void mem_oper_demo() {
    int a = 1, b = 2;
    void *pa = &a;
//    *pa = b; // not allowed
//    *pa = &b; // 1 not allowed to assign void pointer 2, datatype incompatible
    memcpy(pa, &b, sizeof(a)); //
    printf("%d\n", a);

    int aa = 0x12345678, bb = 0;

    printf("12:%x\n", 12);
    printf("%x\t%x\n", aa, bb);
    memcpy(&bb, &aa, 1); //
    printf("%x\t%x\n", aa, bb);

    memcpy(&bb, &aa, 2); //
    printf("%x\t%x\n", aa, bb);

    memcpy(&bb, &aa, 3); //
    printf("%x\t%x\n", aa, bb);

    memcpy(&bb, &aa, 4); //
    printf("%x\t%x\n", aa, bb);

}





//int a, b;
//char aa, bb;

int main(int argc, char *argv[]) {
//    int len = 20;
//    int nums[len];
//
//    rand_int_array_utils(nums, len, 20);
//    print_int_array(nums, len);


//    typecast_demo();
    mem_oper_demo();
    int nums1[] = {1, 1, 1, 1};
    int nums2[] = {-1, -1, -1, -1};

    int size = 4 * sizeof(int);
    print_int_array(nums1, 4);
    print_int_array(nums2, 4);
    swap(nums1, nums2, size);
    print_int_array(nums1, 4);
    print_int_array(nums2, 4);

    int a1 = 1, a2 = -1;
    swap(&a1, &a2, sizeof(int));
    printf("%d\t%d\n", a1, a2);


    long long al1 = 1, al2 = -1;
    swap(&al1, &al2, sizeof(long long));
    printf("%lld\t%lld\n", al1, al2);


    return 0;
}