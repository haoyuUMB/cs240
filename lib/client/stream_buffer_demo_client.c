//
// Created by haoyu on 11/22/22.
//
/*
* Author : Haoyu Wang
* Description:


  int setvbuf(FILE *stream, char *buf, int mode, size_t size)

*  1. _IOFBF(0)  full buffering  (being full cause action)
   2. _IOLBF(1)  line buffering of text files, (a new line character cause action)
   3. _IONBF(2)  no buffering  (every character cause action)
*

   4. If buf is not NULL,it will be used as the buffer;
      otherwise a buffer will be allocated.

   5. size determines the buffer size.

   6. setvbuf returns non-zero for any error




*/
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void test_FullBuffering(void);
void test_LineBuffering(void);
void test_NoBuffering(void);



int main(int argc, char *argv[])
{
    // test_FullBuffering();
    // test_LineBuffering();
    test_NoBuffering();

    fflush(stdout);
    sleep(3);
    printf("Program exits\n");
    return 0;
}


void test_FullBuffering(void){

    int buf_size = 1024;
    char buf[buf_size];
    memset(buf, '\0', buf_size);

    setvbuf(stdout, buf, _IOFBF, buf_size);


//the printf will flush the buffer to stdout
// fprintf(stdout,"asd");

    printf("To be flushed\n");
    printf("To be flushed\n");
    printf("To be flushed\n");
    printf("To be flushed\n");
    fprintf(stdout, "%s\n", "To be flushed\n" );

    fflush(stdout);
    printf("After flushing. Waiting on exit of process\n");
    sleep(4);
    fflush(stdout);
    printf("Testing exits\n");
}



void test_LineBuffering(void){

    int buf_size = 1024;
    char buf[buf_size];
    memset(buf, 0, buf_size);

    setvbuf(stdout, buf, _IOLBF, buf_size);

    printf("String with new Line Char\n");

    printf("String with no new line");
    printf("again");
    sleep(3);
}


void test_NoBuffering(void){

    int buf_size = 1024;
    char buf[buf_size];
    memset(buf, 0, buf_size);

    setvbuf(stdout, buf, _IONBF, buf_size);

    printf("aklsdjf\n");

    printf("Just print out every thing immedately");

    printf("String with no new line");
    printf("again");
    sleep(3);
}
