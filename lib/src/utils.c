//
// Created by haoyu on 9/2/2022.
//

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "headers/utils.h"

void print(char *s) {
    printf("%s\n", s);
}
void print_int(int n) {
    printf("%d\n", n);
}

void printf_long(long n){
    char* msg = calloc(300, 1);
    sprintf(msg, "%ld", n);
    print(msg);
    int l = strlen(msg), j = 1;
    print_int(l);
    int i = l + (l+1) / 3 - 1;
    for (; l > 0; i--){
        if (j++ % 4 == 0) msg[i] = ',';
        else msg[i] = msg[(l--)-1];
    }
    print("heelo");
    print(msg);
    free(msg);
}

