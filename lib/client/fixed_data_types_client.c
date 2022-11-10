//
// Created by haoyu on 11/9/22.
//

#include <stdio.h>
#include "fixed_data_types.h"
#include "comparator.h"

void test_fixed_queue() {
    int l = 10, *val;
    FIQueue q = new_FIQueue(l);
    FIQueue *p_q = &q;
    for (int i = 0; i < l; ++i) {
        enqueue_FIQueue(p_q, i);
    }
    print_IntArray(q.data, q.num);
    for (int i = 0; i < l; ++i) {
        dequeue_FIQueue(p_q, val);
        printf("%d\t", val);
    }
}

int main() {
    test_fixed_queue();
}