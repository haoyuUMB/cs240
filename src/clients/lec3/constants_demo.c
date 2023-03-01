//
// Created by haoyu on 2/9/2023.
//

#include <stdio.h>

int main() {

    int a = 100;
    long l = 100lu;
    int b = 010;
    int c = 0x10lu;

//    int d = 078; // wrong octor does not have digit 8
    int f = 0xa;
    printf("%d   %d", f, 0xA);
    printf("%g   %g\n", 3.1, 3213E-4);


    printf("%d\n", '0' > 0);
    printf("%d\n", '0' - 0);
    printf("%d\n", '\n');
    printf("%d\n", '\0' == 0);
    printf("%d\n", '\0');
    printf("%E\n", 3.123123123);

}