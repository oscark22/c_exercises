#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void print(int**);

int main(int argc, char **argv) {
    int **mat = (int**) malloc(sizeof(int*)*10);

    for (int i=0; i<10; i++) {
        mat[i] = (int*) malloc(sizeof(int)*10);
    }

    // insert values
    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            mat[i][j] = i+j;
        } 
    }

    for (int i=0; i<10; i++) {
        free(mat[i]);
    }

    return 0;
}

void print(int **mat) {
    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            printf("5d\n", mat[i][j]);
        }
        printf();
    }
}