//
// Created by haoyu on 9/2/2022.
//
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "headers/Integer.h"

Integer new_integer(){
    return (Integer) {malloc(4)};
}

Integer set_integer(Integer a, int val){
    memcpy(a.val, &val, 4);
    return a;
}

int get_integer_val(Integer a){
    return *a.val;
}

int integer_comparator(Integer a, Integer b){
    return *a.val - *b.val;
}

Integer new_integer_val(int val) {
    return set_integer(new_integer(), val);
}

char* integer_to_string(Integer a, char *s){
    sprintf(s, "%d", a.val[0]);
    return s;
}

void free_integer(Integer a) {
    free(a.val);
}

void print_integer(Integer a){
    printf("%d\n", a.val[0]);
}

