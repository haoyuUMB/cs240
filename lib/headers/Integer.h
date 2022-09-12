//
// Created by haoyu on 9/2/2022.
//

#ifndef HI_INTEGER_H
#define HI_INTEGER_H
typedef struct IntegerStruct {int *val;} Integer;

Integer new_integer();
Integer new_integer_val(int val);
void free_integer(Integer a);

Integer set_integer(Integer a, int val);
int get_integer_val(Integer a);

int integer_comparator(Integer a, Integer b);

// should not creat pointer that will hard to free
// if we create string within this function then
// we will have to remember to free it
char* integer_to_string(Integer a, char *s);

void print_integer(Integer a);

#endif //HI_INTEGER_H

