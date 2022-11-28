#include <stdio.h>

struct student {
    char name[50];
    int age;
    struct student *self;
};

// function prototype
struct student getInformation();

int add(int i, int j) {
    return 1;
}


int main() {
    struct student s;
    printf("Name: %ld\n", sizeof(struct student));

    s = getInformation();
    printf("s:%p\ts.name:%p\t%s\n", &s, &s.name, s.name);
    printf("s.self:%p\ts.self.name:%p\t%s\n", s.self, s.self->name, s.self->name);
    add(1, 2);
    printf("s1:%p\ts1.name:%p\t%s\n", s.self, s.self->name, s.self->name);

    s.self->age = 123;
    printf("s1:%p\ts1.name:%p\t%s\n", s.self, s.self->name, s.self->name);

    printf("\nDisplaying information\n");
    printf("Name: %s", s.self->name);
    printf("\nRoll: %d", s.self->age);

    return 0;
}

struct student getInformation() {
    struct student s1;
    s1.self = &s1;

    printf("Enter name: ");
    scanf("%[^\n]%*c", s1.name);

    printf("Enter age: ");
    scanf("%d", &s1.age);

    printf("s1:%p\ts1.name:%p\t%s\n", &s1, &s1.name, s1.name);

    return s1;
}