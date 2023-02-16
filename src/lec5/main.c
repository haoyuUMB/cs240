//
// Created by haoyu on 2/16/2023.
//

#include <stdio.h>

int len(char s[]) {
    int i = 0;
    while (s[i]) i++;
    return i;
}

void scanf_demo() {
    char s[1000];
    int l = 0;
    do {
        l = scanf("%s", s);
        printf("%d: %s\n", l, s);
    } while (l != -1);
}

void get_char_demo() {
    char c;
    while (c = getchar() != -1) {
        printf("%c", c);
    }
    printf("\n");
}

int main() {
//    get_char_demo();
    scanf_demo();
}