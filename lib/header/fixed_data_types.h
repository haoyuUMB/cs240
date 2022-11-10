//
// Created by haoyu on 11/8/22.
//

#ifndef CS240_FIXED_DATA_TYPES_H
#define CS240_FIXED_DATA_TYPES_H

typedef struct fix_int_stack {
    int *data, len, i;
} FIStack;

typedef struct fix_int_queue {
    int *data, len, top, end, num;
} FIQueue;

FIStack new_FIStack(int l);

// NULL means fail, st means succeed
FIStack *push_FIStack(FIStack *const st, int val);

FIStack *pop_FIStack(FIStack *const st, int *val);

FIQueue new_FIQueue(int l);

FIQueue *enqueue_FIQueue(FIQueue *const q, int val);

FIQueue *dequeue_FIQueue(FIQueue *const q, int *val);

void print_FIStack(FIStack *const st);

void print_FIQueue(FIQueue *const q);

#endif //CS240_FIXED_DATA_TYPES_H
