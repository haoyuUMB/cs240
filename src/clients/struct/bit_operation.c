#include <stdio.h>

int main(int argc, char *argv[]) {
    int i = 1, j = -1;
//     0000000 0000000 0000000 0000001
//     0000000 0000000 0000000 0000010

    printf("%x\n", i << 1);
    printf("%x\n", i >> 1);

    printf("%x\n", (unsigned) j);
    printf("%x\n", j << 1); // unsigned
    printf("%x\n", j >> 1); // padding 1 or 0 on the most left is not standardized

    unsigned n = 1;
    for (int k = 0; k < 32; ++k) {
        printf("%u\n", n << k);
    }

    n = 1;
    printf("%d\n", n = n ^ 1);
    printf("%d\n", n = n ^ 1);
    printf("%d\n", n = n ^ 0);

    // set first 5 bits to 1;
    // 2^6 = 32  100000 - 1   = 011111
    printf("%x\n", (1 << 2) - 1); // 3  11
    printf("%x\n", (1 << 5) - 1); // 0x1f  11111

    printf("%x\n", n & (1 << 5) - 1); // 0x1f  11111

    // 0xf  15(decimal) 1111(binary)



    // even/odd (n & 1)


    enum color {
        RED, GREEN = 10, BLUE
    };

    typedef enum color Color;
    enum color color1 = BLUE;
    Color color2 = GREEN;

    if (color1 == 11) {
        printf("blue");
    }

    NULL;

//    fclose(stdout);
//    stdout = fopen("hello.txt", "w");
//    fprintf(stdout, "123123123\n");
//    printf("hello");
//
//    FILE *input = fopen("hello.txt", "r");
//    fflush(stdout);
//    fclose(stdout);

    FILE *input = fopen("hello.txt", "r");
    printf("%c", fgetc(input));


    return 0;
}