#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // first pointer exercise
    int a = 12;
    int *p;
    p = &a;
    *p = 15;
    printf("p pointer value: %d\n", *p);
    printf("a variable value: %d\n", a);
    return 0;
}