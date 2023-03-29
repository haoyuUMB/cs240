//
// Created by haoyu on 3/23/2023.
//

#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("argc: %d \n", argc);
    printf("argv[0]: %s \n", argv[0]);
    char s1[] = "12345";
    char s2[] = {'1', '2', '3', '4', '5'};
    printf("argc: %d \n", sizeof(s1));
    printf("argc: %d \n", sizeof(s2));
}