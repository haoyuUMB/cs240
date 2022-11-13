//
// Created by haoyu on 11/5/22.
//

#include <malloc.h>
#include "linked.h"

StackL new_stackINode() {
    return (StackL) {NULL};
}

StackL *push_stackINode(StackL *st, int val) {
    Node *node = malloc(sizeof(Node));
    node->val = val;
    node->next = st->top;
    st->top = node;
    return st;
}

StackL *pop_stackINode(StackL *st, int *val) {
    if (st->top == NULL) return NULL;
    *val = st->top->val;
    Node *top = st->top;
    st->top = st->top->next;
    free(top);
    return st;
}

void print_stackINode(StackL st) {
    printf("Stack values are: ");
    Node *p = st.top;
    while (p) {
        printf("%d\t", p->val);
        p = p->next;
    }
    printf("\n");
}