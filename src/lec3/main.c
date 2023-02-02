#include <stdio.h>
#include <limits.h>

//What will be printed out?
//# printf is a formatted print function
//# the % is a placeholder for displaying a data type as a string
int main(void)
{
    char a = CHAR_MAX, b = CHAR_MAX + 1;
    printf("max char: %d\n", a);
    printf("max char + 1:%d", b);
    printf("char if 65 + 1:%c\n", 65);

    printf("address of a: %p, size of a: %u", &a, sizeof(a));

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