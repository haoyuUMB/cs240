//
// Created by haoyu on 4/20/2023.
//

#include "cs240/linked_list.h"
#include "cs240/utils.h"
#include "stdlib.h"

Node *new_node(const void *val, int size) {
    Node *nodeP = malloc(sizeof(Node));
    *nodeP = (Node) {malloc(size), NULL};
    memcpy(nodeP->val, val, size);
    return nodeP;
}

LinkedList new_linked_list() {
    return (LinkedList) {NULL, NULL};
}

void append_top(LinkedList *list, const void *val, int size) {
    Node *node = new_node(val, size);
    node->next = list->top;
    list->top = node;
    if (list->end == NULL) list->end = node;
}


void print_int_linked_list(LinkedList list) {
    Node *root = list.top;
    while (root) {
        printf("%d ", INT(root->val));
        root = root->next;
    }
    printf("\n");
}



