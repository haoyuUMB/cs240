//
// Created by haoyu on 3/1/2023.
//
//#include <stdio.h> // stdio.h file is within the searching PATH gcc
extern int printf(const char *__restrict __format, ...);

//#include <cs240/utils.h>
#define max(a, b) (a) >= (b) ? a : b
#define PI 3.1416926

int add(int a, int b); //just declaration is not enough

//#include "../../lib/include/cs240/utils.h" // relative path

/*
 *
 * TO use a libray we have to have two parts of that library
 *  1. header files: offers declaration
 *  2. object code: offers definition (object machine code)
 *
 * */

int main() {
    printf("Hello %d %g\n", max(2, 1), PI);
    printf("1 add 2 %d\n", add(1, 2));
}