//
// Created by haoyu on 11/21/2022.
//

#include <stdint.h>
#include <math.h>
#include <stdio.h>


void bin_char(unsigned n, char s[],  int len) {

    unsigned i, j = 0;
    for (i = 1 << (len-1); i > 0; i = i / 2) {
        s[j++] = (n & i) ? '1' : '0';
    }
    s[j] = 0;
}

void print(char s[], int q) {
    printf("%2d-string: \n", q);
    for (int i = 0; i<q; i++) {
        if (!((i) % 4) && i != 0) printf(",");
        if (!((i) % 8) && i != 0) printf(" || ");
        printf("%c", s[i]);
    }
    printf("\n");
}


typedef struct {
    char *p;  /* 8 bytes */
    char c;   /* 1 byte */ // here the c ompiler padded extra 7 bytes
    long x;   /* 8 bytes */
} Foo;


typedef struct __attribute__((__packed__)) {
    char *p;    /* 8 bytes */
    char c;        /* 1 byte */
    long x;        /* 8 bytes */
} Foo1;

typedef struct {
    int i;  //4
    short j; //2  2 padded
    int k;  // 4
} Foo2;

typedef struct {
    int i; //4
    short j;  // 2 2 padded
    long k; // 8
} Foo3;


void testEndianess() {


    int i = 0x12345678; // i takes 4 bytes

    // 0111 1000  0101 0110 0011 0100 0001 0010  little
    // 	  7    8     5    6    3    4    1    2

    // 0001 0010  0011 0100 0101 0110 0111 1000  big
    //0x//    1    2     3    4	   5    6    7    8

    printf("\nHex-String:%x\n", i);
    char si[32];
    char *nums = &i;
    bin_char(i, si, 32);
    print(si, 32);
    for (int j = 0; j < 4; ++j) {
        printf("%x\t", nums[j]);
    }
    for (int j = 0; j < 4; ++j) {
        bin_char(nums[j], si, 8) ;
        print(si, 8);
    }
    printf("\n");









// unsigned char <==> uint8_t
    uint8_t *p = (uint8_t *) &i;

    for (int i = 0; i < 4; ++i) {
        printf("%x\t", p[i]);
    }


    int j = 1;

    // 0000 0001  0000 0000 0000 0000 0000 0000  little
    // 0000 0000  0000 0000 0000 0000 0000 0001  big

    uint8_t *p1 = (uint8_t *) &j;
    if (*p1 == 1)
        printf("little endianess\n");
    else
        printf("big endianess\n");


}


void union_eg() {
    union u_tag {
        int i;
        char s;
    } u = {0x12345678};
    //little endianesss on my machine
    //so s will be least sinificant byte if i

    // printf("%x\n", u.i);
    // printf("%x\n", u.s);
    // printf("%x\n", *(&u.s+1));
    // printf("%x\n", *(&u.s+2));
    // printf("%x\n", *(&u.s+3));



    typedef union {

        unsigned ip;


        struct {
            uint8_t fourth, third, second, first;
        };
    } IP;

// 127.0.0.1  (0x)(FF, 00,00 01)
    IP ip = {0xFF000001};
    // 0111 1000  0101 0110 0011 0100 0001 0010  little
    // 	  7    8     5    6    3    4    1    2
    //    fourth  	  third

    printf("%x\n", ip.fourth);
    printf("%x\n", ip.first);


    ip.fourth = 0x78;
    ip.third = 0x56;
    ip.second = 0x34;
    ip.first = 0x12;

    printf("%x\n", ip.ip);

    printf("%ld\n", sizeof(IP));


}


void bitfiled_eg() {

// char
// 0 0 0 0 0 	0   			0  			    0
//	            is_static	 	is_extern		is_keyword

    typedef struct {
        unsigned char is_keyword: 1;
        unsigned char is_extern: 1;
        unsigned char is_static: 1;
        unsigned char is_global: 1;
    } Flags_b;


    typedef struct {
        unsigned int is_keyword: 1;
        unsigned int is_extern: 1;
        unsigned int is_static: 1;
    } Flags_b_char;


    printf("%ld\n", sizeof(Flags_b));
    printf("%ld\n", sizeof(Flags_b_char));

    Flags_b b = {1, 1, 1, 1};

    printf("%d\n", b.is_keyword);
    printf("%d\n", b.is_extern);

    unsigned char *pb = (unsigned char *) &b;

    printf("*pb%d\n", *pb);


}


void bitfiled_eg1() {

// char
// 0 0 0 0  	0   			0  			     00
//	            is_static	 	is_extern		is_keyword

    typedef struct {
        unsigned char is_keyword: 2;  // 0-3 (00,01,10,11)
        unsigned char is_extern: 1;
        unsigned char is_static: 1;
    } Flags_b;


    printf("bitfilds sizeof:%ld\n", sizeof(Flags_b));

    Flags_b b = {2, 1, 1};

    printf("%d\n", b.is_keyword);
    printf("%d\n", b.is_extern);

    unsigned char *pb = (unsigned char *) &b;

    printf("*pb%d\n", *pb);


    typedef struct {
        unsigned char is_keyword;  // 0-3 (00,01,10,11)
        unsigned char is_extern;
        unsigned char is_static;
    } Flags;

    printf("Without bitfilds:%ld\n", sizeof(Flags));

}


/*
 floating pointer number: sign_bit exponet_bits mantisa_bits

0 00000000 00000000000000000000001 2^-149

0 00000001 00000000000000000000000 2^-126

0 01111111 00000000000000000000000 1

0 00000000 00000000000000000000000 0

1 10000000 00000000000000000000000 -2

*
*/

void bitfiled_eg2() {

    typedef union {
        float f;
        struct {
            unsigned int mantisa_bits: 23;
            unsigned int exponet_bits: 8;
            unsigned int sign_bit: 1;
        };


    } Float;


    // Float f = {1.0};
    Float f;
    f.f = pow(2, -126) * (-1);

    printf("exponet_bits:\t %d\n", f.exponet_bits);
    printf("sign_bit:\t%d\n", f.sign_bit);
    printf("f.mantisa_bits\t%d\n", f.mantisa_bits);


    typedef union {
        unsigned char val;
        struct {
            unsigned char a: 1;  // 0-3 (00,01,10,11)
            unsigned char b: 1;

            unsigned char c: 1;  // 0-3 (00,01,10,11)
            unsigned char d: 1;
            unsigned char e: 1;
            unsigned char f: 1;  // 0-3 (00,01,10,11)
            unsigned char g: 1;
            unsigned char h: 1;
            // unsigned char i : 1;
        };
    } Flags_b;


    Flags_b b = {3};

    printf("val:%d\n %d\t%d\t%d\t%d\t", b.val, b.d, b.c, b.b, b.a);

    // &b.a;
    // printf("%ld\n", sizeof(b.a));

}


int main () {

     printf("Foo: %ld\n", sizeof(Foo));
     printf("Foo1: %ld\n", sizeof(Foo1));
     printf("foo2 %ld\n", sizeof(Foo2));
     printf("Foo3 %ld\n", sizeof(Foo3));

     testEndianess();
    // union_eg();

//    bitfiled_eg2();


}