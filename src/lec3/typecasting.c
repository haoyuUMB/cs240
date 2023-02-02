#include <stdio.h>
#include <limits.h>
//
// Created by haoyu on 2/1/2023.
//



int main(void)
{
    unsigned int a = 1000;
    signed int b = -1; // 2's complement format

    printf("unsigned b conversion: %u\n", b);
    printf("unsigned b conversion: %u\n", UINT_MAX);

    //
    if (a > b)
        printf("a is more than b");
    else
        printf("a is less or equal than b");
    return 0;
}
