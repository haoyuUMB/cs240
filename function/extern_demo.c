//
// Created by haoyu on 9/21/2022.
//
#include <stdio.h>

extern float *pi_a; // undefined here
float pi;

int add(int, int);

int main(int argc, char *argv[]) {


    // Can we print pi here ?


    extern float pi;
    printf("%g\n", pi);
    printf("0 file PI:%p\n", &pi);

    float pi1;
    printf("%g\n", pi1);
    printf("0 file PI1:%p\n", &pi1);




//    printf("2 File PI:%p\n", pi_a);

    // can we redefine pi here ?
    // float pi;
    // pi = -3.2;
    // printf("%g\n", pi);
    // printf("Local PI:%p\n", &pi);



    return 0;
}