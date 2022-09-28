#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUMBER_OF_THREADS 8
#define MATRIX_SIZE 16
#define ROWS MATRIX_SIZE/NUMBER_OF_THREADS


void fill_matrixes();
void *sum_matrixes(void*);
void print_matrix();

// definition of matrixes.
int M1[MATRIX_SIZE][MATRIX_SIZE];
int M2[MATRIX_SIZE][MATRIX_SIZE];
int M3[MATRIX_SIZE][MATRIX_SIZE];

int main(int argc, char **argv) {
    fill_matrixes();

    // init threads arr.
    pthread_t threads[NUMBER_OF_THREADS];

    // create threads and call function.
    int num;
    for (int i=0; i<NUMBER_OF_THREADS; i++) {
        num = pthread_create(&threads[i], NULL, sum_matrixes, (void*) i);
    }

    // wait for threads to finish.
    for (int i=0; i<NUMBER_OF_THREADS; i++) {
        pthread_join(&threads[i], NULL);
    }

    print_matrix();
}

void fill_matrixes() {
    for (int r=0; r<MATRIX_SIZE; r++) {
        for (int c=0; c<MATRIX_SIZE; c++) {
            M1[r][c] = rand()%10;
            M2[r][c] = rand()%10;
        }
    }
}

void *sum_matrixes(void *id) {
    int num_thread = (int) id;
    for (int r=ROWS*num_thread; r<ROWS*(num_thread+1); r++) {
        for(int c=0; c<MATRIX_SIZE; c++) {
            M3[r][c] = M1[r][c] + M2[r][c];
        }
    }
    pthread_exit(0);
}

void print_matrix() {
    for (int r=0; r<MATRIX_SIZE; r++) {
        for (int c=0; c<MATRIX_SIZE; c++) {
            printf("%5d", M3[r][c]);
        }
        printf("\n");
    }
}