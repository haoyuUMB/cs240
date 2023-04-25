//
// Created by haoyu on 4/20/2023.
//

#include "cs240/linked_list.h"
#include "cs240/utils.h"
#include "stdlib.h"

Node *new_node(const void *val, int size) {
    Node *nodeP = malloc(sizeof(Node));
    nodeP->size = size;
    nodeP->val = malloc(size);
    memcpy(nodeP->val, val, size);
    nodeP->next = NULL;
    return nodeP;
}

void free_node(Node *node) {
    free(node->val);
    free(node);
}

LinkedList new_linked_list() {
    return (LinkedList) {NULL, NULL};
}

void append_top(LinkedList *list, const void *val, int size) {
    Node *node = new_node(val, size);
    if (list->top == NULL) {
        list->top = node;
        list->end = node;
        return;
    }
    node->next = list->top;
    list->top = node;
}


void append_end(LinkedList *list, const void *val, int size) {
    Node *node = new_node(val, size);
    if (list->end == NULL) {
        list->top = node;
        list->end = node;
        return;
    }

    list->end->next = node;
    list->end = node;
}


void remove_top(LinkedList *list) {
    if (list->top == NULL) return;
    if (list->top == list->end) {
        free_node(list->top);
        list->top = list->end = NULL;
        return;
    }
    Node *top = list->top;
    list->top = list->top->next;
    free_node(top);
}


Node *dfs_r(Node *cur, Node *pre) {
    if (cur == NULL) return pre;
    Node *next = cur->next;
    cur->next = pre;
    return dfs_r(next, cur);
}


void reverse_ll(LinkedList *list) {
    list->end = list->top;
    list->top = dfs_r(list->top, NULL);
}

void reverse_ll_iterative(LinkedList *list) {
    list->end = list->top;
    Node *pre = NULL, *next = NULL;
    while (list->top) {
        next = list->top->next;
        list->top->next = pre;
        pre = list->top;
        list->top = next;
    }
    list->top = pre;
}

void print_int_linked_list(LinkedList list) {
    Node *root = list.top;
    while (root) {
        printf("%d ", INT(root->val));
        root = root->next;
    }
    printf("\t the end is: %d\n", INT(list.end->val));
}



