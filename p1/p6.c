#include <stdio.h>

void f1(int n) {
    n = 10;
    printf("The number inside the function is: %d\n", n);
}

void f2(int *n) {
    *n = 10;
}

void f3(int *vec) {
    vec[0] = 10;
}

int main(int argc, char** argv) {
    int n = 20;
    int vec[] = {1,2,3,4,5};

    printf("The memory adress of n is: %p\n", &n);
    printf("The number before the function call is: %d\n", n);
    f2(&n);
    printf("The number before the function call is: %d\n", n);
    
    printf("The number before the function call (vector) is: %d\n", vec[0]);
    f3(vec);
    printf("The number before the function call (vector) is: %d\n", vec[0]);

    return 0;
}