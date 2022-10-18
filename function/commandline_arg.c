//
// Created by haoyu on 9/27/22.
//


#include <stdio.h>

int getLen(char *s) {
    int l = 0;
//    while (s[l]) l++;
    while (s[l] != '\0') l++;
//    for (; s[++l];) {}
    return l;
}

int main(int argc, char *argv[]) {

    printf("argc: %d\n", argc);
    printf("argv[0]: %s\n", argv[0]);
    printf("argv[2]: %s\n", argv[1]);
    printf("argv[2]: %s", argv[2]);
    int i = 0;
    printf("d: %d\n", ++i);
    printf("len: d: %d", getLen("12345"));


    return 0;
}