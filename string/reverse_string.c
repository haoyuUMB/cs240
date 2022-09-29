//
// Created by haoyu on 9/28/22.
//



#include <stdio.h>

int len(char *s) {
    int i = 0;
    while (s[i++]);
    return i - 1;
}

char *reverse_string(char *s) {
    int i = 0, j = 0;
    char c;
    while (s[j++]);
    j -= 2;
    while (i < j) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
        i++;
        j--;
    }
    return s;
}

void printf_int(int n) {
    char s[15];
    int i = 0, count = 1;
    for (; n; n /= 10, i++, count++) {
        s[i] = n % 10 + '0';
        if (count % 3 == 0) s[++i] = ',';
    }
    if (s[i - 1] == ',') i--;
    s[i] = 0;
    printf(reverse_string(s));
    printf("\n");
}

void printf_long(long n) {
    char s[20];
    sprintf(s, "%d", n);
    int i = 1, j = 0, l = len(s);
    int l1 = l + (l - 1) / 3;
    s[l1--] = s[l--];
    for (; l >= 0; l--, l1--, i++) {
        s[l1] = s[l];
        if (i % 3 == 0) s[--l1] = ',';
    }
    printf(s);
    printf("\n");


}

int main(int argc, char *argv[]) {
    char *s = "12345";
    printf(s);
//    char s[] = "12345";
//    reverse_string("hello");
    printf(reverse_string(s));
    printf("\n");
//    printf_long(1234567890l);
//    printf_int(123456789);
    return 0;
}