//
// Created by haoyu on 11/5/22.
//

#ifndef CS240_LIST_H
#define CS240_LIST_H

typedef struct list_node {
    int val;
    struct list_node *next;
} LNode;

typedef struct stack_list {
    LNode *top;
} StackL;

StackL push_stackl(StackL *st, int val);

#endif //CS240_LIST_H
