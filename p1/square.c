#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#define NUMBER_OF_THREADS 8


void print_squares_cubes();
void *populate(void *id);

int squares[NUMBER_OF_THREADS];
int cubes[NUMBER_OF_THREADS];

int main(int argc, char **argv) {
    pthread_t threads[NUMBER_OF_THREADS];

    // create threads.
    for (int i=0; i<NUMBER_OF_THREADS; i++) {
        pthread_create(&threads[i], NULL, populate, (void*) i);
    }

    // wait till finish.
    for (int i=0; i<NUMBER_OF_THREADS; i++) {
        pthread_join(&threads[i], NULL);
    }

    print_squares_cubes();
    return 0;
}

void print_squares_cubes() {
    for (int i=0; i<NUMBER_OF_THREADS; i++) {
        if (i % 2) {
            printf("Soy el thread %d y el cuadrado es %d\n", i, squares[i]);
        } else {
            printf("Soy el thread %d y el cubo es %d\n", i, cubes[i]);
        }
    }
}

void *populate(void *id) {
    int i = (int) id;
    squares[i] = i*i;
    cubes[i] = i*i*i;
    pthread_exit(0);
}