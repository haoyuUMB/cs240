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
    while (scanf("%d", &i) != -1) sum += i;
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
    while (scanf("%s", s) != -1)
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
 * Read in a text file, print out how many different character it uses
 * and the occurrences for each character that appears
 */
void statistics_text_file_char() {

}


int main() {
//    get_char_demo();
//    scanf_demo();
    scanf_demo1();
}