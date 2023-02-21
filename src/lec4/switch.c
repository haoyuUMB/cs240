//
// Created by haoyu on 2/14/2023.
//
#include <stdio.h>

// any experssion in c assume a value
// with assginement or comma, it is the right value
//
void commna_demo() {
    int i = 0, j = 0;
    printf("%d\n", j + (i = 2 * 2));
    printf("%d", (j + (i = 2 * 2), 10, i + (j = 1)));
}

// break and continue demo
void demo() {
    for (int i = 0; i < 10; ++i) {
        if (i == 5) break; // break is jump out of loop totally
        if (i % 2 != 0) continue; // skip the rest of the statements in loops body
        printf("%d\n", i);
        printf("***\n");
    }

    int i = 0;
    while (1) {
        i++;
        if (i == 10) { break; }
    }

    for (int j = 0; 1; ++j) {
        if (j == 10) {
            i++;
            break;
        }
    }
}

int main() {
//    commna_demo();
    demo();
    printf("%g", 3.14E0);

    // i++ <==> i += 1; when used as a single line statement

//    int j;
//    for (int i = 0, k = 0, j = 1; i < 10; i++) {
//        switch (i) {
//            case 0:
//                printf("case 0\n");
//                break;
//            case 1:
//                printf("case 1\n");
//                break;
//            default:
//                printf("case default\n");
//        }
//    }

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