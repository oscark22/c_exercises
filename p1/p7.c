#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MATRIX_SIZE 3200
#define NUMBER_OF_THREADS 8


void print_matrix(int size, int matrix[size][size]);
void *multiply_matrix(void*);

// global variables
int M1[MATRIX_SIZE][MATRIX_SIZE];
int M2[MATRIX_SIZE][MATRIX_SIZE];
int M3[MATRIX_SIZE][MATRIX_SIZE];

int THREAD_STEPING = MATRIX_SIZE/NUMBER_OF_THREADS;

int main(int argc, char **argv) {
    pthread_t threads[NUMBER_OF_THREADS];

    // init values in matrix
    for (int r=0; r<MATRIX_SIZE; r++) {
        for (int c=0; c<MATRIX_SIZE; c++) {
            if (r == c) {
                M1[r][c] = 1;
                M2[r][c] = 1;
            } else {
                M1[r][c] = 0;
                M2[r][c] = 0;
            }
        }
    }

    // init threads
    int curr = 0;

    for (int i=0; i<NUMBER_OF_THREADS; i++) {
        pthread_create(&threads[i], NULL, multiply_matrix, (void*) curr);
        curr += THREAD_STEPING;
    }

    //print_matrix(MATRIX_SIZE, M3);
    return 0;
}

void print_matrix(int size, int matrix[size][size]) {
    for (int r=0; r<size; r++) {
        for (int c=0; c<size; c++) {
            printf("%5d", matrix[r][c]);
        }
        printf("\n");
    }
}

void *multiply_matrix(void *curr_i) {
    for (int i=curr_i; i<curr_i+THREAD_STEPING; i++) {
        for (int r=0; r<MATRIX_SIZE; r++) {
            int curr = 0;
            for (int c=0; c<MATRIX_SIZE; c++) {
                curr += M1[i][c] * M2[r][c];
            }
            M3[i][r] = curr;
        }
    }
    pthread_exit(NULL);
}
