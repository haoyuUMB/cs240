//
// Created by haoyu on 4/4/2023.
//

#include <stdio.h>

int main(int argc, char *argv[]) {
    int *p; // only declaration

    printf("size of int: %d\n", sizeof(int));
    printf("%p\n", p);
    printf("%p\n", p + 1);
    printf("%p\n", p + 3);
    printf("%p\n", p);
    printf("%p\n", &p[3]); // p[3] means the *(p + 3)

    // pointer value is address
    // what about the address of pointer
    //
    printf("address of p: %p\n", &p);

    long long *pl; // 8 bytes for my computer

    printf("size of int: %d\n", sizeof(long long));
    printf("%p\n", pl);
    printf("%p\n", pl + 1); // 0x8
    printf("%p\n", pl + 3); // 0x18
    printf("%p\n", pl);
    printf("%p\n", &pl[3]); // p[3] means the *(p + 3)


    int a;
    int *pa; // create a local variable pa (pointer)
    pa = &a; // get the address of a, store that in pa value

    // value of a and pa and the address of pa and a
    //

    printf("address of pa and a: %p and %p\n", &pa, &a);

    printf("%p\n", &pa[-1]);
    printf("%p\n", pa - 1);


    return 0;
}