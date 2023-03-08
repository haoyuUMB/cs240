//
// Created by haoyu on 3/2/2023.
//
//#include <stdio.h>
#include "main.h"

int printf(const char *__restrict __format, ...);

int printf(const char *__restrict __format, ...);

int printf(const char *__restrict __format, ...);

// no function overloading in c
//int sub() {}; // definintion
//
//int sub() {};
//
//int sub() {};

// Macro text substitution will produce preprocessed source code
// function will be compiled to binary and will stay intact in preprocessing statge
#define GREETINGS printf("Hello");
//#define EOF -1
#define YES "YES"

#define max(A, B) A >= B ? A : B
#define square(x) x * x
#define square_fix(x) (x) * (x)




//int max(int a, int b) {
//
//}

int main() {

    GREETINGS
    int aPI;
    printf(" PI %g\n", PI);
#define HI printf("HI");
    HI

    // tertiary expression ?
    // (int expr) ? [first](true) : [second](false)
    // if (int expr)

    // 0 means false; non-0 means true
    printf("which one: %s", 2 < 1 ? "hello" : "word");
    int b = max(2, 1);
    float f = max(PI, 1.0);

    square(2);
    printf("square(2): %d\n", square(2));

    square(2 + 1);
    printf("square(2 + 1): %d\n", square(2 + 1));

    printf("square((2 + 1)): %d\n", square((2 + 1)));

    printf("square_fix(2 + 1): %d\n", square_fix(2 + 1));


#define dprint(expr) printf(#expr " = %g\n", expr)

    dprint(PI * 2);
    // printf("PI * 2" " = %g\n", PI * 2);

#define concat(x, y) x ## y
    int a2;
    concat(a, 2) = 2;

    printf("%s\n", __DATE__);
    printf("%s\n", __FILE__);
    printf("%d\n", __LINE__);

#undef max

#ifdef max
    printf("this macro defined");
#else
    printf("this macro not defined\n");
#endif
#ifndef max
    printf("this macro not defined, indeed");
#endif


#ifdef cs240
    printf("cs240 macro defined");
#else
    printf("cs240 macro not defined\n");
#endif

}