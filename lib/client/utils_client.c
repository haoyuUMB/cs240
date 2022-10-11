//
// Created by haoyu on 10/11/22.
//

#include "utils.h"

void shifting_demo() {
    bin(1);
    bin(~1);
    bin(~1 << 32);

    bin(-1 >> 132);
    bin(((unsigned) -1) >> 132);

}

int main() {
//    bin(2);
//    bin(1 << 2);
//    bin(2 | (1 << 2));

    bin(12);
    bin(1 << 3);
    bin(~(1 << 3));
    bin(12 & ~(1 << 3));

    printf("%d\n", 12 ^ 123 ^ 123);

    int a = 10, b = 20;
    int c = a ^ b;
    printf("%d\n", c ^ a);

    a = a ^ b ^ (b = a);
    printf("%d\t %d\n", a, b);


//    printf("%d")
}