#include <stdio.h>
#include <stdlib.h>

int read_file();
void write_file();

int main(int argc, char **argv) {
    char FILENAME[]="Counter.txt";
    FILE *file = NULL;

    if((file=fopen(FILENAME, "w+"))==NULL) {
        printf("The file could't be created: ");
        return 0;
    }
    fprintf(file, "%d", 0);
    fseek(file, 0, SEEK_SET);
    int c = read_file(file);
    printf("The value is %d\n", c);
    write_file(file, 5);
    fclose(file);
    return 1;
}

int read_file(FILE *f) {
    int counter;
    fscanf(f, "%d", &counter);
    return counter;
}

void write_file(FILE *f, int c) {
    fprintf(f, ",%d", c);
}
