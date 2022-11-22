//
// Created by haoyu on 11/22/22.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

typedef enum color{ RED, GREEN, BLUE } Color;



void printColor(enum color chosenColor){
    const char *color_name = "Invalid color";
    switch (chosenColor){
        case RED:
            color_name = "RED";
            break;
        case GREEN:
            color_name = "GREEN";
            break;
        case BLUE:
            color_name = "BLUE";
            break;
    }
    printf("%s\n", color_name);
}

int main(int argc, char * argv[]){


    enum color  color1 = BLUE;

    printf("%d\n", color1);

    printColor(color1);

    // printColor(RED);
    // printColor(0);


    // Color red = RED;
    // putchar('0' + red);// what will be print out


    return 0;
}
