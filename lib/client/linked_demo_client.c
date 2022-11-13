//
// Created by haoyu on 11/13/2022.
//

#include <stdio.h>
#include "linked.h"

void stack_demo() {
    StackL st = new_stackINode();
    for (int i = 0; i < 10; ++i) {
        push_stackINode(&st, i);
    }
    print_stackINode(st);
    printf("\n");
    for (int i = 0, val; i < 10; ++i) {
        pop_stackINode(&st, &val);
        printf("%d\t", val);
    }
    printf("\n");
}


int main() {
    stack_demo();
    return 0;
}