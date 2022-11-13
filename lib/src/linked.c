//
// Created by haoyu on 11/5/22.
//

#include <malloc.h>
#include "linked.h"

Node *new_node(int val, Node *next) {
    Node *node = malloc(sizeof(Node));
    node->val = val;
    node->next = next;
    return node;
}


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


QueueL new_queueINode() {
    return (QueueL) {NULL, NULL};
}

QueueL *enqueueINode(QueueL *q, int val) {
    Node *node = new_node(val, NULL);
    if (q->end == NULL) {
        q->top = q->end = node;
        return q;
    }
    q->end->next = node;
    q->end = node;
    return q;
}

QueueL *dequeueINode(QueueL *q, int *val) {
    if (q->top == NULL) return NULL;
    *val = q->top->val;
    Node *top = q->top;
    q->top = q->top->next;
    free(top);
    return q;
}

void print_queueINode(QueueL q) {
    printf("Queue values are: ");
    Node *p = q.top;
    while (p) {
        printf("%d\t", p->val);
        p = p->next;
    }
    printf("\n");
}