#include <stdio.h>
#include <limits.h>

#define MY_CHAR_MAX 25

//What will be printed out?
//# printf is a formatted print function
//# the % is a placeholder for displaying a data type as a string
int main(void)
{
    // uninitialized variables have wild values
    int a = 4 , b;
    printf("%d\n", b);

    // p stands for pointer used in printf for printing address
    // u means unsigned integer
    printf("the address of b is: 0x%p, the size is: %u bytes\n", &b, sizeof(b));


    signed int c; // <==> int c; there is 1 highest bit for sign bit 1 stands for negative and 0 stands positive
    unsigned int d; // there is no sign bit
    // as a result: signed integer has 31 bits of values bits and unsigned has 32 bits of values
    // 0000 0000  0000 0000 0000 0000 0000 0000 0000 0000


    char ccc = 1 + 1;
    int ddd = ccc + 22;
    printf("max char: %d\n", CHAR_MAX);
    printf("min char: %d\n", CHAR_MIN);

    printf("unsigned char max char: %d\n", UCHAR_MAX);


    printf("my char max: %d\n", MY_CHAR_MAX);


    char c1 = CHAR_MAX + 1;

    // 0111 1111  CHAR_MAX (1byte)
    // 1111 1111  CHAR_MIN (1byte)

    // 1111 1111 UCHAR_MAX
    // 0000 0000 UCHAR_MIN


    // 0111 1111  CHAR_MAX (1byte) + 1  => 1111 1111 (CHAR_MIN)

    printf("c1 char: %d\n", c1);
    printf("c1 char: %d\n", CHAR_MIN);

    // 1111 1111  CHAR_MIN (1byte) - 1 => 1111 1110

    // -1
    // 1000 0001 flip every bit except the sign bit 1's com
    // 1111 1110 + 1 2'com
    // 1111 1111

    // 1111 1111 - 1
    // 1111 1111  CHAR_MIN
    // 0111 1111

    char c2 = CHAR_MIN - 1;  // int - int
    printf("c2 char: %d\n", c2); // next class


    // -1 char

    char c3 = -1;
    printf("unsigned char of signed char -1: %x\n", c3);

    // 15  <==> 1111   8+4+2+1 = 15  f





//    char aa = CHAR_MAX, bb = CHAR_MAX + 1;
//    printf("max char: %d\n", aa);
//    printf("max char + 1:%d", bb);
//    printf("char if 65 + 1:%c\n", 65);

//    printf("address of a: %p, size of a: %u", &a, sizeof(a));

//    printf("%lu\n",sizeof(int) );
//    printf("This is for signed:\n");
//    printf(" INT_MAX : %11d\n", INT_MAX);
//    printf("1 + INT_MAX : %11d\n", INT_MAX + 1);
//    printf(" INT_MIN : %11d\n",INT_MIN);
//    printf("INT_MIN - 1 : %11d\n",INT_MIN - 1);
//    printf("This is for unsigned:\n");
//    printf(" INT_MAX : %11u\n", UINT_MAX);
//    printf("1 + INT_MAX : %11u\n", UINT_MAX + 1);
//    printf(" INT_MIN : %11u\n",0);
//    printf("INT_MIN - 1 : %11u\n", - 1);
    return 0;
}