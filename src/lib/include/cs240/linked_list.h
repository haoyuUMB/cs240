//
// Created by haoyu on 4/20/2023.
//

#ifndef CS240_LINKED_LIST_H
#define CS240_LINKED_LIST_H

typedef struct node {
    void *val;
    struct node *next;
} Node;

typedef struct {
    Node *top, *end;
} LinkedList;

Node *new_node(const void *val, int size);

LinkedList new_linked_list();

void append_top(LinkedList *list, const void *val, int size);

void remove_top(LinkedList *list, const void *val, int size);

void append_end(LinkedList *list, const void *val, int size);

typedef LinkedList Stack;

void push(Stack *stack, const void *val, int size);

void pop(Stack *stack);

typedef LinkedList Queue;

void enqueue(Queue *queue, const void *val, int size);

void dequeue(Queue *queue);

void print_int_linked_list(LinkedList list);

#endif //CS240_LINKED_LIST_H
