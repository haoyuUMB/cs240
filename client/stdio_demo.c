//
// Created by haoyu on 9/17/2022.
//

#include <stdio.h>
#include "headers/utils.h"

void count(){
    long n = 0; char c;
    int counts[128];
    for(int i=0; i < 128; i++) counts[i]=0;
    while ((c=getchar()) != -1){

        n++;
        counts[c]++;
    }
    printf("%d\n", n);
    for(int i=0; i < 128; i++)
    {
        if (counts[i] != 0)
            printf("%c %d: %d\n",i, i, counts[i]);
    }
}


int main(){
    count();
    printf_int(43102938);
    return 0;
}