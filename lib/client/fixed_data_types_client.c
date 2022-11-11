//
// Created by haoyu on 11/9/22.
//

#include <stdio.h>
#include <string.h>
#include "fixed_data_types.h"
#include "comparator.h"

void test_fixed_queue() {
    int l = 10, val;
    FIQueue q = new_FIQueue(l);
    FIQueue *p_q = &q;
    for (int i = 0; i < l; ++i) {
        enqueue_FIQueue(p_q, i);
    }
    print_IntArray(q.data, q.len);
    for (int i = 0; i < l; ++i) {
        dequeue_FIQueue(p_q, &val);
        printf("%d\t", val);
    }
    printf("\n");
}


void stack_demo() {
    char s1[] = "[()]{}{[()()]()}";
    char di[][2] = {
            {'{', '}'},
            {'[', ']'},
            {'(', ')'}
    };

    int val;
    FIStack st = new_FIStack(strlen(s1));
    FIStack *p_st = &st;

    printf("func push_FIStack: %p\n", push_FIStack);
    printf("func      st.push: %p\n", st.push);

    print_FIStack(p_st);
    for (int i = 0; s1[i]; i++) {
        for (int j = 0; j < 3; ++j) {
            if (di[j][0] == s1[i]) {
                st.push(p_st, (int) di[j][1]);
            }
        }
        for (int j = 0; j < 3; ++j) {
            if (di[j][1] == s1[i]) {
                if (st.i == 0 || st.data[st.i - 1] != s1[i]) {
                    printf("not valid\n");
                    return;
                }
                st.pop(p_st, &val);
            }
        }
    }
    printf("valid\n");

}

int main() {
    test_fixed_queue();
    stack_demo();
}