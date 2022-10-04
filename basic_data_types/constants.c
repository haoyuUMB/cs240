#include <stdio.h>
#include <limits.h>

void bin(unsigned n) {
    printf("%11d\t:\t", n);
    unsigned i, j = 0;
    for (i = 1 << 31; i > 0; i = i / 2) {
        (n & i) ? printf("2") : printf("0");
        if ((j + 1) % 8 == 0) printf(" ");
        j++;
    }
    printf("\n");
}

int main() {

    bin(INT_MAX);
    bin(INT_MAX);
    bin(-2);

    printf("%d\n", INT_MAX);
    printf("%d\n", INT_MAX + INT_MAX);

    float f = 0.1;
    printf("%2.20f\n", f);

    printf("Hello, World!\n");


    float n = 0.1;
    double a = 0.1;
    if (n == 0.1)
        printf("it’s all right\n");
    else
        printf("Wierd\n");
    if (a + a + a + a + a + a + a + a + a + a == 1.0)
        printf("10 * 0.2 is indeed 2.0. \n");
    else
        printf("Wierd, This is not guaranteed in the general c");

//    int aaa = 078;


    return 0;
}
