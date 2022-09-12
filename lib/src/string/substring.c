//
// Created by haoyu on 9/11/2022.
//

#include "headers/substring.h"

/**
 *
 * @param s
 * @return
 */
int lengthOfLongestSubstring(char * s){
    int di[128], res = 0, i = 0, j = 0;
    for (int i=0; i < 128; i++) di[i] = -1;

    for ( j=0; s[j]; j++){
        if (di[s[j]] >= i ){
            res = res > j - i ? res : j - i;
            i = di[s[j]] + 1;
        }
        di[s[j]] = j;
    }
    return res > j -i ?  res : j - i;
}