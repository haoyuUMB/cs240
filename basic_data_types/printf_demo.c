//
// Created by Haoyu on 9/20/2022.
//
#include <stdio.h>
int main(){
    int a = 10, arr[10];
    printf("%x\t%o\t%d\n", a, a, a);
    printf(" add: %p", &a);

    printf("%p\n", &a); // a’s address
    printf("%d\n", a); // a’s value
    printf("%p\n", arr); // arr’s value
    printf("%p\n", &arr); // arr’s address
    printf("%d\n", arr[0]);

}