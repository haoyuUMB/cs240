#include <stdio.h>
#include "cs240/linked_list.h"
#include "cs240/utils.h"

int main(int argc, char *argv[]) {
    LinkedList list = new_linked_list();
    for (int i = 0; i < 10; ++i) {
        append_top(&list, &i, sizeof(i));
    }
    print_int_linked_list(list);
    return 0;
}