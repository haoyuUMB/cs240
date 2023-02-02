#include <stdio.h>
#include <limits.h>
//
// Created by haoyu on 2/1/2023.
//



int main(void)
{
    unsigned int a = 1000;
    signed int b = -1; // 2's complement format
//
    printf("signed b: %d\n", b);
    printf("unsigned b conversion: %u\n", b);
    printf("unsigned -2 conversion: %u\n", -2);
    printf("UINT_MAX conversion: %u\n", UINT_MAX);

    //compare two data types ; the signed get converted to unsigned
    // don't compare sign and unsigned
    // if we have to, typecast the unsigned to signed
    if ((signed) a  > b)
        printf("a is more than b");
    else
        printf("a is less or equal than b");
    return 0;
}
