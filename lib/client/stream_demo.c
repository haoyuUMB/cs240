//
// Created by haoyu on 11/22/2022.
//

#include <bits/types/FILE.h>
#include <stdio.h>
#include <linux/limits.h>
#include <unistd.h>
#include "utils.h"

// blank character(tab, new line, space) seperated word
void getInts(FILE *file) {
    printf("Getting word as int\n");

    rewind(file);
    int n, res = 0;
    while (!feof(file)) {
        fscanf(file, "%d\n", &n);
        res += n;
    }
    printf("%d\n", res);
}

// blank character(tab, new line, space) seperated word
void getWords(FILE *file) {
    printf("Getting word as string\n");
    rewind(file);
    char ss[1000];
    while (!feof(file)) {
        fscanf(file, "%s\n", ss);
        printf("%s\n", ss);
    }
}

int main() {
    // some of the header files may be different on different platform
    // if so just re-include the head files
    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Current working dir: %s\n", cwd);
    } else {
        perror("getcwd() error");
        return 1;
    }
    char *file_name = "../../../data/ints.txt";
    char *file_name1 = "../../../data/ints1.txt";
    FILE *file = fopen(file_name, "r");
    FILE *file1 = fopen(file_name1, "w");
//    TEST_NULL() test if * file is created correctly
    printf("%c", fgetc(file));
    printf("-%d-", fgetc(file));
    fputc('a', file1);

//    printf("%c", fgetc(file));
//    getchar() <==> fgetc(stdin)

//    char ss[1000];
//    fscanf(file, "%s", ss);
//    printf("%s\n", ss);
//    fscanf(file, "%s", ss);
//    printf("%s\n", ss);
//    getWords(file);
    getInts(file);

}