/*
 * Create by Julian on 11/29/2022.
 *
 * Struct variable passing rules
 *
 * 1) If I make a copy of a structure with an array member, the copy structure's array
 *    member will have a distinct array with each element copied from the original.
 * 2) Dangerously, if we make a copy of a struct, and if a pointer is a member of the
 *    struct, we should be wary that only the pointers value will be copied, not the
 *    memory the pointer is pointing to.
 * 3) Primitive member's values will be copied.
 *
 * */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int len;    // length of string
    char *str;  // The word's definition
    char a[100];   // An array containing the word itself
} Word;

Word
deepCopy(Word word) { // Interestingly, the parameter "word" will be a shallow copy of the word passed as an argumen
    Word newWord = word;    // Will copy the primitive types, as well as the array elements correctly
    newWord.str = strdup(word.str); // Manually make newWord.str point to a COPY of the memory pointed to by word.str
}

int main() {

    Word word1; // Create a Word structure name word1
    word1.len = strlen("aqua");  // Set the member "len"
    word1.str = "A latin word for water";
    strncpy(word1.a, "aqua", strlen("aqua"));    // Set the member "a" to the word aqua



    Word word2 = word1; // Create a new struct

    // Check if the primitive member (int len) is the same for both copies
    if (word1.len == word2.len) {
        printf("The length (primitive member) was copied! \n");
    } else {
        printf("The length was not copied! \n");
    }

    // Prove that the arrays are at distinct locations on the stack, with elements having been copied
    if (word1.a == word2.a) {
        // Should never be true
        printf("Both arrays are constant pointers to the same memory (memory shared)! \n");
    } else {
        // Should always be true, array members do not behave like pointer members
        printf("Arrays members are at distinct locations on the stack! \n");


        // Our expectation is the primitive members should have been copied
        if (word1.len != word2.len) {
            printf("Primitives have not been coped, exiting");
            exit(1);
        }

        // Our expectation is that each of the elements in the array matched, because they would have been copied

        printf("\n");
        for (int i = 0; i < word1.len; i++) {
            if ((word1.a)[i] == (word2.a)[i]) {
                printf("%c ", (word1.a)[i]);
            } else {
                printf("The array members for each struct are not copied exactly");
                exit(1);
            }
        }
    }

    // If execution gets to this point, the array is copied EXACTLY and the two arrays are at distinct locations in memory

    printf("\nword2.a is a distinct array with all elements copied from word1.a \n");

    // Check how the pointers have been copied for each member
    if (word1.str == word2.str) {
        printf("The char* members of the copies both point to the same memory! \n");
    } else {
        printf("The char* members point to distinct memory! \n");
    }

    Word wordNew = deepCopy(word1); // wordNew will be a shallow copy of the deepCopy returned by deepCopy function

    if (word1.str != wordNew.str) {
        printf("Success! \n");
    } else {
        printf("Failure! \n");
    }
}
