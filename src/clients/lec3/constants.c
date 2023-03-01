
#include <stdio.h>
#include <float.h>
#include <ctype.h>
#include <math.h>

// 0 means false; non-0 means true; no true or false

// this functions is <==> isupper(c)
int verifyUpperCase(char c) {
    if (c >= 'A' && c <= 'Z') return 1;
    return 0;
}

// <==> tolower(c)
char toLower(char c) {
    // assume c is upper case
    return c - 'A' + 'a';
}


int main() {

//    char c = 65;
//
//    char a = 'A'; // character constant literal
//
//
//
//    printf("65 maps to: %c\n", c);
//    printf("65 + 1 maps to: %c\n", c + 1);
//
//    printf("charat A maps to: %d\n", a);
//    printf("%d\n", isupper('A'));
//    printf("%d\n", isupper('0'));
//    printf("%d\n", 'A' == 65);
//
//
//    printf("%c\n", toLower('A'));
//    printf("hello %c\n", tolower('A'));
//
//
//    float f = FLT_MIN;
//    unsigned int *af = &f;
//    printf("%x\n", *af);
//    // 80000000
//    // 1000 0000
//
//    printf("0.1 is not 0.1 in computer: %1.30f\n", 0.1f);



//    float n = 0.1f; // this means float
//    double a = 0.1; // for constant float-point literal by default it's double
//
//    if (n == 0.1) printf("it's all right\n");
//    else printf("Wierd\n");
//
//
//    if (a + a + a + a + a + a + a + a + a + a == 1.0)
//        printf("10 * 0.1 is indeed 1.0. \n");
//    else
//        printf("Wierd, This is not guaranteed in the general c");


    float epsilon_f = 1.0 / pow(10.0, (double) FLT_DIG);
    double epsilon_d = 1.0 / pow(10.0, (double) DBL_DIG);
    float n = 0.1;
    double a = 0.1;
    if (fabs(n - 0.1) < FLT_EPSILON)
        printf("it's all right\n");
    else printf("Wierd\n");
    if (fabs(a + a + a + a + a + a + a + a + a + a - 1.0)
        < FLT_EPSILON)
        printf("10 * 0.1 is indeed 1.0. \n");
    else
        printf("Wierd, This is not guaranteed in the general case.\n");


    // This relates implicit type conversion


    printf("10 / 3 = %f \n", (float) (10 / 3)); // parenthesis calculated the integer 10 / 3 give 3 floor(division)
    printf("10 / 3 = %f \n", (float) 10 / 3); // mix type of float and integer as a result promoting integer to float


    printf("10 / 3 = %f \n", 10 / 3); // print integer 3 as float
    printf("10 / 3 = %f \n", 3); // print integer 3 as float


    printf("floor of 3 = %d \n", floor(3)); // print 3.0 as integer
    printf("floor of 3 = %d \n", 3.0); // print 3.0 as integer
    printf("floor of 3 = %f \n", floor(3)); // print 3.0 as integer

    // for conversions between integer and floating-point (float/double/long double) we'd better to use explicit conversion to avoid unexpected results

    printf("%d \n", 010);// octal so it 1*8^1 + 0 * 8^0 = 8
    printf("%d \n", 0x10);//


}