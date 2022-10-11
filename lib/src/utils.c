//
// Created by haoyu on 10/11/22.
//

#include <utils.h>

int setNthBit(int x, int n) {
    return x | (1 << n - 1);
}

void bin(unsigned n) {
    printf("%11d\t:\t", n);
    unsigned i, j = 0;
    for (i = 1 << 31; i > 0; i = i / 2) {
        (n & i) ? printf("1") : printf("0");
        if ((j + 1) % 8 == 0) printf(" ");
        j++;
    }
    printf("\n");
}
