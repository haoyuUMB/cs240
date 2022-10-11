
#include <utils.h>


int main() {
    print_utils();
    char *ptr[3];
    ptr[0] = malloc(sizeof(char) * 10);
    ptr[0] = "hello1";
    printf(ptr[0]);
    char **lineptr1;
    lineptr1 = malloc(sizeof(char *) * 3);
    lineptr1[0] = malloc(sizeof(char) * 10);
    lineptr1[0] = "hello";
    printf(lineptr1[0]);

    lineptr1 = ptr;
    printf(lineptr1[0]);
}