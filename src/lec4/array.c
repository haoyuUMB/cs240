#include <stdio.h>

int main() {
    int a[10];
    printf("%d\n", a[0]);

    int b[10] = {1, 2, 3};
    printf("%d\n", b[4]);


    int c[10] = {};
    printf("%d\n", c[0]);

    int aa = 10;
    printf("%d\n", aa);
    printf("%p\n", aa);// hex of value of aa, not the address
    printf("%p\n", &aa);// hex of value of aa, not the address

    printf("%p\n", a);
    printf("%p\n", &a);

//    printf("%p\n", a + 1);  // a is a pointer to int
//    printf("%p\n", &a + 1); // (&a) is a pointer to a[10]  0x28 = 32 + 8 = 40

    printf("%d\n", a);


}