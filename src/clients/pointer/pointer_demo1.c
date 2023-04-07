#include <stdio.h>

void demo1() {
    int a = 0;
    int *pa = &a;
    printf("value of pa: %p\n", pa);
    printf("value of pa + 1: %p\n", pa + 1); // e0 - dc = 16 - 12 = 4
    printf("value of pa reference to: %d\n", *pa);

    *pa = 10;

    printf("value of a: %d\n", a);
    printf("value of a: %d\n", pa[0]);


    pa = (int *) &pa; // explicit typecasting because the reference of pa is a pointer to pointer

    printf("value of pa: %p\n", pa);
    printf("value of pa + 1: %p\n", pa + 1); // e4 - e0
    printf("address of pa: %p\n", &pa);

}


void const_demo() {
    const int a = 0;
    //a = 1// not allow
    int *pa = &a;

    *pa = 10;
    printf("value of a: %d\n", a);

    const int *const_pa = &a;
//    *const_pa = 11;

    int b = -1;
    pa = &b;

    printf("value of *pa: %d\n", *pa);

    int *const const_pp = &b;
//    const_pp = &a;

    // these two quantile
    const int *const const_const_p = &b;
    int const *const const_const_p1 = &b;

//    *const_const_p = 1;// not allowed
//    const_const_p = &a// not allowed


}

void swap_int(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void swap_float(float *a, float *b) {
    float tmp = *a;
    *a = *b;
    *b = tmp;
}


void function_pointer_demo() {
    void (*f_sf)(float *, float *) = swap_float;

    float af = 1.1f, bf = -1.1f;
    (*f_sf)(&af, &bf);
    f_sf(&af, &bf);
    printf("af: %g\tbf: %g", af, bf);

}


int main(int argc, char *argv[]) {
//    const_demo();
//
//    int a = 1, b = -1;
//    swap_int(&a, &b);
//    printf("a: %d\tb: %d\n", a, b);
//
//
//    float af = 1.1f, bf = -1.1f;
//    swap_float(&af, &bf);
//    printf("a: %g\tb: %g", af, bf);

//    function_pointer_demo();

    int nums[10] = {1, 2, 3}; // 0, 4, 8, c

    int *p_num = nums;

    printf("a: %d\tb: %d\n", p_num[0], p_num[1]);
    printf("%d\n", *(nums + 1));

    int *p_num2 = nums;
    printf("%p\n", p_num2);

    for (int i = 0; i < 3; ++i) {
        printf("%d\n", *p_num2);
        p_num2++;
    }
    printf("%p\n", p_num2);

//    nums++;// not allowed, because array address value is constant


    return 0;
}