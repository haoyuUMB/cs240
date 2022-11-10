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
    int (*fs[4])(int, int) = {add, subtract, multiply, divide};
    for (int i = 0; i < 4; i++) {
        printf("%d %s %d result is: %d\n",
               a, operations[i], b, fs[i](a, b));
    }
}