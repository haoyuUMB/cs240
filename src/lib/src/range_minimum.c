#include "cs240/range_minimum.h"
#include "stdlib.h"

int range_minimum_int(int *nums, int len) {
    if (len == 0) return -1;
    if (len == 1) return 0;
    int n = 1, a = 1, res = 0;
    for (; n < len; n++) {
        if (a << 1) break;
    }
    int dp[len][n];
    for (int i = 0; i < len; ++i) {
//        memset(dp[i], )
    }
    return res;
}