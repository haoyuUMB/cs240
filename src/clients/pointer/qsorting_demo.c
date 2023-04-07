#include <stdio.h>
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

    pa = &a;
    printf("%d\n", *(int *) pa);

    float f = 3.14f;
    pa = &f;
    printf("%f\n", *(float *) pa);

    pa = add100;
    printf("%d\n", ((int (*)(int, int)) pa)(1, 2));

}

//
//int compareInt(void *a, void *b){
//    return
//}


int main(int argc, char *argv[]) {
    int len = 20;
    int nums[len];

    rand_int_array_utils(nums, len, 20);
    print_int_array(nums, len);


    typecast_demo();

    return 0;
}