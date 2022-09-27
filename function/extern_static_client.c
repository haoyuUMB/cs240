/*
* Author : Haoyu Wang
* Description:
*
*/

#include <stdio.h>


extern float pi;
// if there is no pi declaration visible to this file from
// somewhere else, then this pi is not declared
extern float getPi();

int main(int argc, char *argv[])
{
    printf("%g\n", getPi());
    printf("%g\n", pi);

    return 0;
}