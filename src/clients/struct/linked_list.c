#include <stdio.h>
#include "cs240/linked_list.h"
#include "cs240/utils.h"

void demo1() {
    LinkedList list = new_linked_list();
    for (int i = 0; i < 10; ++i) {
        append_top(&list, &i, sizeof(i));
    }
    print_int_linked_list(list);

    reverse_ll(&list);
    print_int_linked_list(list);

    reverse_ll_iterative(&list);
    print_int_linked_list(list);
}

int main(int argc, char *argv[]) {
    int a = 10;
    Node *intNode = new_node(&a, sizeof(a));
    printf("int Node val %d\n", *(int *) intNode->val);

    float f = 3.14f;
    Node *floatNode = new_node(&f, sizeof(f));
    printf("int Node val %f\n", *(float *) floatNode->val);
#define FLOAT(p) *(float *) p

    printf("int Node val %f\n", FLOAT(floatNode->val));

    LinkedList intList = new_linked_list();

    for (int i = 0; i < 10; ++i) {
        append_top(&intList, &i, sizeof(i));
    }
    print_int_linked_list(intList);

    LinkedList intList1 = new_linked_list();

    for (int i = 0; i < 10; ++i) {
        append_end(&intList1, &i, sizeof(i));
    }
    print_int_linked_list(intList1);
    remove_top(&intList1);
    print_int_linked_list(intList1);


    return 0;
}