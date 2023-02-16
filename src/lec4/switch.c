//
// Created by haoyu on 2/14/2023.
//
#include <stdio.h>

int main() {

    // i++ <==> i += 1; when used as a single line statement

    int j;
    for (int i = 0; i < 10; i++) {
        switch (i) {
            case 0:
                printf("case 0\n");
                break;
            case 1:
                printf("case 1\n");
                break;
            default:
                printf("case default\n");
        }
    }

//    int n = 0;
//    // post self increment
//    printf("n++ %d\n", n++ + 1); // n gets parsed first, value of n 0 and then doing addition with 0
//    printf("n %d\n\n", n);
//
//    n = 0;
//    // pre self increment
//    printf("n++ %d\n", ++n + 1); // n gets increment first, value 1 and then doing addition with 1
//    printf("n %d\n", n);
//
//
//    n = 0;
//    printf("\nn++ %d\n", n + 1); // n gets increment first, value 1 and then doing addition with 1
//    printf("n %d\n", n);

}