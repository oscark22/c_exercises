#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int vec[] = {1,2,3,4,5};
    int *p;
    p = vec;

    printf("The value of the vector in the first pos is: %d\n", *(p++));
    printf("The value of the vector is: %d\n", *p);
    printf("The value of p is: %p\n", p);

    return 0;
}