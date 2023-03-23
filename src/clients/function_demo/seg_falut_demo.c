//
// Created by haoyu on 3/23/2023.
//
# include <stdio.h>

double this_pi = 3.14;

extern double this_pi;

// main is the program name
// main 1 2
// argc: 3
// argv 0: main
// argv 1: 1

int main(int argc, char *argv[]) {
//    char s[2], i = 1;
//    while (i++) {
//        printf("hello%d\n", i);
//        s[-i] = 'a';
//    }

    { auto int i = 0; }

//    printf("hello%d\n", i);
    int i = 0;
    { i = 1; };

    printf("i: %d\n", i);  // 1

    {
        int i = -1;
        printf("i: %d\n", i); // -1
    }

    printf("i: %d\n", i); // 1


    return 0;
}