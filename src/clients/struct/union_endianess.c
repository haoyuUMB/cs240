#include <stdio.h>


void endianess_demo() {

    int i = 0x12345678;
    printf("%x\n", i);

    char *c = (char *) &i;
    for (int j = 0; j < 4; ++j) {
        printf("%x", c[j]);
    }
    printf("\n");
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

    typedef struct {
        unsigned char is_keyword: 1;
        unsigned int is_extern: 1;
        unsigned char is_static: 1;
    } Flags_c_int_char;

    printf("%ld\n", sizeof(Flags_b));
    printf("%ld\n", sizeof(Flags_b_char));
    printf("%ld\n", sizeof(Flags_c_int_char));

    Flags_b b = {1, 1, 1, 1};

    printf("%d\n", b.is_keyword);
    printf("%d\n", b.is_extern);

}

void padding_demo() {
    struct foo {
        char *p; // 8
        char c; // 1
        long x; // 8 bytes
    };
    printf("%ld bytes\n", sizeof(struct foo));
    printf("%ld bytes\n", sizeof(char *));
    printf("%ld bytes\n", sizeof(char));
    printf("%ld bytes\n", sizeof(long));

    struct foo1 {
        int i;
        char c; // 1
    };
    printf("%ld bytes\n", sizeof(struct foo1));

    struct foo1 foo_[10];
    struct foo1 *foo_1 = malloc(sizeof(struct foo1));


    struct __attribute__((__packed__)) foo_Pack {
        int *p; // 8
        char c; // 1
        long x; // 8 bytes
    };
    printf("%ld bytes\n", sizeof(struct foo_Pack));
}


int main(int argc, char *argv[]) {
//    endianess_demo();
//    bitfiled_eg();

    short a = 0x1234;
    char *cp = (char *) &a;

    printf("%x\n", *cp);

    if (*cp == 0x12) {
        printf("big endian");
    } else if (*cp == 0x34)
        printf("little endian");

    endianess_demo();
    // bit order within 1 byte is big endianess of bit order

    // reterpretation/ resegment of the same data
    union u1 {
        int i;
        char c;
    };

    printf("%ld bytes\n", sizeof(union u1));

    union u1 au1;
    au1.i = 0x12345678;
    printf("i: %x\n", au1.i);
    printf("c :%x\n", au1.c);


    return 0;
}