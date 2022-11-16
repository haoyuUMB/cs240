//
// Created by haoyu on 11/10/2022.
//

#include <stdio.h>
#include <malloc.h>

struct point2D {
    int x, y;
};

typedef struct point2D Point2D;

/*
 *
 *  typedef struct point2D {
            int x, y;
    } Point2D;
 *
 *
 *
 * */

void print_point2d(Point2D p) {
    printf("Point, x:%d\ty:%d\n", p.x, p.y);
}

Point2D new_Point2D(int x, int y) {
    return (Point2D) {x, y};
}

Point2D *new_Point2D_p(int x, int y) {
    Point2D *p = calloc(1, sizeof(Point2D)); // don't use sizeof all it's members add together
    p->x = x;
    p->y = y;
    return p;
}


int main() {
    struct point2D p0 = {10, -10};
    Point2D p00 = {-10, 10};

    print_point2d(p0);
    print_point2d(p00);

    printf("The type of our Point2D type: %ld\n", sizeof(Point2D));

    Point2D p1 = {1, 2},
            *p2 = calloc(1, sizeof(Point2D)),
            *p3;
    *p2 = (Point2D) {3, 1}; // Explicit type casting the curly braces data members
    (*p2).x = 3;
    (*p2).y = 1;
    p2->x = -1;
    p2->y = -2;
    print_point2d(p1);
    print_point2d(*p2);

    p2 == p3;

    Point2D p_new1 = new_Point2D(1, 2); // the values of the member of Point2D gets returned and copied
    Point2D *p_new2 = new_Point2D_p(1, 2); // the address of the locally created heap memory Point2D

    Point2D arr[2] = {
            {1, 1},
            {2, 2}
    };

    print_point2d(arr[0]);
    print_point2d(arr[1]);
}