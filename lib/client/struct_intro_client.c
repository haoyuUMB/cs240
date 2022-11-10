//
// Created by haoyu on 11/10/2022.
//

typedef struct point2D {
    int x, y;
} Point2D;

void print_point2d(Point2D p) {
    printf("Point, x:%d\ty:%d\n", p.x, p.y);
}

int main() {
    Point2D p1 = {1, 2},
            *p2 = calloc(1, sizeof(Point2D));
    *p2 = (Point2D) {3, 1};
    print_point2d(p1);
    print_point2d(*p2);
}