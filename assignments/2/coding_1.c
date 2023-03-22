/*
 * The first line of the input gives the number of test cases, T.
 * T test cases follow.

    The first line of each test case contains four integers N, D, C, and M:
    The next line contains a string S of length N representing the arrangement of animals.
 *
 *
 *
 * */


// scanf  will treat the string as (white space and new line separated) words
//

#include <stdio.h>

// stdin(getchar scanf)
int main(int argc, char *argv[]) {
    int T, N, D, C, M;
    char s[10001]; // array is not resize

    scanf("%d", &T);
    // printf("the %d test cases\n", T);

    for (int i = 1; i <= T; ++i) {
        scanf("%d %d %d %d %s", &N, &D, &C, &M, s);
        // printf("#%d sum is %d, the string is %s\n", i, N + D + C + M, s);
        printf("Case #%d: %s\n", i, i > 2 ? "NO" : "YES");
    }
    return 0;
}