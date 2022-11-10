//
// Created by haoyu on 11/8/22.
//

#include <malloc.h>
#include "fixed_data_types.h"
#include "comparator.h"

FIStack new_FIStack(int l) {
    return (FIStack) {calloc(l, sizeof(int)), l, 0};
}

FIStack *push_FIStack(FIStack *const st, int val) {
    if (st->i == st->len) return NULL;
    st->data[st->i++] = val;
    return st;
}

FIStack *pop_FIStack(FIStack *const st, int *val) {
    if (st->i == 0) return NULL;
    *val = st->data[--st->i];
    return st;
}

// top is at the first item and end is at 1 after the last item
FIQueue new_FIQueue(int l) {
    return (FIQueue) {calloc(l, sizeof(int)), l, 0, 0, 0};
}

// enqueue from end
FIQueue *enqueue_FIQueue(FIQueue *const q, int val) {
    if (q->len == q->num) return NULL;
    q->data[q->end++] = val;
    q->num++;
    if (q->end == q->len) q->end = 0;
    return q;
}

FIQueue *dequeue_FIQueue(FIQueue *const q, int *val) {
    if (q->num == 0) return NULL;
    *val = q->data[q->top++];
    q->num--;
    if (q->top == q->len) q->top = 0;
    return q;
}

void print_FIQueue(FIQueue *const q) {
    printf("Queue top: %d\tend: %d\tnum: %d\n", q->top, q->end, q->num);
    if (q->top < q->end) {
        for (int i = q->top; i < q->end; i++)
            printf("%d\t", q->data[i]);
        printf("\n");
        return;
    }
    for (int i = q->top; i < q->len; i++)
        printf("%d\t", q->data[i]);
    for (int i = 0; i < q->end; i++)
        printf("%d\t", q->data[i]);
    printf("\n");
}

void print_FIStack(FIStack *const st) {
    print_IntArray(st->data, st->len);
}