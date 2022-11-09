//
// Created by haoyu on 11/8/22.
//

#include <malloc.h>
#include "fixed_data_types.h"

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

FIQueue new_FIQueue(int l) {
    return (FIQueue) {calloc(l, sizeof(int)), l, 0, 0, 0};
}

FIQueue *enqueue_FIQueue(FIQueue *const q, int val) {
    if (q->len == q->num) return NULL;
    q->num++;
    if (++q->end == q->len) q->end = 0;
    q->data[q->end] = val;
    return q;
}

FIQueue *dequeue_FIQueue(FIQueue *const q, int *val) {
    if (q->num == 0) return NULL;
    q->num--;
    *val = q->data[q->top++];
    if (q->top == q->len) q->top = 0;
    return q;
}