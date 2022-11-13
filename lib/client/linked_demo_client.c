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

void queue_demo() {
    QueueL q = new_queueINode();
    for (int i = 0; i < 10; ++i) {
        enqueueINode(&q, i);
    }
    print_queueINode(q);
    printf("\n");
    for (int i = 0, val; i < 10; ++i) {
        dequeueINode(&q, &val);
        printf("%d\t", val);
    }
    printf("\n");
}


int main() {
    stack_demo();
    queue_demo();
    return 0;
}