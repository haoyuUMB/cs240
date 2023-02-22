//
// Created by haoyu on 2/21/2023.
//

#include <stdio.h>

int main(int argc, char *argv[]) {

    printf("argc %d\n", argc);

    int c = getchar();
    printf("the char is :%c\n", c);

    while (c != EOF) {
        c = getchar();
        printf("the char is :%c\n", c);
    }

//    while ((c = getchar()) != EOF) {
//        printf("the char is :%c\n", c);
//    }
    printf("the EOF is :%d\n", EOF);
    return 0;
}