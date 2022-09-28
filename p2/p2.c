#include <stdio.h>
#include <pthread.h>

#define MAX 100

pthread_mutex_t mutex;
pthread_cond_t condc, condp;
int buffer = 100;

void *producer(void *p) {
    while (1) {
        pthread_mutex_lock(&mutex);
        if(buffer == 100) pthread_cond_wait(&condp, &mutex);
        buffer += 1;
        printf("%d\n", buffer);
        if(buffer == 1) pthread_cond_signal(&condc);
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(0);
}

void *consumer(void *p) {
    while (1) {
        pthread_mutex_lock(&mutex);
        if(buffer == 0) pthread_cond_wait(&condc, &mutex);
        buffer -= 1;
        printf("%d\n", buffer);
        if(buffer == 99) pthread_cond_signal(&condp);
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(0);
}

int main(int argc, char **argv) {
    pthread_t pro, cons;
    pthread_mutex_init(&mutex, 0);
    pthread_cond_init(&condc, 0);
    pthread_cond_init(&condp, 0);
    pthread_create(&cons, NULL, consumer, 0);
    pthread_create(&pro, NULL, producer, 0);
    pthread_join(cons, NULL);
    pthread_join(pro, NULL);
    pthread_cond_destroy(&cons);
    pthread_cond_destroy(&pro);
    pthread_mutex_destroy(&mutex);
    return 0;
}
