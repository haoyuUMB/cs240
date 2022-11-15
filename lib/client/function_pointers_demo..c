//
// Created by haoyu on 11/10/2022.
//

#include <stdio.h>

int add(int a, int b) { return a + b; }

int subtract(int a, int b) { return a - b; }

int multiply(int a, int b) { return a * b; }

int divide(int a, int b) { return a / b; }

int main() {
    int a = 4, b = 2;
    char *operations[] = {"+", "-", "*", "/"};

    // using an data of function pointers to reference the above 4 functions
    int (*func_ptr[4])(int, int) = {add, subtract, multiply, divide};

    for (int i = 0; i < 4; i++) {
        printf("%d %s %d result is: %d\n",
               a, operations[i], b, func_ptr[i](a, b));
    }
}