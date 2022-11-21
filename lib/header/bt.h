//
// Created by haoyu on 11/18/2022.
//

#ifndef CS240_BT_H
#define CS240_BT_H

typedef void *P_void;

typedef struct binary_node {
    int type;
    P_void val;
    struct binary_tree *left, *right;
} BNode;

typedef BNode *P_BNode;


typedef struct binary_tree {
    BNode *root;
} BTree;

P_BNode new_BNode(int type, P_void const val, P_BNode left, P_BNode right);

P_BNode new_int_BNode(int val, P_BNode left, P_BNode right);

void print_int_P_BNode(P_BNode root);

#endif //CS240_BT_H
