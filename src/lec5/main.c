//
// Created by haoyu on 2/16/2023.
//

#include <stdio.h>


int len(char s[]) {
    int i = 0;
    while (s[i]) i++;
    return i;
}

void scanf_demo1() {
    int i, sum = 0;
    while (scanf("%d", &i) != EOF) sum += i;
    printf("%d\n", sum);

}

/**
 * Read in a text file, print out how many different length of word it uses
 * and the occurrences for each  length of word
 */
void statistics_text_file_word() {

}

void scanf_demo() {
    char s[1000];
    while (scanf("%s", s) != EOF)
        printf("%s\n", s);

}

void get_char_demo() {
    char c;
    while ((c = getchar()) != -1) {
        printf("%c", c);
    }
    printf("\n");
}

/**
 * Read in a text file from stdin, print out how many different character it uses
 * and the occurrences for each character that appears exclude the null character
 */
void statistics_text_file_char() {
    int c, count = 0, counts[200] = {}, res = 0; // have to initialize to all 0
    // ascii code has 128 character starting from 0
    // 0 is null character

    // ASCII code is used for index/key

    // so the c returned will be from 0-128
    while ((c = getchar()) != EOF) {
        counts[c] += 1; //
    }
    for (int i = 0; i < 200; ++i) {
        if (counts[i] != 0) {
            printf("char %c: appears %10d times\n", i, counts[i]);
            res++;
        }
    }
    printf("The total number of diff chars is: %d \n", res);
}


int main() {
//    get_char_demo();
//    scanf_demo();
//    scanf_demo1();
    statistics_text_file_char();
}