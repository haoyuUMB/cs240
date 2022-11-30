//
// Created by 25jul on 11/29/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int len;  // length of string
    char* str; // The word's definition
    char a[100];  // An array containing the word itself
}  Word;

Word deepCopy(Word word){ // Interestingly, the parameter "word" will be a shallow copy of the word passed as an argumen
    Word newWord = word;  // Will copy the primitive types, as well as the array elements correctly
    newWord.str = strdup(word.str); // Manually make newWord.str point to a COPY of the memory pointed to by word.str
    return newWord;
}

int main(){

    printf("\n\n------Shallow Copy Testing------\n\n");

    Word Word1;

    Word1.len = strlen("hello");

// allocate memory for char * member

    Word1.str = (char *) malloc((strlen("a greeting")));

    strcpy(Word1.str, "a greeting");

    strcpy(Word1.a, "hello");


    // Iterate through each element in Word1.a, and print t
    // Should be "hello"
    for(int i = 0; i < Word1.len; i++){
        printf("-");
        printf("%c", Word1.a[i]);
    }

    printf("\n");

    // Word1.str points to some heap memory, iterate through
    // this heap memory and print each character (should be "a greeting")
    for(int i = 0; i < strlen("a greeting"); i++){
        printf("%c-", Word1.str[i]);
    }

    Word word2 = Word1;

    // Check if primitive members copied (should be true)

    printf("\n");

    if(Word1.len == word2.len){
        printf("\nThe primitive members copied\n");
    }

    // Verify that each array is at distinct location in the stack
    if(Word1.a == word2.a){
        printf("Error");
    }

    printf("\n");

    // Verify that each element in array member is copied

    printf("Verify that original struct's array member's elements have been copied\n");
    for(int i = 0; i < strlen("hello"); i++){

        printf("%c, %c\n", Word1.a[i], word2.a[i]);

        if(Word1.a[i] != word2.a[i]){
            printf("Elements not copied, error");
        }
    }

    // Did the pointer's value get copied? Should be "yes"
    if(Word1.str == word2.str){
        printf("Pointer members of each respective copy are pointing to the same location in memory (shared)\n");
    }



    printf("\n\n------Deep copy testing------\n\n");

    // Make a deep copy
    Word deepCopyWord1 = deepCopy(Word1);

    // Verify the primitive member has been copied
    if(Word1.len == deepCopyWord1.len){
        printf("Primitive member copied \n");
    }
    else{
        printf("Primitive member not copied! Error!\n");
    }

    // Iterate through each copies respective array and verify elements have been copied
    printf("Verify that the original's array member's elements have been copied\n");
    for(int i = 0; i < strlen("hello"); i++){

        printf("%c, %c\n", Word1.a[i], deepCopyWord1.a[i]);

        if(Word1.a[i] != deepCopyWord1.a[i]){
            // printf("%c, %c \n", Word1.a[i], deepCopyWord1.a[i]);
            printf("Elements not copied, error\n");
        }
    }

    // Make sure pointers point to distinct locations in the heap (memory has been copied)
    printf("\n");
    printf("Proof that the deep copy's pointer member points to a distinct location in memory: \n");
    printf("word1.str = %lu and deepCopyWord1.str = %lu\n", Word1.str, deepCopyWord1.str);
    printf("Note they are different locations (copied memory at each distinct location)\n");
    printf("\n");
    printf("Let us examine if data has been copied exactly to a distinct location \n");
    for(int i = 0; i < strlen("a greeting"); i++){
        printf("%c, %c \n", Word1.str[i], deepCopyWord1.str[i]);
    }










}