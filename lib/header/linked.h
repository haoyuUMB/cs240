//
// Created by haoyu on 11/5/22.
//

#ifndef CS240_LINKED_H
#define CS240_LINKED_H

typedef struct list_node {
    int val;
    struct list_node *next;
} Node;


/*
 * Linked Integer Stack Implementation
 *
 *
 * */
typedef struct stack_list {
    Node *top;
} StackL;

StackL new_stackINode();

StackL *push_stackINode(StackL *st, int val);

StackL *pop_stackINode(StackL *st, int *val);

void print_stackINode(StackL st);
/*
 *
 * */

#endif //CS240_LINKED_H
