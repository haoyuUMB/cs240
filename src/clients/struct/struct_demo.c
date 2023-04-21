#include <stdio.h>


struct mix {
    int x, y;
    char c;
} mix1 = {1, 1, '1'};

typedef struct mix Mix;


int main(int argc, char *argv[]) {

    printf("mix1.x %d\n", mix1.x);
    mix1.x = 2;
    mix1.c = 'a';

    Mix mix2 = {2, 2, '2'};
    printf("mix1.x %d\n", mix1.x);

    struct mix mix3;
    mix3.c = 'c';


    return 0;
}