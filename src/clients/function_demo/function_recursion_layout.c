//
// Created by haoyu on 3/23/2023.
//
#include "stdio.h"

// 32 bytes
//  0x8c - 0x6c = 0x20 = 2 * 16 ^ 1 + 0 * 16 ^ 0 = 32 bytes


// fac(n) = n * (n - 1) * ... * 1
int factorial(int a) {
//    int b[100];
    printf(" factorial: a:%3d\taddress: %p\n", a, &a);
    if (a == 1) return 1;
    return a * factorial(a - 1);
}

int main(int argc, char *argv[]) {

    int a = 10;
    printf(" main: a:%d\taddress:%p\n", a, &a);
    printf(" factorial of %d is: %d\n", a, factorial(a));
    return 0;
}

