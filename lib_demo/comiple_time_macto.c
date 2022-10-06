
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define YES "NO"
#define NO YES // chain of substitution
//#define WHAT OK

#define MAX(x, y) x > y ? x : y
#define SQUARE(x) (x) * (x)

int main() {
    
    assert(0);
    printf(YES);
    printf(NO);
    printf("\nmax : %d", MAX(1, 2));
    printf("\nmax : %f", MAX(1.1, 2.0));
    printf("\nsquere : %d", SQUARE(1 + 1));
//    printf(WHAT);
#ifndef DEBUG
    1 + 1;
#elif DEBUG
    printf("this a debug info");
#endif
}