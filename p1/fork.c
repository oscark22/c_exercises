#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


int main(int argc, char **argv) {
    pid_t pid = fork();
    if (pid == 0) {
        printf("Soy Luke\n");
    } else {
        printf("Soy Darth Vader\n");
        printf("Como Vader, el process id de Luke es: %d\n", pid);
    }
}