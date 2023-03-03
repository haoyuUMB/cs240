//
// Created by haoyu on 3/2/2023.
//
#include "main.h"

// Macro text substitution
#define GREETINGS printf("Hello");
#define EOF -1
#define YES "YES"

//#define max(A, B) A >= B ? A : B;

int main() {

    GREETINGS
    int aPI;
    printf(" PI %g\n", PI);
#define HI printf("HI");
    HI

    // tertiary expres ?
    // (int expr) ? [first](true) : [second](false)

    // 0 means false; non-0 means true
    printf("which one: %s", 2 < 1 ? "hello" : "word");
}