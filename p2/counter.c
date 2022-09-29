#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define FILENAME "s.txt"
#define NUMBER_THREADS 8
#define NUMBER_OF_REQUESTS 100

int read_file(FILE*);
int write_file(FILE*, int);
void *counter(void*);

FILE *file = NULL;
pthread_mutex_t mutex;

int main(int argc, char **argv) {
    pthread_t threads[NUMBER_THREADS];
    write_file(file, 0);

    pthread_mutex_init(&mutex, 0);

    //Init threads
    for (int i=0; i<NUMBER_THREADS; i++) {
        pthread_create(&threads[i], NULL, counter, (void*) i);
    }

    for (int i=0; i<NUMBER_THREADS; i++) {
        pthread_join(&threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    return 0;
}

void *counter(void *id) {
    int c;
    for (int i=0; i<NUMBER_OF_REQUESTS; i++) {
        pthread_mutex_lock(&mutex);
        c = read_file(file);
        write_file(file, (c+1));
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(0);
}

int read_file(FILE *file) {
    if((file=fopen(FILENAME, "r"))==NULL) {
        printf("The file could't be readed:\n");
        return -1;
    }
    int counter = fscanf(file, "%d", &counter);
    fclose(file);
    return counter;
}

int write_file(FILE *file, int c) {
    if((file=fopen(FILENAME, "w"))==NULL) {
        printf("The file could't be written:\n");
        return 0;
    }
    fprintf(file, "%d", c);
    fclose(file);
    return 1;
}
