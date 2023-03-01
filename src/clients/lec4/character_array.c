//
// Created by haoyu on 2/14/2023.
//

#include <stdio.h>
#include <string.h>

int array_pass(const int arr[]) {
    // arr passing degenerate to a pointer and lose the length info
    printf("sizeof arr: %u bytes\n", sizeof(arr));
}


int main() {

//    int a = 10;
//    printf("sizeof int is: %d bytes\n", sizeof(a));
//    printf("sizeof long is: %d bytes\n", sizeof(long long));
//
//    int arr[100] = {1, 2, 3};
//    long long arr1[10];
//
//    printf("sizeof arr is: %d bytes\n", sizeof(arr));
//    printf("sizeof arr is: %d bytes\n", sizeof(arr1));
//
//    array_pass(arr);
//    array_pass(arr1);


    int a[] = {1, 2, 3}, b[3];
    //    b = a; // wrong, cannot even pass compiling
//
//    for (int i = 0; i < ; ++i) {
//
//    }

//    memcpy(b, a, sizeof(int) * 3);
//
//    printf("a[0] is: %d \n", a[0]);

    char str[7] = "hello\n"; // at least length of 7
    char str2[] = "12345\n"; // or implicit initialization
    // the length of string str2 is 6 but it has to at least have 7 bytes since
    // there is a null character at the end
    printf("%d\n", sizeof(str2));
    str2[0] = 75; // ascii
    printf("strt2 is %s\n", str2);

    char ss[] = {'1', '2', '3'};
    // there is not a null character set at the end
    printf("size of ss %d\n", sizeof(ss));
    printf("----ss is %s------\n", ss);

    char ss1[] = {'1', '2', 0}; // there is not a null character set at the end
    // 0 <==> '\0'
    printf("size of ss %d\n", sizeof(ss1));
    printf("----ss is %s------\n", ss1);


    char s[] = "hell0";
    printf("%d", sizeof(s));

    s[1] = '1';
    char *s2 = "h2ll0";

    printf("\n===s2[0] is %c==\n", s2[0]);

//    s2[1] = '3'; // this will crash
//    printf("\n===s2[1] is %c==\n", s2[1]);


    for (int i = 0; s[i] != '\0'; ++i)  // 0 means false; non 0 means true
        printf("%c", s[i]);


    int a1[2], a2[3];
    a1 > a2;
    printf("\n a1 > a2 %d", a1 > a2);
    return 0;
}