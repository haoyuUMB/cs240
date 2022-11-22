//
// Created by haoyu on 11/18/2022.
//

#include <stddef.h>
#include "bt.h"

void int_BNode_demo() {
    int val = 10;
    print_int_P_BNode(new_int_BNode(val, NULL, NULL));
}

int main() {
    int_BNode_demo();
}