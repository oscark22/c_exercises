#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define NUMBER_OF_THREADS 8

void* print_hello_world(void* tid) {
  printf("Hello world. Greetings from thread %p\n", tid);
  pthread_exit(NULL);
}

int main(int argc, char** argv) {
  pthread_t threads[NUMBER_OF_THREADS];

  int s;
  for (int i=0; i<NUMBER_OF_THREADS; i++) {
    s = pthread_create(&threads[i], NULL, print_hello_world, (int*) i);
    if (s != 0) {
      printf("Thread can't be created :(\n");
    }
  }
  
  return 0;
}
