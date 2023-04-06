

#include <stdio.h>
#include <stdlib.h>
#include "cs240/utils.h"


// variable declaration
//extern double pi; // variable declaration
//extern double pi = 3.0; // variable definition

int counter() {
    // local variable will be destroyed when function exits
    auto int count = 0;
    count++;
    return count;
}

int counter1() {
    // static local retain its value even after the exit of the function
    static int count = 0;
    count++;
    return count;
}


int main(int argc, char *argv[]) {
    printf("pi:%g\n", pi);
    add(1, 2);
//    extern int seed;
//    printf("non_static :%d\n", seed);

    extern int non_static;
    printf("non_static :%d\n", non_static);

    printf("drand48 :%g\n", drand48());
    srand48(1);
    printf("drand48 :%g\n", drand48());

    srand48(0);
    printf("drand48 :%g\n", drand48());

    for (int i = 0; i < 10; ++i) {
        counter();
        counter1();
    }
    printf("counter :%d\n", counter());
    printf("counter1 :%d\n", counter1());

    register int count = 0;

//    printf("count :%p\n", &count);// not allowed

    int a;
    int nums[10];

    return 0;
}