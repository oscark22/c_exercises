#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char** argv) {
  printf("I am %d\n", getpid();
  pid_t pid = fork();
  printf("fork returned: %d\n", pid);
  if (pid < 0) {
    perror("Error, process can't be created:\n");
  }
  else if (pid == 0) {
    printf("Process created. I am the child with paid %d\n", getpid());
    exit(0);
  }
  printf("I am the parent with process id: %d\n", getpid());
  wait(NULL);
  return 0;
}
