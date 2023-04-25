#include <stdio.h>
#include <stdlib.h>

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

    struct mix *p_mix3 = &mix3;
    (*p_mix3).x = 3;
    printf("mix3->x %d\n", p_mix3->x);

    //
    Mix *mix4 = (Mix *) malloc(sizeof(Mix));
    mix4->x = 4;

    *mix4 = (Mix) {1, 2, 'x'};
    printf("mix4->x %d\n", mix4->x);
    printf("mix4->y %d\n", mix4->y);
    printf("mix4->c %c\n", mix4->c);


    Mix mixes[3] = {
            {1, 2, 'x'},
            {3, 4, 'y'},
            {5, 6, 'z'},
    };

    printf("mix4->x %c\t%p\n", mixes[0].c, &mixes[0].c);
    printf("mix4->x %c\t%p\n", mixes[1].c, &mixes[1].c);
    printf("mix4->x %c\n", mixes[1].c);
    printf("mix4->x %c\n", mixes[2].c);


    typedef struct {
        int *nums, size;
    } Array;


    Array *arr = malloc(sizeof(Array));
    arr->size = 10;
    arr->nums = malloc(sizeof(int) * arr->size);


    return 0;
}