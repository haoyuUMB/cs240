//
// Created by haoyu on 11/18/2022.
//

#include <malloc.h>
#include <string.h>
#include "bt.h"

P_BNode new_BNode(int type, P_void const val, P_BNode left, P_BNode right) {
    P_BNode node = malloc(sizeof(BNode));
    *node = (BNode) {type, malloc(type), left, right};
    memcpy(node->val, val, type);
    return node;
}

P_BNode new_int_BNode(int val, P_BNode left, P_BNode right) {
    return new_BNode(sizeof(int), &val, left, right);
}

void print_int_P_BNode(P_BNode root) {
    printf("Current int node val: %d\tleft: %p\tright: %p\n",
           *(int *) root->val, root->left, root->right);
}