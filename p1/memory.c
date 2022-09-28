#include <stdlib.h>
#include <stdio.h>


struct SO {
    int NH;
    int NC;
    char *NP;
}

int main(void) {
    int i,n=10;
    int *vec = (int*) malloc(sizeof(int)*n);

    for(i=0; i<n; i++) {
        vec[i] = i;
    }
    free(vec);

    int **mat = (int**) malloc(sizeof(int*)*n);
    for (i=0; i<n; i++) {
        mat[i] = (int*) malloc(sizeof(int)*n);
    }

    for(i=0; i<n; i++) {
        free(mat[i]);
    }

    struct SO *LS = (struc SO*) malloc(sizeof(struct SO)*n);
    free(LS);
}
